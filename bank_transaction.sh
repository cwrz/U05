#!/bin/bash
TAN="/Users/chris/Desktop/HTW-Zeug/Security Engineering/U05/TAN"

read -p "Username: " name
read -p "TAN-Nummer: " tan
cd TAN
tanliste="$name.txt"
echo "$tanliste"
typeset -i i=0
while read array[$i]
    do
        if [ "$tan" = "${array[0]}" ]
            then
                echo "Zugriff erlaubt!"
                echo "Die Tan ist korrekt und wurde gelöscht"
                sed -i "" '1d' "$tanliste"
                break
            else
                echo "Zugriff verweigert!"
                echo "Die Tan ist nicht korrekt"
                exit
        fi
        i=i+1
    done < $tanliste

cd ..
./generate-tan.sh
echo "$name"
echo "$i"
