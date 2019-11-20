UN1 download:**

    $ sudo pacman -S xorg

**2 show your recent keybord layouts:**

    $ xmodmap

**3 show id of your of all keybord layouts:**

    $ xev

**4 input your layouts into .xmodmap:**

    $ xmodmap -pke > ~/.xmodmap && vim .xmodmap

**5 change the Esc and CapLock:**

    change their contents behind the id and input 'clear lock' into header of file and 'add lock = Cap_Lock'

**6 save config:**

     $ xmodmap ~/.xmodmap
