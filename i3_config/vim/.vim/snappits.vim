autocmd Filetype markdown inoremap <Space><Space> <Esc>/<++><CR>:nohlsearch<CR>c4l
autocmd Filetype markdown inoremap ,n ---<Enter><Enter>
autocmd Filetype markdown inoremap ,, - **** <++><Esc>F*hi
autocmd Filetype markdown inoremap ,s ~~~~ <++><Esc>F~hi
autocmd Filetype markdown inoremap ,i ** <++> <Esc>F*i
autocmd Filetype markdown inoremap ,d `` <++> <Esc>F`i
autocmd Filetype markdown inoremap ,c ```<Enter><++><Enter>```<Enter><Enter><++><Esc>4kA
autocmd Filetype markdown inoremap ,h ====<Space><++><Esc>F=hi
autocmd Filetype markdown inoremap ,p ![](<++>) <++><Esc>F[a
autocmd Filetype markdown inoremap ,a [](<++>) <++><Esc>F[a
autocmd Filetype markdown inoremap ,1 #<Space><Enter><++><Esc>kA
autocmd Filetype markdown inoremap ,2 ##<Space><Enter><++><Esc>kA
autocmd Filetype markdown inoremap ,3 ###<Space><Enter><++><Esc>kA
autocmd Filetype markdown inoremap ,4 ####<Space><Enter><++><Esc>kA
autocmd Filetype markdown inoremap ,l --------<Enter>
autocmd Filetype markdown inoremap ,b <Tab>-<Space> <++> <Esc>F-la
autocmd Filetype markdown inoremap ( ()<ESC>i
autocmd Filetype markdown inoremap ) <Esc>a()<Esc>i

""autocmd Filetype markdown inoremap { {<CR>}<ESC>i
autocmd Filetype markdown inoremap ( (<++>) <++><Esc>/<++><CR>:nohlsearch<CR>c4l
autocmd Filetype markdown inoremap ) <Esc>a()<Esc>i
":inoremap { {<CR>}<ESC>i
autocmd Filetype markdown inoremap { {<++>} <++><Esc>/<++><CR>:nohlsearch<CR>c4l
autocmd Filetype markdown inoremap } <Esc>a{}<Esc>i
autocmd Filetype markdown inoremap [ [<++>] <++><Esc>/<++><CR>:nohlsearch<CR>c4l
autocmd Filetype markdown inoremap ] <Esc>a[]<Esc>i
autocmd Filetype markdown inoremap " "<++>" <++><Esc>/<++><CR>:nohlsearch<CR>c4l
autocmd Filetype markdown inoremap ' ''<ESC>i


