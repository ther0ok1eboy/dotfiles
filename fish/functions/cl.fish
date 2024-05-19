function cl --wraps='clear; echo; echo; seq 1 $(tput cols) | sort -R | spark | lolcat; echo; echo' --description 'alias cl=clear; echo; echo; seq 1 $(tput cols) | sort -R | spark | lolcat; echo; echo'
  clear; echo; echo; seq 1 $(tput cols) | sort -R | spark | lolcat; echo; echo $argv
        
end
