#! /bin/bash
TAN="/Users/chris/Desktop/HTW-Zeug/Security Engineering/U05/TAN"

read -p "Username: " name
read -p "Anzahl TAN-Nummern: " zahl

declare -a array

for ((i=0; i<$zahl; i++))
do
    array[i]=$(( $RANDOM % 99999 + 10000 ))
    echo ${array[i]}
done
printf "%s\n" "${array[@]}" > $name.txt
mv $name.txt TAN