#!/bin/sh

exe=./vector.exe

#Запуск программы без параметров
result=`($exe)`
errorLevel=$?
if [ "$errorLevel" -ne 0 ]; then
    echo "Failed."
    exit
fi

echo "Program testing succeeded!"