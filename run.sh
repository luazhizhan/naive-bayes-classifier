#!/bin/bash
rm main.exe
echo "Building main.c to main.exe..."
gcc -std=c99 -pedantic -Wall -Wextra -Wwrite-strings -Werror -g main.c -o main.exe
echo "Executing main.exe..."
./main.exe
