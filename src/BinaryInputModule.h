#include "BinaryInputChannel.h"
#include "OpenKNX/Module.h"
#include "hardware.h"

#ifndef OPENKNX_BI_ONLEVEL
#define OPENKNX_BI_ONLEVEL LOW
#endif

class BinaryInputModule : public OpenKNX::Module
{

  public:
    const std::string name() override;
    const std::string version() override;
    void loop() override;
    void setup() override;

  private:
    void processHardwareInputs();

    uint32_t _lastHardwareQuery = 0;

#ifdef OPENKNX_BI_PINS
    uint8_t _gpioPinArray[BI_ChannelCount] = {OPENKNX_BI_PINS};
    uint8_t* _gpioPins = _gpioPinArray;
#else
    uint8_t* _gpioPins = nullptr;
#endif
    BinaryInputChannel* _channels[BI_ChannelCount];
};

extern BinaryInputModule openknxBinaryInputModule;