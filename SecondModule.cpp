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
        wait(inputFifo->data_written_event());
        InputData inpuData = inputFifo->read();
        std::cout << "Led state:\n";
        printLedStateForStorage(inpuData.secondStorage);
        printLedStateForOperation(inpuData.operation);
        printLedStateForStorage(inpuData.firstStorage);
        std::cout << std::endl;
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
            printLedOff();
            printLedOff();
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
            printLedOff();
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