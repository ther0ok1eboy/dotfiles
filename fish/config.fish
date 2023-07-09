set fish_greeting ""

export XDG_CONFIG_HOME=$HOME/.config

# budspencer
# set budspencer_pwdstyle long
# set -U budspencer_cmdhist c d ll ls m s
# set budspencer_colors fffafa 666666 333333 fffafa 000000 ff6600 ff0000 ff0033 fffafa fffafa fffafa fffafa

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
export http_proxy=http://127.0.0.1:7890
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
# starship init fish | source

# pokemon-colorscripts
function fish_greeting
     pokemon-colorscripts -r --no-title
end

