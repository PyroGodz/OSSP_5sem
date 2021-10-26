@echo off

chcp 65001

echo -- строка параметров: %1 %2 %3
echo -- параметр 1: %1
echo -- параметр 2: %2
echo -- параметр 3: %3

set /a sum= %1 + %2
set /a mult= %1 * %2
set /a div= %3 / %2
set /a sub= %2 - %1
set /a prim= %sub * (%1 - %2)

echo -- %1 + %2 = %sum%
echo -- %1 * %2 = %mult%
echo -- %3 / %2 = %div%
echo -- %2 - %1 = %sub%
echo -- (%2 - %1) * (%2 - %1) = %prim%