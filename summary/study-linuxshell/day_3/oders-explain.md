- **df -Th | grep dev/sdb4 | awk '{print $6}' | cut -d % -f1**

    - means grep to find row of dev/sdb4 then 
    - print sixth column data then 
    - base on % to spill this results then 
    - show the firt part of result

- **cat /etc/passwd | awk -F: 'print $1'}** 

    - means each row must base on : to spill then
    - print the first contents
