1 install ranger: 
	pacman -S ranger && ranger --copy-config=all && vim $HOME/.config/ranger/rc.conf
2 if you want ranger to excest you config:
	input 'set -g -x RANGER_LOAD_DEFAULT_RC=FALSE' in ~/.config/fish/config.fish
3 some seting of rc.conf
	input 'set draw_borders true' 'set vcs_awere ture' 'set preview_images_mothed w3m' 'set preview_iamges true'in your rc.conf
4 show the icons of files under ranger:
	cd ~/.config/ranger && mkdir plugins && cd flugins && git clone https://github.com/alexanderjeurissen/ranger_devicons && make insatll then input 'default_linemode devicons' in your rc.conf
5 if you want to change your ranger colorscheme
	set colorscheme 'the colorscheme you like' in your rc.conf
