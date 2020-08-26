## how to use find:


- **find . -name "*.md"** 
    - under reccent directory to find the tail is md's files

- **find . -name "[a-z]"** 

    - under reccent directory to find head is a-z's files

- **find / -name "host"** 

    - under root directory to find...

- **find . -perm 644** 

    - under reccent directory to find permission is 644'files

- **find . -user root** 

    - under root directory to find files whose user is root


- **find /var -mtime -5/+5** 

    `$ stat file/directory //the status of file of directory` 

    - find the files whose change time within 5/before 5

- **find . -type d/f/l** 

    - file the file whose type is directory/file/link file

- **find . -size 1024000c** 

    - find the files whose file size greater than 1.024MB // 1MB = 1000,000 bits

- **find . -name ".txt | xargs rm -f"** 

    - emmmm.. maybe i will known what's mean later
