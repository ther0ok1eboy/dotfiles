# some useful applications

$ sudo pacman-mirrors -c China
$ sudo pacman -Syyu

**安装teamviewer**

$ sudo pacman -S teamviewer
$ sudo nano /opt/teamviewer/tv_bin/desktop/com.teamviewer.TeamViewer.desktop
Exec=/bin/sudo /opt/teamviewer/tv_bin/script/teamviewer passwd 123456

**网易云音乐**

$ sudo pacman -S netease-cloud-music vlc
$ sudo nano /usr/share/applications/netease-cloud-music.desktop
Exec=/opt/netease/netease-cloud-music/netease-cloud-music %U

**腾讯TIM**

$ sudo pacman -S deepin.com.qq.office
    add the following in your /etc/pacman.conf
    [archlinuxcn]
    SigLevel = Never
    Server = http://mirrors.tuna.tsinghua.edu.cn/archlinuxcn/$arch
$sudo pacman Syu
$sudo pacman -S gnome-settings-daemon
exc=/usr/lib/gsd-xsettings then start tim

**redshift: 护眼工具，需要额外配置**

**wqy-microhei : 开源免费的中文字体**

**git : 下载github代码工具**

**wget : 命令行下载工具，支持http，ftp**

**vim : 很好用的编辑器**

zsh : 终端美化，主题可以到 ohmyz.sh 去看

exfat-utils :支持exfat格式的包

gvfs-mtp : 能够挂载安卓手机

bluez和bluez-utils:蓝牙模块包

firefox, firefox-i18n-zh-cn: 火狐浏览器及简体中文包

**google-chrome : 谷歌浏览器**

**deepin.com.qq.im[deepin-wine] : 腾讯QQ**

**screenfetch ： 装逼神器**

**neofetch ： 装逼神器**

**lolcat : 彩虹装逼神器，结合screenfetch或者neofetch使用**

file-roller : 桌面GUI解压软件

unarchiver : 命令行解压，支持unar、lsar命令

p7zip : 非常流行的解压工具

kchmviewer : chm文件阅读器

evince : 支持PDF, Postscript, djvu, tiff, dvi, XPS, SyncTex support with gedit, comics books (cbr,cbz,cb7 and cbt)

deepin-calculator : deepin的计算器

flameshot : 火焰截图，强大又易用的屏幕截图软件

deepin-screenshot : deepin截图

deepin-picker : deepin取色器

deepin-screen-recorder : deepin录屏

deepin-movie : deepin视频播放器

vlc：一款强大开源的全平台播放器

xmind-zen : 思维导图

wps-office : 中文办公软件WPS

ttf-wps-fonts：中文办公软件WPS的字体包, 安装WPS必须安装的包

krita : photoshop的替代, Krita 是一款自由、免费、开源的专业绘画软件。

gimp：photoshop的替代品, GIMP 是自由、免费、开源的。

baidupcs-go：百度网盘-命令行版

uget : aria2下载工具，需要再设置里面调成aria2。

baidunetdisk-bin[aur] : 百度网盘

browser360[aur] : 360浏览器

360zip[aur] : 360压缩

mitalk[aur] ： 米聊，强大的全平台聊天软件

jmtpfs[aur] : 挂载手机的包，jmtpfs /路径和fusermount -u /路径

其他软件
dmidecode: 可以查看部分硬件信息
sudo dmidecode -t memory           #查看内存条信息 
1
开发工具
postman-bin：api测试工具

visual-studio-code-bin：vscode

android-tools：安卓调试工具，adb

jetbrains-toolbox[aur] : jetbrains家族软件的管理工具

**wechat-devtools [aur]: 微信开发者工具**

another-redis-desktop-manager [aur]: redis管理工具

