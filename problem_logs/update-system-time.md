- ### 1 install ntp:
    `$ yum -y install ntp or yaourt -S ntp`

- ### 2 update time:
    `$ ntpdate time1.aliyun.com`

- ### 3 or:
    ```c
    $ sudo timedatectl set-local-rtc 1 --adjust-system-clock
    $ sudo timedatectl set-ntp 0
---

    


