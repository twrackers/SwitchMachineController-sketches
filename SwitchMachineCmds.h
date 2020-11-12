#ifndef _SWITCH_MACHINE_CMDS__H_
#define _SWITCH_MACHINE_CMDS__H_

// NOTE: A copy of this file also exists under the SwitchMachineController
// sketch.  Both must define the same enumerated values.

// The command and channel codes below are bitwise OR'ed together to form
// single-byte codes which are compatible with the SwitchMachineController
// sketch (https://github.com/twrackers/SwitchMachineController-sketches).
// This set of codes will support up to 8 switch machines per controller,
// although the current version of the SwitchMachineController sketch only
// controls 4 switch machines on an Adafruit Pro Trinket or an Arduino UNO.

// Each command code has a Hamming distance
// of at least 2 bits from all other codes.
// Additional codes which would meet this
// criterion are (using only high 4 bits):
//   0x80  0xC0  0xE0  0xF0

enum E_CMD {
  eRefresh = 0x10,
  eMain    = 0x20,
  eDiv     = 0x40,
  eReset   = 0x70
};

// Channel codes also have a Hamming distance of at least 2 bits from each
// other.  For more than 8 channels per device, you will need to assign new
// codes or change the message format to use more bytes.
enum E_CHAN {
  eChan0 = 0x01,
  eChan1 = 0x02,
  eChan2 = 0x04,
  eChan3 = 0x07,
  eChan4 = 0x08,
  eChan5 = 0x0C,
  eChan6 = 0x0E,
  eChan7 = 0x0F
};

#endif
