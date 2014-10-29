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

#Запуск программы с невалидным параметром
result=`($exe abc)`
errorLevel=$?
expectation=`cat invalid_argument.txt`
if [ "$errorLevel" -ne 1 ] || [ "$result" != "$expectation" ]; then
    echo "Failed checking with invalid argument."
    exit
fi

#Запуск программы с параметром выходящем за допустимые пределы
result=`($exe -10)`
errorLevel=$?
expectation=`cat exceed_the_limits.txt`
if [ "$errorLevel" -ne 1 ] || [ "$result" != "$expectation" ]; then
    echo "Failed checking with parameter exceed the limits."
    exit
fi

result=`($exe 6)`
errorLevel=$?
if [ "$errorLevel" -ne 0 ] || [ "$result" != "96" ]; then
    echo "Failed checking flip for 6. It returns $result"
    exit
fi

echo "Program testing succeeded!"
