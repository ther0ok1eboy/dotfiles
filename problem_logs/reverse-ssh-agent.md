### Introduction

You may use SSH service to connect your cloud servers, but you may not know how to connect LAN server. I used to use FRP or Ngrok to penetrate LAN, i feel those ways will spent a lot of time and you also need to register an account. So i find our commonly used SSH service also does this work.

### Prerequisite

You need a cloud server name A and two PC in deffirent LAN name B and C (B is your home PC and C is your work PC).

The work principle is A map C's 22 port to WAN(C will open a port like 5432 to connect C's a random port like 2345. And C will open a new port like 54321 to listen in WAN)

| server name | open port | listen port |
|-------------|-----------|-------------|
| A           | 54321     | 5432        |
| B           | random    | random      |
| C           | 2345      | 22          |

### Quick start

**Some operations in C**

`ssh -CqTfnN -R :5432:localhost:22 root@49.235.215.98 -p 10022`(22 is your local SSH service port and 10022 is your cloud server SSH service port), If you used server is domestic you also need setting your safe rule.  

**Some operations in B**

`ssh root@49.235.215.98 -p 5432`. Looks like you are connecting cloud server, but in fact you are connecting LAN server C's 22 port.

And you need inputing root password(not your login password). If you do not know what is your root password. `su root && passwd root` 

**Some management scripts**

cloud server:
```shell
if [ -n "$1" ] && [ "$1" -gt "0" ];then
        PID=$(netstat -anp | grep $1 | awk '/sshd/ && !/awk/{print $7}')
            PID=${PID%%/*}

                if [ -n "${PID}" ];then
                            kill -9 $PID && exit 0
                                fi
                            fi

                            exit 1
```
usage: chmod 777 kill-remoteSSH.sh && ./kill-remoteSSH 5432
