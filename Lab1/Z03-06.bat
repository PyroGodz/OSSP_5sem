@echo off

chcp 65001

echo -- строка параметров: %1 %2
echo -- режим: %1
echo -- имя файла: %2

if "%1" == "" (
	echo ---+ z03-06 режим файла
	echo ---++ режим = {создать, удалить}
	echo ---++ файл = имя файла
	goto endFile
)

if "%2" == "" (
	echo ---+ не задано имя файла
	goto endFile
)

if "%1" == "удалить" (
    if not exist %2 (
        echo ---+ файл %2 не найден
        goto endFile
    ) 
    del %2
    echo ---+  файл %2 удален
    goto endFile
)

if "%1" == "создать" (
    if exist %2 (
        echo ---+ файл %2 уже существует
        goto endFile
    ) 
    type nul>%2
    echo ---+ файл %2 создан
    goto endFile
)

echo ---+ режим задан не корректно

:endFile