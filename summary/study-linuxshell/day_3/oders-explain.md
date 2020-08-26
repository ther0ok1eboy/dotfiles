- **df -Th | grep dev/sdb4 | awk '{print $6}' | cut -d % -f1**

    - means grep to find row of dev/sdb4 then 
    - print sixth column data then 
    - base on % to split this results then 
    - show the first part of result

- **cat /etc/passwd | awk -F: 'print $1'}** 

    - means each row must base on : to split then
    - print the first contents

- **df -h | awk '{if(NR==2){print $4}}'** 

    - print contents whose position is the second row and four column  
