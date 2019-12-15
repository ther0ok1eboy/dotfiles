## Some problems i encounter when i update my system

### Description:

**yesterday, i update my system as usual as always, even though i am concerned about it could make my system crash, i still update my system simply becase i want to insatll Firefox that Aria2 needs. So just as i feared, it happened** 

### My system informations:

```shell
██████████████████  ████████   sorria@rooter
██████████████████  ████████   -------------
██████████████████  ████████   OS: Manjaro Linux x86_64
██████████████████  ████████   Kernel: 5.4.2-1-MANJARO
████████            ████████   Shell: fish 3.0.2
████████  ████████  ████████   Resolution: 1920x1080
████████  ████████  ████████   WM: i3
████████  ████████  ████████   Terminal: alacritty
████████  ████████  ████████   Terminal Font: Hack Nerd Font
████████  ████████  ████████   CPU: Intel i5-8250U (8) @ 3.400GHz
████████  ████████  ████████   GPU: NVIDIA GeForce MX150
████████  ████████  ████████   GPU: Intel UHD Graphics 620
████████  ████████  ████████   Memory: 912MiB / 11865MiB
████████  ████████  ████████   Battery0: 92% [Discharging]
```

### Problems and solutions:

#### ranger:
in /usr/bin/ranger line 35,import ranger  # NOQA pylint: disable=import-self,wrong-import-position, have no module calls ranger 

`$ sudo pacman -S ranger` reinstall ranger, which can make its version lower than now

but still have some bugs in ranger, when i quit ranger, it always show The option named w3m_offset does not exist, The option named size_in_bytes does not exist

```shell
$ vim ~/.config/ranger/rc.conf
  annotate the following lines(about line 121)
#set w3m_offset 0 (about line 121)
#set size_in_bytes false (about line 301)
```

### alacrity:
when i open a new alacrity, it is always show [WARN] Config scrolling.faux_multiplier is deprecated; the alternate scroll escape can now be used to disable it and scrolling.multiplier controls the number of scrolled lines

```shell
$ vim ~/.config/alacrity/alacritty.yml
  annotate the following lines(about line 71)
  #scrolling:
  #  # Maximum number of lines in the scrollback buffer.
  #  # Specifying '0' will disable scrolling.
  #  history: 10000
  #
  #  # Number of lines the viewport will move for every line scrolled when
  #  # scrollback is enabled (history > 0).
  #  multiplier: 3
  #
  #  # Faux Scrolling
  #  #
  #  # The `faux_multiplier` setting controls the number of lines the terminal
  #  # should scroll when the alternate screen buffer is active. This is used
  #  # to allow mouse scrolling for applications like `man`.
  #  #
  #  # Specifying `0` will disable faux scrolling.
  #  faux_multiplier: 3
  #
  # Scroll to the bottom when new text is written to the terminal.
  auto_scroll: false
```


