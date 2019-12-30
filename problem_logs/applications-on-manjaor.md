---
layout: post
title: Some applications on manjaro linux
date: 2019-12-22 
tags: linux   
---

### Update system source

```shell
$ sudo pacman-mirrors -c China
$ sudo pacman -Syyu
```
**Teamviewer: GUI remote tool**

```shell
$ sudo pacman -S teamviewer
$ sudo vim /opt/teamviewer/tv_bin/desktop/com.teamviewer.TeamViewer.desktop
# modify this line: 
# Execute=/bin/sudo /opt/teamviewer/tv_bin/script/teamviewer passwd 123456
```
**Netease cloud music**

```shell
$ sudo pacman -S netease-cloud-music vlc
$ sudo vim /usr/share/applications/netease-cloud-music.desktop
# modify this line:
# Execute=/opt/netease/netease-cloud-music/netease-cloud-music %U
```

**TIM**

```shell
$ sudo pacman -S deepin.com.qq.office
# add the following lines in your /etc/pacman.conf
$ vim /etc/pacman.conf

[archlinuxcn]
SigLevel = Never
Server = http://mirrors.tuna.tsinghua.edu.cn/archlinuxcn/$arch

$sudo pacman Syu
$sudo pacman -S gnome-settings-daemon
# excute=/usr/lib/gsd-xsettings //it will became a daemon process hanging out your system
# open your pamc or other application managements to run tim
```
**redshift:** a tool for protecting your eyes, but it needs ro extra configuration.

**wqy-microhei:** a open source Chinese font for free.

**git:** a tool for downloading github code and you need to study its some syntax.

**wget:** a download tool for CLI supporting http，ftp.

**vim:** a very powerful editor and you can go my [github](https://github.com/JasonSorria/manjaro_pro) to see more information about my configuration of vimrc.

**zsh:** beautify terminal and you can go [ahmyz.sh](ahmyz.sh) to find more theme.(but i recommend you to use fish)

**exfat-utils:** a package support exfat.

**gvfs-mtp:** it can mount Android phone.

**bluez和bluez-utils:** blue tooth model package.

**firefox, firefox-i18n-zh-cn:** firefox and its Chinese install package.

**google-chrome:** Google browser.

**deepin.com.qq.im [deepin-wine]:** it is similar with QQ.

**screenfetch:** a funny tool.

**neofetch:** a funny tool.

**lolcat:** a fucking funny tool and if you use it with screenfetch or neofetch you will get more surprise.

**file-roller:** desktop GUI unzip tool.

**unarchiver:** use CLI to unzip and support command of unar、lsar

**p7zip:** a very popular unzip tool.

**kchmviewer:** chm file browser management.

**evince:** support PDF, Postscript, djvu, tiff, dvi, XPS, SyncTex support with gedit, comics books (cbr,cbz,cb7 and cbt)

**deepin-calculator:** deepin version calculator.

**flameshot:** a powerful and easy to use tool for screen shuter.

**deepin-screenshot:** deepin screen shuter.

**deepin-picker: **a tool for take colors.

**deepin-screen-recorder:** deepin record screen tool.

**deepin-movie:** deepin video palyer.

**vlc:** a powerful open source video palyer for all platform.

**xmind-zen:** mind mapping.

**wps-office:** Chinese version of office WPS.

**ttf-wps-fonts:** Chinese font package of WPS office, which is you must to install if you want to install WPS.

**krita:** the alternative of photoshop, Krita is professional painting tool for free and open source.

**gimp:**  the alternative of photoshop, GIMP is free, open source and freedom.

**baidupcs-go:** CLI version of baidu pan download.

**uget:** aria2download tool, need to configure.

**baidunetdisk-bin [aur]:** baidu pan disk.

**browser360[aur]:** 360browser.

**360zip [aur]:** 360zip.

**mitalk [aur]:** a powerful chat application on any platform.

**jmtpfs [aur]:** mount phone package.

```shell
$ jmtpfs /path
$ fusermount -u /path
```

# Another applications:

**dmidecode:** it can show some information of hardware.

> $ sudo dmidecode -t memory // show memory information.

### Development tools:

**postman-bin:** api test tool.

**visual-studio-code-bin:** vscode.

**android-tools:** android debug tool.

**jetbrains-toolbox [aur] :** jetbrains family software management tools.

**wechat-devtools [aur]**

**another-redis-desktop-manager [aur]:** redis management tool.

