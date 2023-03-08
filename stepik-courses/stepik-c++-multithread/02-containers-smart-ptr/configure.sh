#! /usr/bin/bash

rm -rf build/; 
mkdir build;
cmake -C config.txt -S . -B build/;
