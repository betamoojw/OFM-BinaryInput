#include "BinaryInputChannel.h"
#include "OpenKNX/Module.h"
#include "hardware.h"

#ifdef OPENKNX_BI_GPIO_PINS

#ifndef OPENKNX_BI_ONLEVEL
#define OPENKNX_BI_ONLEVEL LOW
#endif

class GpioBinaryInputModule : public OpenKNX::Module
{

  public:
    const std::string name() override;
    const std::string version() override;
    void loop() override;
    void setup() override;

  private:
    void processHardwareInputs();

    uint32_t _lastHardwareQuery = 0;

    const uint8_t _gpioPins[BI_ChannelCount] = {OPENKNX_BI_GPIO_PINS};

    BinaryInputChannel* _channels[BI_ChannelCount];
};

extern GpioBinaryInputModule openknxGpioBinaryInputModule;

#endif