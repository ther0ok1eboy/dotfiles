" __     _____ __  __ ____   ____    ____ ___  _   _ _____ ___ ____
" \ \   / /_ _|  \/  |  _ \ / ___|  / ___/ _ \| \ | |  ___|_ _/ ___|
"  \ \ / / | || |\/| | |_) | |     | |  | | | |  \| | |_   | | |  _
"   \ V /  | || |  | |  _ <| |___  | |__| |_| | |\  |  _|  | | |_| |
"    \_/  |___|_|  |_|_| \_\\____|  \____\___/|_| \_|_|   |___\____|
"

" ==================================Editor behavior==============================

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

set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8

set relativenumber
set number
set mouse=a
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
"set foldmethod=indent
set foldlevel=99
set foldenable
set viewoptions=cursor,folds,slash,unix
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
set clipboard=unnamedplus

" ==================================key binds==============================

noremap K 5k    
noremap J 5j    
noremap q h
noremap e l
noremap <LEADER><CR> :nohlsearch<CR> 

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
map rg :RnvimrToggle<CR>
map os :sudaWrite <CR>

" spilling vim windos
map sl :set splitright<CR>:vsplit<CR>
map sh :set nosplitright<CR>:vsplit<CR>
map sj :set nosplitbelow<CR>:vsplit<CR>
map sk :set splitbelow<CR>:vsplit<CR>
" focus or resize the vim window
map dk <C-w>l
map dj <C-w>h
map <LEADER><left> :vertical resize-5<CR>
map <LEADER><right> :vertical resize+5<CR>

" create a new vim window and focus
map so :tabe<CR>
map sJ :-tabnext<CR>
map sK :+tabnext<CR>

"Ctrl+a
map <C-A> ggVGY
map! <C-A> <Esc>ggVGY
map <F12> gg=G
"Ctrl+c
vmap <C-c> "+y

" press space twice to jump next <++>
map <LEADER><LEADER> <Esc>/<++><CR>:nohlsearch<CR>c4l

"some useful function
:inoremap ( (<++>) <Esc>/<++><CR>:nohlsearch<CR>c4l
:inoremap ) <Esc>a()<Esc>i
:inoremap { {<CR><++><CR>} <Esc>/<++><CR>:nohlsearch<CR>c4l
:inoremap } <Esc>a{}<Esc>i
:inoremap [ [<++>] <Esc>/<++><CR>:nohlsearch<CR>c4l
:inoremap ] <Esc>a[]<Esc>i
":inoremap " ""<++>""<++><Esc>/"<++>"<CR>:nohlsearch<CR>c6l
:inoremap ' ''<ESC>i

" ==================================Plugins==============================

call plug#begin('~/.config/nvim/plugged')

" Vim theme plugs
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'lervag/vimtex'
let g:airline_theme='violet'
let g:airline_powerline_fonts               = 1
let g:airline#extensions#branch#enabled     = 1
let g:airline#extensions#syntastic#enabled  = 1
let g:airline_detect_paste                  = 1
let g:airline#extensions#whitespace#enabled = 1
let g:airline_detect_modified               = 1
let g:airline#extensions#tagbar#enabled     = 1
let g:airline#extensions#tagbar#flags       = 'p'

Plug 'connorholyday/vim-snazzy'
Plug 'tomasr/molokai'
Plug 'altercation/vim-colors-solarized'
let g:solarized_termcolors = 256
let g:solarized_termtrans  = 1
let g:solarized_contrast   = "normal"
let g:solarized_visibility = "low"

Plug 'bling/vim-bufferline'
" Plug 'liuchengxu/eleline.vim'
Plug 'makerj/vim-pdf'
let g:rehash256 = 1
let g:molokai_original = 1

" File navigation
Plug 'scrooloose/nerdtree', { 'on': 'NERDTreeToggle' }
Plug 'Xuyuanp/nerdtree-git-plugin'
Plug 'jistr/vim-nerdtree-tabs'

" Taglist 
Plug 'majutsushi/tagbar', { 'on': 'TagbarOpenAutoClose' }
map T :Tagbar<CR>


" Markdown
Plug 'dhruvasagar/vim-table-mode', { 'on': 'TableModeToggle', 'for': ['text', 'markdown', 'vim-plug'] }
Plug 'ryanoasis/vim-devicons'
Plug 'instant-markdown/vim-instant-markdown', {'for': 'markdown', 'do': 'yarn install'}

" Bookmarks
Plug 'kshenoy/vim-signature'

" Dependencies
Plug 'MarcWeber/vim-addon-mw-utils'
Plug 'kana/vim-textobj-user'
Plug 'fadein/vim-FIGlet'

" nerd commentater
Plug 'preservim/nerdcommenter'
noremap C \c

" ranger with flow window
Plug 'kevinhwang91/rnvimr', {'do': 'make sync'}

" Far.vim makes it easier to find and replace text through multiple files.
Plug 'brooth/far.vim'

let g:SnazzyTransparent = 1

" Undo tree
Plug 'mbbill/undotree'

" vim startify
Plug 'mhinz/vim-startify'
    
" fzf
Plug 'junegunn/fzf', { 'dir': '~/.fzf', 'do': './install --all' }
Plug 'junegunn/fzf.vim'

" vim table mode
Plug 'dhruvasagar/vim-table-mode', { 'on': 'TableModeToggle', 'for': ['text', 'markdown', 'vim-plug'] }

" save file with root permission (map as the key os)
Plug 'lambdalisue/suda.vim'

call plug#end()

colorscheme snazzy

" Compile function
map run :call CompileRunGcc()<CR>
func! CompileRunGcc()
  exec "w"
  if &filetype == 'c'
    exec "!g++ % -o %<"
    exec "! ./%<"
  elseif &filetype == 'sh'
    :! bash %
  elseif &filetype == 'python'
    silent! exec "!clear"
    exec "!time python3 %"
  elseif &filetype == 'html'
    exec "!firefox % &"
  elseif &filetype == 'markdown'
    exec "InstantMarkdownPreview"
  endif
endfunc

" ==================================plug behavior==============================

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
let NERDTreeShowLineNumbers=1
let NERDTreeShowHidden=1
let NERDTreeWinSize=25
" automatically startup NERDTree when open a file using nvim then focus the file instead of nerdtree toggle.
autocmd vimenter * NERDTree
autocmd vimenter * NERDTreeFocusToggle
let g:nerdtree_tabs_smart_startup_focus=2
" automatically startup NERDTree when open a directory using nvim
autocmd StdinReadPre * let s:std_in=1
autocmd VimEnter * if argc() == 1 && isdirectory(argv()[0]) && !exists("s:std_in") | exe 'NERDTree' argv()[0] | wincmd p | ene | exe 'cd '.argv()[0] | endif

" ==
" == NERDTree-git
" ==
" It will show some statuses of file which is github repository using some icons like following that
let g:NERDTreeGitStatusIndicatorMapCustom = {
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
" === vim instant markdown
" ===
let g:instant_markdown_slow = 0
let g:instant_markdown_autostart = 0
let g:instant_markdown_autoscroll = 1

" ===
" === some keys
" ===
source ~/.config/nvim/snappits.vim

" ===
" === vim-table-mode
" ===
" It will automatically full up md syntax of table.
map <LEADER>tm :TableModeToggle<CR>

" ===
" === Far.vim
" ===
noremap <LEADER>f :F  %<left><left>
"set lazyredraw            " improve scrolling performance when navigating through large results
"set regexpengine=1        " use old regexp engine
"set ignorecase smartcase  " ignore case only when the pattern contains no capital letters
"" shortcut for far.vim find
"nnoremap <silent> <Find-Shortcut>  :Farf<cr>
"vnoremap <silent> <Find-Shortcut>  :Farf<cr>
"" shortcut for far.vim replace
"nnoremap <silent> <Replace-Shortcut>  :Farr<cr>
"vnoremap <silent> <Replace-Shortcut>  :Farr<cr>

" ===
" === Undotree
" ===
noremap L :UndotreeToggle<CR>
let g:undotree_DiffAutoOpen = 1
let g:undotree_SetFocusWhenToggle = 1
let g:undotree_ShortIndicators = 1
let g:undotree_WindowLayout = 2
let g:undotree_DiffpanelHeight = 8
let g:undotree_SplitWidth = 24
function g:Undotree_CustomMap()
	nmap <buffer> u <plug>UndotreeNextState
	nmap <buffer> e <plug>UndotreePreviousState
	nmap <buffer> U 5<plug>UndotreeNextState
	nmap <buffer> E 5<plug>UndotreePreviousState
endfunc

" ===
" === FZF
" ===
map ff :FZF<CR>

" ===
" === vim table mode
" ===
noremap <LEADER>vtm :TableModeToggle<CR>
let g:table_mode_corner='|'


