#include "FirstModule.hpp"

namespace projectSystemC
{
    FirstModule::FirstModule(sc_module_name name) : sc_module(name)
    {
        SC_THREAD(readKeyboardInput);
        SC_THREAD(validateUserInput);
    }

    void FirstModule::readKeyboardInput()
    {
        while (true)
        {
            InputData inputData{};
            std::cout << "Eneter value for the first storage (A/B/C):\n";
            std::cin >> inputData.firstStorage;
            std::cout << "Eneter value for the operation \n";
            std::cin >> inputData.operation;
            std::cout << "Eneter value for the second storage (A/B/C):\n";
            std::cin >> inputData.secondStorage;
            inputState.write(inputData);
            wait(3, SC_SEC);
        }
    }

    void FirstModule::validateUserInput()
    {
        while (true)
        {
            wait(inputState.value_changed_event());
            InputData inputData{inputState.read()};
            bool isDataValid{true};

            if (inputData.firstStorage != 'A' && inputData.firstStorage != 'B' && inputData.firstStorage != 'C')
            {
                std::cout << "Invalid value for the first storage\n";
                isDataValid = false;
            }

            if (inputData.secondStorage != 'A' && inputData.secondStorage != 'B' && inputData.secondStorage != 'C')
            {
                std::cout << "Invalid value for the second storage\n";
                isDataValid = false;
            }

            if (inputData.operation != 1 && inputData.operation != 2)
            {
                std::cout << "Invalid value for the operation\n";
                isDataValid = false;
            }

            if (!isDataValid)
            {
                continue;
            }

            secondModuleFifo->write(inputData);
            nestedModuleFifo->write(inputData);
        }
    }

    void FirstModule::connectNestedModlueFifo(sc_fifo<InputData> &fifo)
    {
        nestedModule.inputFifo(fifo);
    }
} // namespace projectSystemC