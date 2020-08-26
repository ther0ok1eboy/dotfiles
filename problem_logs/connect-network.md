# Uesing pppoe to connect network:
--------


- **1 if not have this command "netctl", install it:**

    `$ sudo pacman -S netctl`

- **2 download pppoe protocol:**
    
    `$ sudo pacman  -S rp-pppoe`

- **3 configurations:**
    
    ```c
    $ sudo cp /etc/netctl/example/pppoe /etc/netctl && sudo vim /etc/netctl/pppoe
    $ sudo ip link (to look your network cards interface)
    ```

    **modify "interface=enp2s0   user='1806102003'   password='032992'" at pppoe file**

- **4 close this network card and show the accessible network methods:**

    `$ sudo ip link set enp2s0 down && sudo netctl list`

- **5 connect network by pppoe:**
    
    `$ sudo netctl start pppoe`
