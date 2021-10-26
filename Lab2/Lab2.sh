#!/bin/bash

name=$(ps -ef | grep "$1" | head -n 1 | awk '{print $8}')

if [ "$name" == "/bin/bash" ]
then
echo pid="$1" process not found
exit 1
fi

if [ "$1" == "" ]
then
echo parametrs not found
exit 1
fi

ppid=$(ps -ef | grep "$1" | head -n 1 | awk '{print $3}')

printf "name:\t%-5s\n" "$name"
printf "pid:\t%-5s\n" "$1"
printf "ppid:\t%-5s\n" "$ppid"

if [ "$2" == "fd" ]
then
# shellcheck disable=SC2012
fds=$(ls -l /proc/"$1"/fd/ | awk '{print $9}')
for fd in $fds
do
echo fd = "$fd"
done
fi