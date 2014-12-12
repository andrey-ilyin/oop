#!/bin/sh

exe=./multmatrix.exe

#Запуск программы без параметров
result=`($exe)`
errorLevel=$?
expectation=`cat test/invalid_count_of_arguments.txt`
if [ "$errorLevel" -ne 1 ] || [ "$result" != "$expectation" ]; then
    echo "Failed checking without parameters."
    exit
fi

#Проверка на обработку ошибки с открытием файла
result=`($exe test/correct_m1.txt invalid_file.txt)`
errorLevel=$?
expectation=`cat test/invalid_file.txt`
if [ "$errorLevel" -ne 1 ] || [ "$result" != "$expectation" ]; then
    echo "Failed checking invalid file opening."
    exit
fi

#Проверка на feof в файле матрицы
result=`($exe test/correct_m1.txt test/invalid_m2.txt)`
errorLevel=$?
expectation=`cat test/invalid_matrix_3x3.txt`
if [ "$errorLevel" -ne 1 ] || [ "$result" != "$expectation" ]; then
    echo "Failed checking for feof."
    exit
fi

#Проверка перемножения матриц
result=`($exe test/correct_m1.txt test/correct_m2.txt)`
errorLevel=$?
expectation=`cat test/correct_result1.txt`
if [ "$errorLevel" -ne 0 ] || [ "$result" != "$expectation" ]; then
    echo "Failed checking for matrix multiplication."
    exit
fi


echo "Program testing succeeded!"
