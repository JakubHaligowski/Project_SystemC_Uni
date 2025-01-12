#include <systemc.h>
#include <iostream>
#include "FirstModule.hpp"
#include "NestedModule.hpp"
#include "SecondModule.hpp"

int sc_main(int argc, char *argv[])
{
    using namespace projectSystemC;
    
    sc_fifo<InputData> fifoForSecondModule(1);
    sc_fifo<InputData> fifoForNestedModlue(1);

    FirstModule firstModlue("FirstModule");
    SecondModule secondModule("SecondModule");

    firstModlue.secondModuleFifo(fifoForSecondModule);
    firstModlue.nestedModuleFifo(fifoForNestedModlue);
    secondModule.inputFifo(fifoForSecondModule);
    firstModlue.connectNestedModlueFifo(fifoForNestedModlue);

    sc_start();
    return 0;
}