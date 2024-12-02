#!/bin/bash

g++ -lm -g ./data/*.cpp ./algo/*.cpp main.cpp -o main.exe
chmod u+x ./main.exe

./main.exe