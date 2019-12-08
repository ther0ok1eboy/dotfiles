## linux user:

- **1. root(u)** 

- **2. group(g)** 

- **3. other user(o)** 

- **4. all user(a)** 

## user management:

- **1. show users:**

    `id user1`
```sh
id user1
```

- **2. add a user:**

    `useradd user1 //this user belong to other user`

- **3. delete a user:**

    `userdel -r user1`

- **4.chech whether user1 have passwords:**

    `cat /etc/shadow | grep user1`
        if have ! mean not password
  
- **5.add password for user1:**

    `passwd user1`

## user and group:

- **1. add user into group:**

    `gpasswd -a(add) user1 root/sorria`

- **2. delete user form group:**

    `gpasswd -d(delete) user1 root/sooria`

- **3. cheack belongs:**

    `head -1 /etc/passwd`

    `head -1 /etc/group`
        root: x :0:root ==> group of root have only a user root

    `cat /etc/group | grep user1`

## chmod to contribute permission:
 
- **1. mkdir file-name** this default permission of this file is 755

- **2. chmod u+x file-name** 

- **3. chmod 777 file-name**
    r => 4  w => 2  x => 1
    `chmod 644 file-name`  

- **4. different permission bewten file and directory:**

    for flie: r is read the file; w is write the file; x is you can excute the file

    for directory: r is you can browse the file; w is you can create directory or file; x is you can cd to the file 

## acl contribute permission:

- **1. set file permission** 

    `setfacl -m(modify) u:user1:rwx file-name` 
    
    `setfacl -m u:user1:rwx -R(recursion) file-name //set file,child file and child'child file's permission`  

- **2. browse file permission** 

    `getfacl file-name`   

- **3. delete permission to file or directory:** 

    `setfacl -x u:user1 file-name //delete user1's permission form file-name`

    `setfacl -b file-name //delete all users's permission form file-name` 

- **4. if you want to remove this file-name, you should modify its father directory's permission**    

- **5. inherented father'directory'permission later:** 

    `setfacl -m u:user1:rwx -R file-name` 

    `setfacl -m d:u:user1:rwx -R file-name //add default permission to this file-name which means inhrent prmission`    

- **6. set user'permission to excute oders with passwords:** 

    `visudo then add 'user1 localhost=/usr/bin/pacman(oders'position)'` 

- **7. set user'permission to excute oders without passwords:** 

    `user1 ALL/localhost=NOPASSWD: /usr/bin/pacman` 

 
