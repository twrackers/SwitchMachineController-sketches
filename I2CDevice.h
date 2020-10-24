#ifndef _I2C_DEVICE__H_
#define _I2C_DEVICE__H_

#include <Arduino.h>
#include <Wire.h>

#include "SwitchMachineCmds.h"

typedef void (*CALLBACK0)();
typedef void (*CALLBACK1)(int);

class I2CDevice
{
  private:
    const byte m_addr;
    
  public:
    I2CDevice(
      const byte addr,
      CALLBACK1 receive,
      CALLBACK0 request
    );
    void begin();
};

#endif
