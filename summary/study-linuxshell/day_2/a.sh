#!/bin/fish

echo "use fish to explain syntax shell scrept..."

for i in `ls /home`; do
#    id -u $i
    id $i
done

echo "act explains that bash better than fish in shell"

read -p "please input something..." name
echo $name

string=`whereis fish`
echo $string
