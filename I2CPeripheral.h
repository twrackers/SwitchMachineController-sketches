#ifndef _I2C_PERIPHERAL__H_
#define _I2C_PERIPHERAL__H_

#include <Arduino.h>
#include <Wire.h>

typedef void (*CALLBACK0)();
typedef void (*CALLBACK1)(int);

class I2CPeripheral
{
  public:
    I2CPeripheral(
      CALLBACK1 receive,
      CALLBACK0 request
    );
    void begin(const byte addr);
};

#endif
