#!/bin/bash
TAN="/Users/chris/Desktop/HTW-Zeug/Security Engineering/U05/TAN"

sighandler_INT() {
   printf "\nHabe das Signal SIGINT empfangen\n"
   printf "Soll das Script beendet werden (j/n) : "
   read
   if [[ $REPLY = "j" ]]
   then
      echo "Bye!"
      exit 0;
   fi
}
trap 'sighandler_INT' 2
echo "_____Bank Transaktionen_____"
read -p "Username: " name
cd TAN

tanliste="$name.txt"
if  [ ! -f "$tanliste" ];
    then
        echo "TAN-Liste leer. Bitte Neue generieren11!"
        cd ..
        ./generate-tan.sh
        ./bank_transaction.sh
    fi
typeset -i i=0
while true
do
    while read array[$i]
    do 
        #weiter=true
        #while [ "$weiter" = true ]
        #do
            echo "Username: " $name
            echo "TAN-Nummer: "
            read tan </dev/tty
            neueTan=$(openssl passwd -6 -salt x "$tan")
            echo "$neueTan"
            #pw=$(openssl passwd -1 "${array[i]}")
            if [ "$neueTan" = "${array[i]}" ]
                then
                    echo "Nach then!" "${array[i]}"
                    echo "Zugriff erlaubt!"
                    echo "Die Tan ist korrekt und wurde gelöscht"
                    sed -i "" '1d' "$tanliste"
                    #shift ${array[0]}
                    array=("${array[@]:1}")
                    #unset array[0]
                    #array=("${array[@]}")
                    #"$weiter" = false
                else
                    #while true
                    #do
                        echo "Zugriff verweigert!"
                        echo "Die Tan ist nicht korrekt"
                        echo "${array[i]}"
                        break
                    #done
                    #"$weiter" = true
            fi
        #done
        #i=i+1
    done < $tanliste
    #if  [ ! -f "$tanliste" ];
    #then
    #    echo "TAN-Liste leer. Bitte Neue generieren!"
    #cd ..
    #    ./generate-tan.sh
    #    ./bank_transaction.sh
    #fi
    #rm "$tanliste"
    #sleep 1
    #cd ..
    #echo "Tan-Liste leer!"
    #sleep 1
    #./bank_transaction.sh
    #sleep 1
    #if [ -f "$tanliste" ]; then
    #    echo "$FILE exists."
#else 
 #   echo "$FILE does not exist."
#fi
done

    #if [ ${#array[@]} ];
    #./generate-tan.sh
    #echo "Fehler"
    #