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
            std::cout << "Hex display:\n";
            std::cout << inputData.secondStorage << " | " << inputData.operation << " | " << inputData.firstStorage << std::endl;
        }
    }
} // namespace projectSystemC
