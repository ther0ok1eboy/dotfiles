# Defined in /usr/share/fish/functions/ls.fish @ line 6
function ls --description 'List contents of directory'
	set -l param --color=auto
        if isatty 1
            set -a param --indicator-style=classify
        end
        command ls $param $argv
end
