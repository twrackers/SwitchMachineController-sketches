#include <Wire.h>

#include "I2CDevice.h"

// I2CDevice class - Handles device end of I2C link to central processor.
I2CDevice::I2CDevice(
  const byte addr,      // I2C address of this processor
  CALLBACK1 receive,    // address of onReceive callback
  CALLBACK0 request     // address of onRequest callback
) : m_addr(addr)
{
  // Set up callbacks for I2C interface.
  Wire.onReceive(receive);
  Wire.onRequest(request);
}

void I2CDevice::begin()
{
  // Begin I2C interface.
  Wire.begin(m_addr);
}
