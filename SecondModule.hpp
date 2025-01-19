#pragma once
#include <systemc.h>
#include "InputData.hpp"

namespace projectSystemC
{
    class SecondModule : public sc_module
    {
    public:
        sc_port<sc_fifo_in_if<InputData>> inputFifo;
        SecondModule(sc_module_name name);

    private:
        void printLedState();
        void printLedError();
        void printLedStateForStorage(const uint8_t storage);
        void printLedStateForOperation(const uint16_t operation);
        void printLedOn();
        void printLedOff();
    };
} // namespace projectSystemC