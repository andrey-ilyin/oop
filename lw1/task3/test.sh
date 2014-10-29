#!/bin/sh

exe=./a.exe

#Запуск программы без параметров
result=`($exe)`
errorLevel=$?
expectation=`cat invalid_count_of_arguments.txt`
if [ "$errorLevel" -ne 1 ] || [ "$result" != "$expectation" ]; then
    echo "Failed checking without parameters."
    exit
fi

#Запуск программы с некорректным числом параметров
result=`($exe 10.10 +)`
errorLevel=$?
expectation=`cat invalid_count_of_arguments.txt`
if [ "$errorLevel" -ne 1 ] || [ "$result" != "$expectation" ]; then
    echo "Failed checking with invalid count of arguments."
    exit
fi

#Запуск программы с двумя параметрами и знаком
result=`($exe 1.2 + 3.5)`
errorLevel=$?
if [ "$errorLevel" -ne 0 ] || [ "$result" != "4.700" ]; then
    echo "Failed checking of sum."
    exit
fi

#Деление на ноль
result=`($exe 10 // 0)`
errorLevel=$?
expectation=`cat invalid_operation.txt`
if [ "$errorLevel" -ne 1 ] || [ "$result" != "$expectation" ]; then
    echo "Failed checking of operation."
    exit
fi

echo "Program testing succeeded!"
