#pragma once
#include <systemc.h>
#include "InputData.hpp"

namespace projectSystemC
{
    class NestedModule : public sc_module
    {
    public:
        sc_port<sc_fifo_in_if<InputData>> inputFifo;
        NestedModule(sc_module_name name);

    private:
        void printHexDisplay();
    };
} // namespace projectSystemC