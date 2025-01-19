#include "NestedModule.hpp"

namespace projectSystemC
{
    NestedModule::NestedModule(sc_module_name name) : sc_module(name)
    {
        SC_THREAD(printHexDisplay);
    }

    void NestedModule::printHexDisplay()
    {
        while (true)
        {
            wait(inputFifo->data_written_event());
            InputData inputData = inputFifo->read();

            std::cout << "\nHex display:\n";
            if (!inputData.isDataValid)
            {
                std::cout << "E | r | r | o | r\n";
                return;
            }

            std::cout << inputData.secondStorage << " | " << inputData.operation << " | " << inputData.firstStorage << std::endl;
        }
    }
} // namespace projectSystemC
