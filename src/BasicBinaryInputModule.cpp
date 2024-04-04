#include "BasicBinaryInputModule.h"

const std::string BasicBinaryInputModule::name()
{
    return "BasicBinaryInput";
}

const std::string BasicBinaryInputModule::version()
{
    return MODULE_BinaryInput_Version;
}

void BasicBinaryInputModule::setPins(uint8_t* gpioPins)
{
    _gpioPins = gpioPins;
}

void BasicBinaryInputModule::setup()
{
    if(_gpioPins == nullptr)
    {
        logErrorP("No GPIO pins defined, module inactive");
        return;
    }

    
    for(uint8_t i = 0; i < BI_ChannelCount;i++)
    {
        pinMode(_gpioPins[i], INPUT_PULLUP);
        _channels[i] = new BinaryInputChannel(i);
        _channels[i]->setup();
    }
}

void BasicBinaryInputModule::loop()
{
    if(_gpioPins == nullptr)
        return;

    processHardwareInputs();

    for (uint8_t i = 0; i < BI_ChannelCount; i++)
        _channels[i]->loop();
}

void BasicBinaryInputModule::processHardwareInputs()
{
    if(_gpioPins == nullptr)
        return;

    for(uint8_t i = 0; i < BI_ChannelCount;i++)
    {
        if (_channels[i]->isActive())
            _channels[i]->setHardwareState(digitalRead(_gpioPins[i]) == LOW);
    }
}

BasicBinaryInputModule openknxBasicBinaryInputModule;