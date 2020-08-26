### cat:

- **show the contents of file** 

### tee:
    
- **be similar with cat and save a file** 

    `$ ls -l | tee bak.txt` 

### more:
        
- **if the contents more than this screen to show, show gratually** 

    `$ journalctl | more //and use Enter to show more` 
    
    `$ more a.txt` 

### head && tail:

- **show ten row head contents of file or tail contents** 

    `$ ll | head -5 //show five row head data` 

### nl:

- **be similar with cat and show row number then show detail information** 

    `$ ll | nl` 


### test:

- **test status of file:** 

    - format: [ operation file or directory ]

    - commond operators:
        
        -d: if or not a directory

        -f: if or not a file

        -e: if or not exist

        -r/-w/-x: if or not can read/write/excute 
        
        `$ [ -e /home/sorria ] //ture for 1, fail 0`  

    - **intger compare** 

        - format: [ intger1 operator intger2 ]
    
        - commond operator:

            -eq: equal

            -ne: not equal

            -gt: greater than

            -lt: lesser than

            -le: lesser or equal

            -ge: greater or equal


    - **string compare** 

        - format: [ string1 operator string2 ]

        - commond operator: =, != and -z for NULL
