#pragma once
#include <systemc.h>
#include "NestedModule.hpp"

namespace projectSystemC
{
    class FirstModule : public sc_module
    {
    public:
        FirstModule(sc_module_name name);
        void connectNestedModlueFifo(sc_fifo<InputData> &fifo);

        sc_port<sc_fifo_out_if<InputData>> secondModuleFifo;
        sc_port<sc_fifo_out_if<InputData>> nestedModuleFifo;

    private:
        void readKeyboardInput();
        void validateUserInput();
        sc_signal<InputData> inputState;
        NestedModule nestedModule{"NestedModule"};
    };
} // namespace projectSystemC