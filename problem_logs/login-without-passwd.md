### Introduction

If you are frequently login your server and each login needs you inputing password. You may feel it so disgusting... OK, the following commands also resolve your sufferjng.

### Quick start

**Auto product SSH public key**

`ssh-keygen -t rsa -P ''` the the file will store on path `~/.ssh`

**Give your server the file(key value)**

`scp (-P your server-port) your-file-path USER@IP:store-path`  

Such as `scp -P 2222 ~/.ssh/id_rsa root@192.168.0.0:/root/.ssh/id_rsa_` 

**Add the key to the known host**

Login in your remote server and input `cat ~/.ssh/id_rsa_ >> ~/.ssh/known_hosts`

OK, you can login your remote server without password.

    
