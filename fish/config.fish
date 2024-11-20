set fish_greeting ""

export XDG_CONFIG_HOME=$HOME/.config
#export PATH="$PATH:/home/sorria/.local/share/gem/ruby/3.2.0/bin"
#export QT_QPA_PLATFORM=wayland

# budspencer
# set budspencer_pwdstyle long
# set -U budspencer_cmdhist c d ll ls m s
# set budspencer_colors fffafa 666666 333333 fffafa 000000 ff6600 ff0000 ff0033 fffafa fffafa fffafa fffafa
# set -U fish_cursor_insert inclusive

# editor
export EDITOR="nvim"
export VISUAL="nvim"

# fcitx5
export GTK_IM_MODULE=fcitx
export QT_IM_MODULE=fcitx
export XMODIFIERS=@im=fcitx
export SDL_IM_MODULE=fcitx
export GLFW_IM_MODULE=ibus

# Clash
#export http_proxy=
#export http_proxy=http://127.0.0.1:8088
export http_proxy=http://127.0.0.1:65353
#export http_proxy=socks://175.178.160.167:1099
export https_proxy=$http_proxy
export ftp_proxy=$http_proxy
export rsync_proxy=$http_proxy
export no_proxy="localhost,127.0.0.1,localaddress,.localdomain.com"

# fish_vi_key_bindings
set -g fish_vi_force_cursor 1
set fish_cursor_insert line
set fish_cursor_replace_one underscore
set fish_cursor_replace underscore

# starship for fish
 starship init fish | source

function fish_greeting
    #bash ~/KittyCMDBar/startup.sh
    #pokemon-colorscripts -r --no-title
    set fish_cursor_insert inclusive
end

# wechat-uos-qt
#export trashAppUnsafe=1
#export isWeChatEnvPresent=1
#export wechatXserverPatch=1

# yazi
function y
	set tmp (mktemp -t "yazi-cwd.XXXXXX")
	yazi $argv --cwd-file="$tmp"
	if set cwd (command cat -- "$tmp"); and [ -n "$cwd" ]; and [ "$cwd" != "$PWD" ]
		builtin cd -- "$cwd"
	end
	rip "$tmp"
end
