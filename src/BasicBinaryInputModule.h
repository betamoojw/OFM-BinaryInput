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

    uint8_t* _gpioPins = nullptr;

    BinaryInputChannel* _channels[BI_ChannelCount];
};

extern BasicBinaryInputModule openknxBasicBinaryInputModule;