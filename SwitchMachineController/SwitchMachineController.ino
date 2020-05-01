#include <StateMachine.h>
#include <SwitchMachine.h>
#include <Triad.h>
#include <RingBuffer.h>

#include "I2CSlave.h"
#include "Timeout.h"

const byte I2C_ADDR = 0x30;    // I2C address

// Pin assignments are specific to Adafruit Pro Trinket.
// All triads are consecutive pins.
// The pins should be connected to white/red/black
// in that order.  White is the enable signal for a
// channel, while red and black match the pair of wires
// connected to the switch machine.

const Triad<byte> pins[] = {
  Triad<byte>(A0, A1, A2),
  Triad<byte>(9, 10, 11),
  Triad<byte>(8, 6, 5),
  Triad<byte>(3, 1, 0)
};

// Forward reference to I2C handlers.
void receiveCallback(int);
void requestCallback();

I2CSlave i2c(I2C_ADDR, receiveCallback, requestCallback);

const byte NUM_CHANS = sizeof pins / sizeof *pins;
SwitchMachine* chans[NUM_CHANS];
RingBuffer cmdBuffer(8);
RingBuffer opQueue(8);
Timeout timer;

const byte BAD_CHAN = 0xFF;

byte decodeChan(const byte chan)
{
  return (chan == eChan0) ? 0
       : (chan == eChan1) ? 1
       : (chan == eChan2) ? 2
       : (chan == eChan3) ? 3
       : BAD_CHAN;  // channel code not valid
}

// I2C Receive Handler, called when
// this I2C slave receives bytes from
// the I2C master.  Is passed the number
// of bytes in the received I2C transaction
// (not used, all commands are 1 byte long).
void receiveCallback(int i)
{
  cmdBuffer.push(Wire.read());
}

// Decode command byte received via I2C,
// and if it's valid translate it into an
// operation byte and queue it up for
// the SwitchMachine objects.
void decodeAndQueue(const byte cmdByte)
{
  // The channel code, if present, is in
  // the low 4 bits of the command byte.
  byte chan = decodeChan(cmdByte & 0x0F);
  
  // The command code is the high 4 bits only.
  byte cmd = cmdByte & 0xF0;
  
  // Decode commands, and queue up operation
  // if command is valid.
  if (cmd == eRefresh) {
    
    // Force all four switch machines to match
    // their current states, in case any were
    // switched by hand.
    for (byte c = 0; c < 4; ++c) {
      opQueue.push((byte) SwitchMachine::eRefresh | (c << 4));
    }
    
  } else if (cmd == eReset) {
    
    // Reset all four channels to their reset state
    // (main for LH and RH, left for Y, thru for DX).
    for (byte c = 0; c < 4; ++c) {
      opQueue.push((byte) SwitchMachine::eMain | (c << 4));
    }
    
  } else if (chan != BAD_CHAN) {
    
    if (cmd == eMain) {
      opQueue.push((byte) SwitchMachine::eMain | (chan << 4));
    } else if (cmd == eDiv) {
      opQueue.push((byte) SwitchMachine::eDiverging | (chan << 4));
    }
    
  }
}

void requestCallback()
{
  // no op  
}

void setup()
{
  for (byte i = 0; i < NUM_CHANS; ++i) {
    chans[i] = new SwitchMachine(pins[i]);
    delay(100);
  }
  i2c.begin();
}

void loop()
{
  // Update the SwitchMachine objects.
  for (byte i = 0; i < NUM_CHANS; ++i) {
    chans[i]->update();
  }
  
  // Update the Timeout.
  timer.update();
  
  // If there are any received commands buffered,
  // process the one at the front of the buffer.
  if (!cmdBuffer.isEmpty()) {
    decodeAndQueue(cmdBuffer.pop());
  }
  
  // If enough time has passed and there are any
  // operation codes in the queue, fetch the code
  // at the front of the queue and command the
  // selected switch machine to throw.
  if (timer.isTimedOut() && !opQueue.isEmpty()) {
    // Fetch the operation code.
    byte op = opQueue.pop();
    
    // The channel number is in the high 4 bits.
    byte chan = (op >> 4) & 0x03;
    
    // The operation is in the low 4 bits.
    op &= 0x0F;
    
    // Command the switch machine to throw.
    chans[chan]->throwPoints(static_cast<SwitchMachine::E_DIR>(op));
    
    // Force minimum delay before another switch
    // machine can be commanded to throw.
    timer.setTimeout(100);
  }
}
