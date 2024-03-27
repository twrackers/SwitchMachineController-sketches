#include <Wire.h>

#include "I2CPeripheral.h"

// I2CPeripheral class - Handles device end of I2C link to central processor.
I2CPeripheral::I2CPeripheral(
  CALLBACK1 receive,    // address of onReceive callback
  CALLBACK0 request     // address of onRequest callback
)
{
  // Set up callbacks for I2C interface.
  Wire.onReceive(receive);
  Wire.onRequest(request);
}

void I2CPeripheral::begin(
  const byte addr       // I2C address of this processor
)
{
  // Begin I2C interface.
  Wire.begin(addr);
}
