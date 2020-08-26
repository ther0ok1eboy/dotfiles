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
"set clipboard+=unnamed



noremap K 5k    
noremap J 5j    
noremap q h
noremap e l
noremap <LEADER><CR> :nohlsearch<CR> 
"noremap z v
noremap X c<RIGHT>


"spelling check keyboard
map ck :set spell!<CR>
noremap ss [s
noremap s ]s
noremap mo ea<C-x>s<Esc>
inoremap <C-x> <Esc>ea<C-x>s

map W :w<CR>
map P :q!<CR>
map S :wq<CR>
map shell :r!
map rg :RnvimrToggle<CR>
" map os :w !sudo tee % <CR>

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

" make markdown notes become html
" map html :%TOhtml<CR>S

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
"":inoremap < <><ESC>i
"":inoremap > <Space><Esc>i<><ESC>i

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""new file tital:
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"first build the *.c, *.cpp, *.sh, *.sh and auto insert file headers
autocmd BufNewFile *.cpp,*.[ch],*.sh,*.java exec ":call SetTitle()"

func SetTitle()
    "shell:
    if &filetype == 'sh'
        call setline(1,"\#########################################################################")
        call append(line("."), "\# File Name: ".expand("%"))
        call append(line(".")+1, "\# Author: sorria")
        call append(line(".")+2, "\# mail: sorria1003@gmail.com")
        call append(line(".")+3, "\# Created Time: ".strftime("%c"))
        call append(line(".")+4, "\#########################################################################")
        call append(line(".")+5, "\#!/bin/bash")
        call append(line(".")+6, "")
    endif
    if &filetype == 'cpp'
        call append(line(".")+6, "#include<iostream>")
        call append(line(".")+7, "using namespace std;")
        call append(line(".")+8, "int main(int argc,char *argv[]){")
        call append(line(".")+9, "    ")
        call append(line(".")+10,"    return 0;")
        call append(line(".")+11, "}")
    endif
    if &filetype == 'c'
        call append(line(".")+6, "#include<stdio.h>")
        call append(line(".")+7, "int main(int argc,char *argv[]){")
        call append(line(".")+8, "    ")
        call append(line(".")+9,"    return 0;")
        call append(line(".")+10, "}")
    endif
        "after build the file, auto locate to file-tail
    autocmd BufNewFile * normal G
endfunc
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" ==================================Plugins==============================

call plug#begin('~/.config/nvim/plugged')
"Vim theme plugs
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'lervag/vimtex'
let g:airline_theme='simple'
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
"Plug 'liuchengxu/eleline.vim'
Plug 'makerj/vim-pdf'
let g:rehash256 = 1
let g:molokai_original = 1

" error checking 
" Plug 'w0rp/ale'

" File navigation
Plug 'scrooloose/nerdtree', { 'on': 'NERDTreeToggle' }
Plug 'Xuyuanp/nerdtree-git-plugin'
Plug 'jistr/vim-nerdtree-tabs'

" Taglist 
Plug 'majutsushi/tagbar', { 'on': 'TagbarOpenAutoClose' }
map T :Tagbar<CR>


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

" coc
Plug 'neoclide/coc.nvim', {'branch': 'release'}

" coc bash languageserver
"Plug 'autozimu/LanguageClient-neovim', {
"    \ 'branch': 'next',
"    \ 'do': 'bash install.sh',
"    \ }

" nerd commentater
Plug 'preservim/nerdcommenter'
noremap C \c

" ranger with flow window
Plug 'kevinhwang91/rnvimr', {'do': 'make sync'}

" Far.vim makes it easier to find and replace text through multiple files.
Plug 'brooth/far.vim'

let g:SnazzyTransparent = 1
"color snazzy

"let g:airline#extensions#tabline#enabled = 1

" Undo tree
Plug 'mbbill/undotree'

" vim startify
Plug 'mhinz/vim-startify'
    
" fzf
Plug 'junegunn/fzf', { 'dir': '~/.fzf', 'do': './install --all' }
Plug 'junegunn/fzf.vim'

call plug#end()

"colorscheme snazzy
colorscheme molokai


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
    exec "!firefox % &"
  elseif &filetype == 'markdown'
    exec "MarkdownPreview"
  elseif &filetype == 'vimwiki'
    exec "MarkdownPreview"
  endif
endfunc

" ===
" === Jekyll preview 
" ===
" Automatically browse your Jekyll article on web browsers.
map <F5> :term bash start-serve.sh

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
" When you with your md file you will see your contents on web browsers
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
" === coc-key-mapping
" ===
" It includes many useful language extensions.
" if hidden is not set, TextEdit might fail.
set hidden

" You will have bad experience for diagnostic messages when it's default 4000.
set updatetime=100

" don't give |ins-completion-menu| messages.
set shortmess+=c

" always show signcolumns
set signcolumn=yes

" Use tab for trigger completion with characters ahead and navigate.
" Use command ':verbose imap <tab>' to make sure tab is not mapped by other plugin.
inoremap <silent><expr> <TAB>
      \ pumvisible() ? "\<C-n>" :
      \ <SID>check_back_space() ? "\<TAB>" :
      \ coc#refresh()
inoremap <expr><S-TAB> pumvisible() ? "\<C-p>" : "\<C-h>"

function! s:check_back_space() abort
  let col = col('.') - 1
  return !col || getline('.')[col - 1]  =~# '\s'
endfunction

" Use <c-space> to trigger completion.
inoremap <silent><expr> <c-space> coc#refresh()

" Use <cr> to confirm completion, `<C-g>u` means break undo chain at current position.
" Coc only does snippet and additional edit on confirm.
inoremap <expr> <cr> pumvisible() ? "\<C-y>" : "\<C-g>u\<CR>"
" Or use `complete_info` if your vim support it, like:
" inoremap <expr> <cr> complete_info()["selected"] != "-1" ? "\<C-y>" : "\<C-g>u\<CR>"

"================ useful mapping ===========
" Use `[g` and `]g` to navigate diagnostics show debug error
nmap <silent> <LEADER>n <Plug>(coc-diagnostic-prev)
nmap <silent> <LEADER>m <Plug>(coc-diagnostic-next)

" Remap keys for gotos
nmap <silent> gd <Plug>(coc-definition)
nmap <silent> gy <Plug>(coc-type-definition)
nmap <silent> gi <Plug>(coc-implementation)
nmap <silent> gr <Plug>(coc-references)

" Remap for rename current word
nmap <leader>rn <Plug>(coc-rename)

"================ useful mapping ===========

" Use K to show documentation in preview window
"nnoremap <silent> K :call <SID>show_documentation()<CR>

function! s:show_documentation()
  if (index(['vim','help'], &filetype) >= 0)
    execute 'h '.expand('<cword>')
  else
    call CocAction('doHover')
  endif
endfunction

" Highlight symbol under cursor on CursorHold
autocmd CursorHold * silent call CocActionAsync('highlight')

" Remap for format selected region
xmap <leader>f  <Plug>(coc-format-selected)
nmap <leader>f  <Plug>(coc-format-selected)

augroup mygroup
  autocmd!
  " Setup formatexpr specified filetype(s).
  autocmd FileType typescript,json setl formatexpr=CocAction('formatSelected')
  " Update signature help on jump placeholder
  autocmd User CocJumpPlaceholder call CocActionAsync('showSignatureHelp')
augroup end

" Remap for do codeAction of selected region, ex: `<leader>aap` for current paragraph
xmap <leader>a  <Plug>(coc-codeaction-selected)
nmap <leader>a  <Plug>(coc-codeaction-selected)

" Remap for do codeAction of current line
nmap <leader>ac  <Plug>(coc-codeaction)
" Fix autofix problem of current line
nmap <leader>qf  <Plug>(coc-fix-current)

" Create mappings for function text object, requires document symbols feature of languageserver.
xmap if <Plug>(coc-funcobj-i)
xmap af <Plug>(coc-funcobj-a)
omap if <Plug>(coc-funcobj-i)
omap af <Plug>(coc-funcobj-a)

" Use <C-d> for select selections ranges, needs server support, like: coc-tsserver, coc-python
nmap <silent> <C-d> <Plug>(coc-range-select)
xmap <silent> <C-d> <Plug>(coc-range-select)

" Use `:Format` to format current buffer
command! -nargs=0 Format :call CocAction('format')
map cf :Fold<CR>
" Use `:Fold` to fold current buffer
command! -nargs=? Fold :call     CocAction('fold', <f-args>)

" use `:OR` for organize import of current buffer
command! -nargs=0 OR   :call     CocAction('runCommand', 'editor.action.organizeImport')

" Add status line support, for integration with other plugin, checkout `:h coc-status`
set statusline^=%{coc#status()}%{get(b:,'coc_current_function','')}

" Using CocList
" Show all diagnostics
nnoremap <silent> <space>a  :<C-u>CocList diagnostics<cr>
" Manage extensions
nnoremap <silent> <space>e  :<C-u>CocList extensions<cr>
" Show commands
nnoremap <silent> <space>c  :<C-u>CocList commands<cr>
" Find symbol of current document
nnoremap <silent> <space>o  :<C-u>CocList outline<cr>
" Search workspace symbols
nnoremap <silent> <space>s  :<C-u>CocList -I symbols<cr>
" Do default action for next item.
nnoremap <silent> <space>j  :<C-u>CocNext<CR>
" Do default action for previous item.
nnoremap <silent> <space>k  :<C-u>CocPrev<CR>
" Resume latest coc list
nnoremap <silent> <space>p  :<C-u>CocListResume<CR>

" fix the most annoying bug that coc has
silent! au BufEnter,BufRead,BufNewFile * silent! unmap if
let g:coc_global_extensions = ['coc-python', 'coc-vimlsp', 'coc-html', 'coc-json', 'coc-css', 'coc-tsserver', 'coc-yank', 'coc-lists', 'coc-gitignore', 'coc-vimlsp', 'coc-tailwindcss', 'coc-stylelint']
set statusline^=%{coc#status()}%{get(b:,'coc_current_function','')}
" use <tab> for trigger completion and navigate to the next complete item
function! s:check_back_space() abort
	let col = col('.') - 1
	return !col || getline('.')[col - 1]	=~ '\s'
endfunction
inoremap <silent><expr> <Tab>
			\ pumvisible() ? "\<C-n>" :
			\ <SID>check_back_space() ? "\<Tab>" :
			\ coc#refresh()
inoremap <expr> <S-Tab> pumvisible() ? "\<C-p>" : "\<S-Tab>"
inoremap <silent><expr> <c-space> coc#refresh()
" Useful commands
nnoremap <silent> <space>y :<C-u>CocList -A --normal yank<cr>
nmap <silent> gd <Plug>(coc-definition)
nmap <silent> gy <Plug>(coc-type-definition)
nmap <silent> gi <Plug>(coc-implementation)
nmap <silent> gr <Plug>(coc-references)
nmap <leader>rn <Plug>(coc-rename)

" ===
" === fastfold (some function have been replace by COC)
" ===

"noremap <silent> <LEADER>o zo
"
"nmap zuz <Plug>(FastFoldUpdate)
"let g:fastfold_savehook = 1
"let g:fastfold_fold_command_suffixes =  ['x','X','a','A','o','O','c','C']
"let g:fastfold_fold_movement_commands = [']z', '[z', 'ze', 'zu']
"
"let g:markdown_folding = 1
"let g:tex_fold_enabled = 1
"let g:vimsyn_folding = 'af'
"let g:xml_syntax_folding = 1
"let g:javaScript_fold = 1
"let g:sh_fold_enabled= 7
"let g:ruby_fold = 1
"let g:perl_fold = 1
"let g:perl_fold_blocks = 1
"let g:r_syntax_folding = 1
"let g:rust_fold = 1
"let g:php_folding = 1

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
" === coc bash languageserver
" ===
"let g:LanguageClient_serverCommands = {
"    \ 'sh': ['bash-language-server', 'start']
"    \ }
"
"
"Markers
"
"Every change has a sequence number and it is displayed before timestamps.
"The current state is marked as > number <.
"The next state which will be restored by :redo or <ctrl-r> is marked as { number }.
"The [ number ] marks the most recent change.
"The undo history is sorted by timestamps.
"Saved changes are marked as s and the big S indicates the most recent saved change.
"

" ===
" === FZF
" ===

map ff :FZF<CR>
