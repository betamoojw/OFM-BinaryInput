#include "BinaryInputModule.h"

const std::string BinaryInputModule::name()
{
    return "BinaryInput";
}

const std::string BinaryInputModule::version()
{
    // hides the module in the version output on the console, because the firmware version is sufficient.
    return "";
}

void BinaryInputModule::setPins(uint8_t* gpioPins)
{
    _gpioPins = gpioPins;
}

void BinaryInputModule::setup()
{
    if(_gpioPins != nullptr)
    {
        for(uint8_t i = 0; i < BI_ChannelCount;i++)
        {
            pinMode(_gpioPins[i], INPUT_PULLUP);
            _channels[i] = new BinaryInputChannel(i);
            _channels[i]->setup();
        }
        return;
    }
}

void BinaryInputModule::loop()
{
    processHardwareInputs();

    for (uint8_t i = 0; i < BI_ChannelCount; i++)
        _channels[i]->loop();
}

void BinaryInputModule::processHardwareInputs()
{
    for(uint8_t i = 0; i < BI_ChannelCount;i++)
    {
        if (_channels[i]->isActive())
            _channels[i]->setHardwareState(digitalRead(_gpioPins[i]) == LOW);
    }
}

BinaryInputModule openknxBinaryInputModule;