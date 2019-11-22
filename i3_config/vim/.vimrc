" __     _____ __  __ ____   ____    ____ ___  _   _ _____ ___ ____ 
" \ \   / /_ _|  \/  |  _ \ / ___|  / ___/ _ \| \ | |  ___|_ _/ ___|
"  \ \ / / | || |\/| | |_) | |     | |  | | | |  \| | |_   | | |  _ 
"   \ V /  | || |  | |  _ <| |___  | |__| |_| | |\  |  _|  | | |_| |
"    \_/  |___|_|  |_|_| \_\\____|  \____\___/|_| \_|_|   |___\____|
"                                                                   
" 

" ===
" === Auto load for first time uses
" ===
if empty(glob('/home/sorria/.vim/autoload/plug.vim'))
" if empty(glob('~/.vim/autoload/plug.vim'))
  silent !curl -fLo ~/.vim/autoload/plug.vim --create-dirs
    \ https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
  autocmd VimEnter * PlugInstall --sync | source $MYVIMRC
endif

let mapleader=" "
let g:SnazzyTransparent = 1
let g:lightline = {
\ 'colorscheme': 'snazzy',
\ }
let &t_SI = "\<Esc>]50;CursorShape=1\x7"
let &t_SR = "\<Esc>]50;CursorShape=2\x7"
let &t_EI = "\<Esc>]50;CursorShape=0\x7"

filetype on
filetype indent on
filetype plugin on
filetype plugin indent on

set number
set mouse=a
set encoding=utf-8
let &t_ut=''
set expandtab
set tabstop=4	
set shiftwidth=4
set softtabstop=4
set list
set listchars=tab:▸\ ,trail:▫
set scrolloff=7
set tw=0
set indentexpr=
set backspace=indent,eol,start
set foldmethod=indent
set foldlevel=99
set laststatus=2
set autochdir
au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
set nocompatible
set number
set cursorline
syntax on 
set wrap        
set wildmenu   
set showcmd
set incsearch   
set hlsearch    
set ignorecase  
set clipboard+=unnamed



noremap k 5k    
noremap j 5j    
noremap <LEADER><CR> :nohlsearch<CR> 
noremap z v
"spelling check keyboard
map ck :set spell!<CR>
noremap ss [s
noremap s ]s
noremap mo ea<C-x>s<Esc>
inoremap <C-x> <Esc>ea<C-x>s

map W :w<CR>
map Q :q!<CR>
map S :wq<CR>
map shell :r!
map os :w !sudo tee %<CR>

" spilling vim windos
map sl :set splitright<CR>:vsplit<CR>
map sh :set nosplitright<CR>:vsplit<CR>
map sj :set nosplitbelow<CR>:vsplit<CR>
map sk :set splitbelow<CR>:vsplit<CR>
" focus or resize the vim window
map <LEADER>k <C-w>l
map <LEADER>j <C-w>h
map <LEADER><left> :vertical resize-5<CR>
map <LEADER><right> :vertical resize+5<CR>

" create a new vim window and focus
map so :tabe<CR>
map sj :-tabnext<CR>
map sk :+tabnext<CR>

"Ctrl+a
map <C-A> ggVGY
map! <C-A> <Esc>ggVGY
map <F12> gg=G
"Ctrl+c
vmap <C-c> "+y

" make markdown notes become html
" map html :%TOhtml<CR>S

" press space twice to jump next <++>
map <LEADER><LEADER> <Esc>/<++><CR>:nohlsearch<CR>c4l

"some useful function
:inoremap ( ()<ESC>i
:inoremap ) <Esc>i()<Esc>i
:inoremap { {<CR>}<ESC>O
:inoremap } <Esc>i{}<Esc>i
:inoremap [ []<ESC>i
:inoremap ] <Esc>i[]<Esc>i
:inoremap " ""<ESC>i
:inoremap ' ''<ESC>i
:inoremap < <><ESC>i
:inoremap > <Space><Esc>i<><ESC>i

"shell:
:inoremap ,sh #!/bin/bash<CR><CR>
"C/C++:
:inoremap ,cc #include <stdio.h><CR>#include <stdlib.h><CR><CR>
:inoremap ,cpp #include <iostream><CR><RC>using namespace std;<CR><CR>
:inoremap ,ma int main(int args, char *argv[]){<CR><Tab><++>return 0;<CR>}<Esc>/<++><CR>:nohlsearch<CR>c4l<CR><UP>



"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""new file tital:
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"first build the *.c, *.cpp, *.sh, *.sh and auto insert file headers
""autocmd BufNewFile *.cpp,*.[ch],*.sh,*.java exec ":call SetTitle()"
""
""func SetTitle()
""    "shell:
""    if &filetype == 'sh'
""        call setline(1,"\#########################################################################")
""        call append(line("."), "\# File Name: ".expand("%"))
""        call append(line(".")+1, "\# Author: sorria")
""        call append(line(".")+2, "\# mail: sorria1003@gmail.com")
""        call append(line(".")+3, "\# Created Time: ".strftime("%c"))
""        call append(line(".")+4, "\#########################################################################")
""        call append(line(".")+5, "\#!/bin/bash")
""        call append(line(".")+6, "")
""    else
""        call setline(1, "/*************************************************************************")
""        call append(line("."), "    > File Name: ".expand("%"))
""        call append(line(".")+1, "    > Author: sorria")
""        call append(line(".")+2, "    > Mail: sorria1003@gmail.com")
""        call append(line(".")+3, "    > Created Time: ".strftime("%c"))
""        call append(line(".")+4, " ************************************************************************/")
""        call append(line(".")+5, "")
""    endif
""    if &filetype == 'cpp'
""        call append(line(".")+6, "#include<iostream>")
""        call append(line(".")+7, "using namespace std;")
""        call append(line(".")+8, "int main(int argc,char *argv[]){")
""        call append(line(".")+9, "    ")
""        call append(line(".")+10,"    return 0;")
""        call append(line(".")+11, "}")
""    endif
""    if &filetype == 'c'
""        call append(line(".")+6, "#include<stdio.h>")
""        call append(line(".")+7, "int main(int argc,char *argv[]){")
""        call append(line(".")+8, "    ")
""        call append(line(".")+9,"    return 0;")
""        call append(line(".")+10, "}")
""    endif
""    "    if &filetype == 'java'
""    "        call append(line(".")+6,"public class ".expand("%"))
""    "        call append(line(".")+7,"")
""    "    endif
""    "after build the file, auto locate to file-tail
""    autocmd BufNewFile * normal G
""endfunc
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" ==================================Plugins==============================

call plug#begin('/home/sorria/.vim/plugged')
Plug 'vim-airline/vim-airline'
Plug 'connorholyday/vim-snazzy'
Plug 'bling/vim-bufferline'

" error checking 
" Plug 'w0rp/ale'

" File navigation
Plug 'scrooloose/nerdtree', { 'on': 'NERDTreeToggle' }
Plug 'Xuyuanp/nerdtree-git-plugin'

" Taglist 
Plug 'majutsushi/tagbar', { 'on': 'TagbarOpenAutoClose' }

" Markdown
Plug 'iamcco/markdown-preview.nvim', { 'do': { -> mkdp#util#install_sync() }, 'for' :['markdown', 'vim-plug'] }
Plug 'dhruvasagar/vim-table-mode', { 'on': 'TableModeToggle' }
Plug 'vimwiki/vimwiki'

" Bookmarks
Plug 'kshenoy/vim-signature'


" Dependencies
Plug 'MarcWeber/vim-addon-mw-utils'
Plug 'kana/vim-textobj-user'
Plug 'fadein/vim-FIGlet'

call plug#end()

let g:SnazzyTransparent = 1
color snazzy

call plug#end()

colorscheme snazzy


" Compile function
map run :call CompileRunGcc()<CR>
func! CompileRunGcc()
  exec "w"
  if &filetype == 'c'
    exec "!g++ % -o %<"
    exec "! ./%<"
  elseif &filetype == 'cpp'
    exec "!g++ % -o %<"
    exec "! ./%<"
  elseif &filetype == 'java'
    exec "!javac %"
    exec "!time java %<"
  elseif &filetype == 'sh'
    :! bash %
  elseif &filetype == 'python'
    silent! exec "!clear"
    exec "!time python3 %"
  elseif &filetype == 'html'
    exec "!google-chrome-stable % &"
  elseif &filetype == 'markdown'
    exec "MarkdownPreview"
  elseif &filetype == 'vimwiki'
    exec "MarkdownPreview"
  endif
endfunc


" ===
" === NERDTree
" ===
map tt :NERDTreeToggle<CR>
let NERDTreeMapOpenExpl = ""
let NERDTreeMapUpdir = ""
let NERDTreeMapUpdirKeepOpen = "l"
let NERDTreeMapOpenSplit = ""
let NERDTreeOpenVSplit = ""
let NERDTreeMapActivateNode = "i"
let NERDTreeMapOpenInTab = "o"
let NERDTreeMapPreview = ""
let NERDTreeMapCloseDir = "n"
let NERDTreeMapChangeRoot = "y"


" ==
" == NERDTree-git
" ==
let g:NERDTreeIndicatorMapCustom = {
    \ "Modified"  : "✹",
    \ "Staged"    : "✚",
    \ "Untracked" : "✭",
    \ "Renamed"   : "➜",
    \ "Unmerged"  : "═",
    \ "Deleted"   : "✖",
    \ "Dirty"     : "✗",
    \ "Clean"     : "✔︎",
    \ "Unknown"   : "?"
    \ }


" ===
" === MarkdownPreview
" ===
let g:mkdp_auto_start = 0
let g:mkdp_auto_close = 1
let g:mkdp_refresh_slow = 0
let g:mkdp_command_for_global = 0
let g:mkdp_open_to_the_world = 0
let g:mkdp_open_ip = ''
let g:mkdp_browser = 'google-chrome-stable'
let g:mkdp_echo_preview_url = 0
let g:mkdp_browserfunc = ''
let g:mkdp_preview_options = {
    \ 'mkit': {},
    \ 'katex': {},
    \ 'uml': {},
    \ 'maid': {},
    \ 'disable_sync_scroll': 0,
    \ 'sync_scroll_type': 'middle',
    \ 'hide_yaml_meta': 1
    \ }
let g:mkdp_markdown_css = ''
let g:mkdp_highlight_css = ''
let g:mkdp_port = ''
let g:mkdp_page_title = '「${name}」'
source ~/.vim/snappits.vim


" ===
" === vim-table-mode
" ===
map <LEADER>tm :TableModeToggle<CR>

