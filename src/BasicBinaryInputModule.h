#include "BinaryInputChannel.h"
#include "OpenKNX/Module.h"
#include "hardware.h"

class BasicBinaryInputModule : public OpenKNX::Module
{

  public:
    const std::string name() override;
    const std::string version() override;
    void loop() override;
    void setup() override;
    void setPins(uint8_t* gpioPins);

  private:
    void processHardwareInputs();

    uint32_t _lastHardwareQuery = 0;

#ifdef OPENKNX_BASIC_BINARY_INPUT_GPIO_PINS
    uint8_t _gpioPinArray[BI_ChannelCount] = {OPENKNX_BASIC_BINARY_INPUT_GPIO_PINS};
    uint8_t* _gpioPins = _gpioPinArray;
#else
    uint8_t* _gpioPins = nullptr;
#endif
    BinaryInputChannel* _channels[BI_ChannelCount];
};

extern BasicBinaryInputModule openknxBasicBinaryInputModule;