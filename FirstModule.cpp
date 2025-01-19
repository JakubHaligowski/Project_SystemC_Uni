#include "FirstModule.hpp"
#include <sstream>

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
            std::cout << "Enter values for the first storage, operation and second storage\n";
            std::cout << "Valus should be sperated by spaces, in the format: A/B/C 1/2 A/B/C\n";
            std::cout << "or type Q to exit\n";

            std::string userInput;
            std::getline(std::cin, userInput);

            if (userInput.empty())
            {
                continue;
            }

            std::istringstream ss(userInput);

            if (ss.str().at(0) == 'Q')
            {
                sc_stop();
                break;
            }

            ss >> inputData.firstStorage;
            ss >> inputData.operation;
            ss >> inputData.secondStorage;
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

            if (inputData.firstStorage != 'A' && inputData.firstStorage != 'B' && inputData.firstStorage != 'C')
            {
                std::cout << "Invalid value for the first storage\n";
                inputData.isDataValid = false;
            }

            if (inputData.secondStorage != 'A' && inputData.secondStorage != 'B' && inputData.secondStorage != 'C')
            {
                std::cout << "Invalid value for the second storage\n";
                inputData.isDataValid = false;
            }

            if (inputData.operation != 1 && inputData.operation != 2)
            {
                std::cout << "Invalid value for the operation\n";
                inputData.isDataValid = false;
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