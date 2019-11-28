#!/bin/bash

function eoffunc(){
value=ssssssucessful
cat << eof
    aaaaa${value}aaaaa
    aaaaa`echo -e "\033[30;47m${value}\033[0m"`aaaaa
    aaaaaaaaaaaaaaaaaaaaaaaa
eof
}

eoffunc
eoffunc

