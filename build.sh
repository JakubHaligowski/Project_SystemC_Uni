#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
export SYSTEMC_HOME=$SCRIPT_DIR/systemc/install
[ -d build ] || mkdir ./build
(cd ./build; cmake ..)
(cd ./build; make)

