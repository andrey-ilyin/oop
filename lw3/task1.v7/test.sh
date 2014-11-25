#!/bin/sh

exe=./vector.exe

testParams=`cat test/numbers.txt`
expectation=`cat test/result.txt`
echo "Run program with parametes:\n$testParams"
result=`($exe < test/numbers.txt)`
errorLevel=$?
echo "Result\n$result"
if [ "$errorLevel" -ne 0 ] || [ "$result" != "$expectation" ]; then
    echo "Calculations are wrong!"
    exit
fi

echo "Program testing succeeded!"