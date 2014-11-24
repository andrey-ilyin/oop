#!/bin/sh

exe=./findtext.exe

#Запуск программы без параметров
result=`($exe)`
errorLevel=$?
expectation=`cat test/empty_args.txt`
if [ "$errorLevel" -ne 1 ] || [ "$result" != "$expectation" ]; then
    echo "Failed checking without parameters."
    exit
fi

#Проверка на недоступном файле
result=`($exe invalid.txt search)`
errorLevel=$?
expectation=`cat test/invalid_file.txt`
if [ "$errorLevel" -ne 1 ] || [ "$result" != "$expectation" ]; then
    echo "Failed invalid file."
    exit
fi

#Поиск пустой подстроки
result=`($exe test/poem.txt "")`
errorLevel=$?
expectation=`cat test/search_is_empty.txt`
if [ "$errorLevel" -ne 1 ] || [ "$result" != "$expectation" ]; then
    echo "Failed checking empty search string."
    exit
fi

#Поиск не существующего текста
result=`($exe test/poem.txt "nothing")`
errorLevel=$?
expectation=`cat test/text_not_found.txt`
if [ "$errorLevel" -ne 1 ] || [ "$result" != "$expectation" ]; then
    echo "Failed checking if text is not found."
    exit
fi

echo "Poem:"
cat test/poem.txt
echo ""

#Проверка поиска Roses
result=`($exe test/poem.txt "Roses")`
errorLevel=$?
expectation="0"
echo "$exe test/poem.txt \"Roses\""
echo $result
if [ "$errorLevel" -ne 0 ] || [ "$result" != "$expectation" ]; then
    echo "Faild to find 'Roses'."
    exit
fi

#Проверка поиска are
result=`($exe test/poem.txt "are")`
errorLevel=$?
expectation=`cat test/find_are.txt`
echo "$exe test/poem.txt \"are\""
echo $result
if [ "$errorLevel" -ne 0 ] || [ "$result" != "$expectation" ]; then
    echo "Faild to find 'are'."
    exit
fi
                          
echo "Program testing succeeded!"
