## Today, i will share how to scientific surfing on Linux 

### First and foremost, you should have some abroad nodes or line

**i have gone to [there](https://justmysocks.net/members/)(need scientific surfing) to buy my nodes** 

### You should install a proxy client application

**maybe shadowsocks-qt5 is a good choice**

**nowdays, it only support artificial add**

`$ sudo pacman -Syu` 

`$ sudo pacman -S shadowsocks-qt5` 

`ss-qt5`

### Configure your ss-qt5

**after startup it, artificial add your sever infrmation into ss-qt5** 

**default setting the listen port is `127.0.0.1:1080`**

`sudo netstat -pantu | grep :1080` you will see that your local port has listened

### Last, setting you browser's proxy configuration

**find your browser's proxy interface, only modify the SOCK5 interface `ip:127.0.0.1 port:1080`**

### You also can understand like me

**the date your browser send to your request distinaation will auto transmit into your request distination by your local 1080 port which is been listenes by ss-qt5.**

**in a word, your data send to Internet by your abroad server node**    
