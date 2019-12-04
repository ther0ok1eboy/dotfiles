## The key could not be found remotely

### only if the directory exists

`rm -R /etc/pacman.d/gnupg/`

`rm -R /root/.gnupg/`

`gpg --refresh-keys`

`pacman-key --init && pacman-key --populate archlinuxcn`

`pacman-key --refresh-keys archlinuxcn`


### if you use community source then you maybe have setted check

```shell
$ vim /etc/pacman.conf
# you should close this check

[archlinuxcn]
#SigLevel = Optional TrustedOnly
SigLevel = Optional TrustAll
Server = http://repo.archlinuxcn.org/$arch

```

### if you encounter the fowling problem

Error：can't mirrors.tuna.tsinghua.edu.cn : Operation too slow. Less than 1 bytes/sec transferred the last 10 seconds to get 'file-package'

Go to Google to see [this Wiki](https://forum.manjaro.org/t/cant-update-extra-db-with-syyu/9651/3)

**Resolve** 

```shell
$ vim /etc/pacman.conf
# add fowling code into this file
[options]
XferCommand = /usr/bin/wget --quiet --show-progress --passive-ftp -c -O %o %u
SigLevel    = Required DatabaseNever
```
### last suggestions

If you `$ sudo pacman -Syu` your system, you should go [Archlinux](https://www.archlinux.org/) to see some updates 
