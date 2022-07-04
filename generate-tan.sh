#! /bin/bash
TAN="/Users/chris/Desktop/HTW-Zeug/Security Engineering/U05/TAN"

read -p "Username: " name
read -p "Anzahl TAN-Nummern: " zahl

declare -a array

for ((i=0; i<$zahl; i++))
do
    #passwort=$(( $RANDOM % 99999 + 10000 ))
    passwort=$(openssl rand -base64 30)
    array[i]=$(openssl passwd -6 -salt x "$passwort")
    echo ${array[i]} "$passwort"
done
printf "%s\n" "${array[@]}" > $name.txt
mv $name.txt TAN