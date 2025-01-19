#!/bin/bash

git clone https://github.com/accellera-official/systemc.git
mkdir ./systemc/build
(cd ./systemc/build;cmake .. -DCMAKE_INSTALL_PREFIX=../install)
(cd ./systemc/build;make -j$(nproc))
(cd ./systemc/build;make install)
