function fzf --description alias\ fzf\ fzf\ --preview\ \'bat\ --color=always\ \{\}\'\ --preview-window\ \'\~3\'\ --height\ 50\%\ --border
 command fzf --preview 'bat --color=always {}' --preview-window '~3' --height 50% --border $argv
        
end
