#include "SecondModule.hpp"
#include <iostream>

namespace projectSystemC
{
    SecondModule::SecondModule(sc_module_name name) : sc_module(name)
    {
        SC_THREAD(printLedState);
    }

    void SecondModule::printLedState()
    {
        while (true)
        {
            wait(inputFifo->data_written_event());
            InputData inpuData = inputFifo->read();
            std::cout << "\n\nLed state:\n";

            if (!inpuData.isDataValid)
            {
                printLedError();
                return;
            }

            printLedStateForStorage(inpuData.secondStorage);
            printLedStateForOperation(inpuData.operation);
            printLedStateForStorage(inpuData.firstStorage);
        }
    }

    void SecondModule::printLedStateForStorage(const uint8_t storage)
    {
        switch (storage)
        {
        case 'A':
            printLedOff();
            printLedOn();
            break;
        case 'B':
            printLedOn();
            printLedOff();
            break;
        case 'C':
            printLedOn();
            printLedOn();
            break;
        default:
            break;
        }
    }

    void SecondModule::printLedStateForOperation(const uint16_t operation)
    {
        switch (operation)
        {
        case 1:
            printLedOn();
            printLedOff();
            break;
        case 2:
            printLedOff();
            printLedOn();
            break;
        default:
            break;
        }
    }

    void SecondModule::printLedError()
    {
        constexpr std::size_t numberOfLeds{5};
        for (std::size_t i = 0; i < numberOfLeds; i++)
        {
            printLedOff();
        }
    }

    void SecondModule::printLedOn()
    {
        std::cout << "{O} ";
    }

    void SecondModule::printLedOff()
    {
        std::cout << "{ }  ";
    }
} // namespace projectSystemC