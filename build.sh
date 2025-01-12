#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PARENT_DIR="$(dirname "$SCRIPT_DIR")"
export SYSTEMC_HOME=$PARENT_DIR/systemc/install
mkdir ./build
(cd ./build; cmake ..)
(cd ./build; make)

