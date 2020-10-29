#ifndef _I2C_PERIPHERAL__H_
#define _I2C_PERIPHERAL__H_

#include <Arduino.h>
#include <Wire.h>

typedef void (*CALLBACK0)();
typedef void (*CALLBACK1)(int);

class I2CPeripheral
{
  private:
    const byte m_addr;
    
  public:
    I2CPeripheral(
      const byte addr,
      CALLBACK1 receive,
      CALLBACK0 request
    );
    void begin();
};

#endif
