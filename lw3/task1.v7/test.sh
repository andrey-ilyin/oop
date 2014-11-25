#!/bin/sh

exe=./vector.exe

#check for invalid count of numbers
result=`($exe < /dev/null)`
errorLevel=$?
expectation=`cat test/invalid_count_of_numbers.txt`
if [ "$errorLevel" -ne 1 ] || [ "$result" != "$expectation" ]; then
    echo "Faild checking invalid cout of numbers."
    exit
fi

#main scenario
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