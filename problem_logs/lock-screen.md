### 1 arch linux:
    $ installing dependencies(not required if using betterlockscreen aur package)
	$ pacman -s imagemagick feh xorg-xrandr xorg-xdpyinfo i3lock-color

### 2 Installation: 
    $git clone https://github.com/pavanjadhaw/betterlockscreen
	$ cd betterlockscreen
	$ cp betterlockscreen ~/.local/bin/

### 3 choose your lock_screen wallpaper then automatically store into ~/.cache/i3lock/1980x1200:
	$ betterlockscreen -u "/path/to/img.jpg"

### 4 if that add the command to i3wm is invalid, make shell to /usr/bin:

	$ touch /usr/bin/lock.sh && cd /usr/bin && vim lock.sh
	
input '~/.local/bin/betterlockscreen --lock blur' or '~/.local/bin/betterlockscreen -w dim' in shell
	chmod 777 lock.sh && alias lk lock.sh

