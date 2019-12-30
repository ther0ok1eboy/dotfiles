### 介绍

随着Linux用户的不断增长，我们不可避免地要使用vim，而代码也成为了vim编辑的一个普遍现象。所以我想您一定对vim感到厌烦了，并且总是问为什么vim没有完成代码。我也相信你已经安装或尝试一些代码完成插件。否则你找不到这篇文章。今天，我将分享一个功能强大、易于使用的插件COC。
> 效果:

![](1.gif)


--------


### 什么是COC插件
Coc是一个用于Vim/Neovim.True代码段和其他文本编辑支持的intellisense引擎。查看vim接口的Wiki。它支持float窗口，可以方便地浏览您定义的函数。与YCM插件相比，COC插件更小，更易于安装。最重要的原因是，COC作为一个插件，它支持添加许多语言插件，如C/C++，这是支持代码完成，并看到更多的wiki获得更多的细节。它有许多功能，如：
- 快速：即时增量完成，使用缓冲区更新事件增量缓冲区同步。
- 可靠：打字语言，用CI测试。
- 特色：完全支持LSP
- 灵活：配置像VSCode，扩展工作就像在VSCode
### 快速启动

### 要求

`neovim` >= 0.3.1 is required.

`vim` >= 8.0.1453 is required.

Use command `:version` or `$ vim --version` to checkout your vim version.

--------

### 安装

`$ sudo pacman -S neovim`, 果您是neovim用户，可以忽略它。除了您的所有vim配置和vim插头外，neovim将完全支持它。

`$ nvim file-name` to edit your file. 


neovim的本地配置主页是~/.config/nvim如果您没有这个目录，可以在安装后手动添加它。关于neovim的另一件事是，您将发现您没有neovim的配置文件，因此$cd~/.config/nvim&&nvim init.vim和init.vim是您的neovim的配置文件，如.vimrc。只需将.vimrc复制到~/.config/nvim和mv.vimrc init.vim中。

当您将vim的配置文件复制到~/.config/nvim中时，您需要再次安装PluginInstall。如果忘记了如何安装插件，可以看到他的[github](https://github.com/junegunn/vim-plug)或我的以下配置文件内容：

```vim
$ nvim ~/.config/nvim/init.vim
# add the following lines into it.
----
if empty(glob('~/.config/nvim/autoload/plug.vim'))
        silent !curl -fLo ~/.config/nvim/autoload/plug.vim --create-dirs
                                \ https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
        autocmd VimEnter * PlugInstall --sync | source $MYVIMRC
endif
----
# it will auto loading Pluginstall manager
```
`$ nvim` you will see that: 

![](1.png)

--------

### 添加COC插件

如果你不愿意阅读这篇文章，你可以参考这个[文件](https://github.com/neoclide/coc.nvim)，这是一个官方文件有更多的细节。

必要时安装nodejs和pyneovim：

```vim
curl -sL install-node.now.sh/lts | bash
pip3 install neovim
npm install -g neovim
----
# Install nerd-fonts (actually it’s optional but it looks real good)
```

Add the following line into `init.vim`.

```vim
Plug 'neoclide/coc.nvim', {'branch': 'release'} 
----
# run `:PlugIinstall` to load this plugin. 
```
一些vim插件可以更改keymapping。使用类似于：verbose imap的命令来确保keymap已经生效。

再次将以下行添加到init.vim中。不要只抄这几行，你至少需要读一些解释

```vim
" if hidden is not set, TextEdit might fail.
set hidden

" Some servers have issues with backup files, see #649
set nobackup
set nowritebackup

" Better display for messages
set cmdheight=2

" You will have bad experience for diagnostic messages when it's default 4000.
set updatetime=300

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

" Use `[g` and `]g` to navigate diagnostics
nmap <silent> [g <Plug>(coc-diagnostic-prev)
nmap <silent> ]g <Plug>(coc-diagnostic-next)

" Remap keys for gotos
nmap <silent> gd <Plug>(coc-definition)
nmap <silent> gy <Plug>(coc-type-definition)
nmap <silent> gi <Plug>(coc-implementation)
nmap <silent> gr <Plug>(coc-references)

" Use K to show documentation in preview window
nnoremap <silent> K :call <SID>show_documentation()<CR>

function! s:show_documentation()
  if (index(['vim','help'], &filetype) >= 0)
    execute 'h '.expand('<cword>')
  else
    call CocAction('doHover')
  endif
endfunction

" Highlight symbol under cursor on CursorHold
autocmd CursorHold * silent call CocActionAsync('highlight')

" Remap for rename current word
nmap <leader>rn <Plug>(coc-rename)

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

" Use <TAB> for select selections ranges, needs server support, like: coc-tsserver, coc-python
nmap <silent> <TAB> <Plug>(coc-range-select)
xmap <silent> <TAB> <Plug>(coc-range-select)

" Use `:Format` to format current buffer
command! -nargs=0 Format :call CocAction('format')

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
```
**之后你仍然没有完成代码的功能**



### 添加语言服务器

你可以查看它的[官方文件](https://github.com/neoclide/coc.nvim/wiki/Language-servers)以获取更多信息。

--------

```json
{
	"yank.enableCompletion" : false,
	"diagnostic.virtualText": true,
	"codeLens.enable": true,
	"suggest.detailMaxLength": 60,
	"languageserver": {
		"lua": {
			"command": "lua-lsp",
			"filetypes": ["lua"]
		},
		"golang": {
			"command": "gopls",
			"rootPatterns": ["go.mod"],
			"filetypes": ["go"]
		},
		"bash": {
			"command": "bash-language-server",
			"args": ["start"],
			"filetypes": ["sh"],
			"ignoredRootPaths": []
		},
		"ccls": {
      "command": "ccls",
      "filetypes": ["c", "cpp", "cuda", "objc", "objcpp"],
      "rootPatterns": [".ccls-root", "compile_commands.json"],
      "initializationOptions": {
         "cache": {
           "directory": ".ccls-cache"
         }
       }
    }
	}
}
```

Run `:CocInstall coc-pyls coc-json coc-html coc-css ` to add needed language servers

```vim
coc-json for json.
coc-tsserver for javascript and typescript.
coc-html for html, handlebars and razor.
coc-css for css, scss and less.
coc-ember for ember projects.
coc-vetur for vue, use vetur.
coc-phpls for php, use intelephense-docs.
coc-java for java, use eclipse.jdt.ls.
coc-solargraph for ruby, use solargraph.
coc-rls for rust, use Rust Language Server
coc-rust-analyzer for rust, use rust-analyzer
coc-r-lsp for r, use R languageserver.
coc-yaml for yaml
coc-python for python, extension forked from vscode-python.
coc-highlight provides default document symbol highlighting and color support.
coc-emmet provides emmet suggestions in completion list.
coc-snippets provides snippets solution.
coc-lists provides some basic lists like fzf.vim.
coc-git provides git integration.
coc-yank provides yank highlights & history.
coc-fsharp for fsharp.
coc-svg for svg.
coc-tailwindcss for tailwindcss.
coc-angular for angular.
coc-vimlsp for viml.
coc-xml for xml, use lsp4xml.
coc-elixir for elixir, based on elixir-ls.
coc-erlang_ls for erlang, based on erlang_ls
coc-tabnine for tabnine.
coc-powershell for PowerShellEditorService integration.
coc-omnisharp for csharp and visualbasic.
coc-texlab for LaTex using TexLab.
coc-lsp-wl for wolfram mathematica, fork of vscode-lsp-wl.
coc-flow for flow
coc-reason for reasonml
coc-svelte for svelte
coc-flutter for flutter
coc-pyright Pyright extension
coc-markdownlint for markdown linting
coc-ecdict ECDICT extension
coc-metals for Scala using Metals
coc-explorer file explorer extension
coc-calc expression calculation extension
```

`$ sudo pacman -S ccls-git` C/C++的代码完成需要它的支持（非常重要！）。并查看其[官方文档](https://github.com/MaskRay/ccls/wiki/Build)以了解更多详细信息

--------

### Debug
### 调试

运行：`:checkhealth` neovim中的health以获取错误信息，并按照提示修改一些丢失的依赖项。

在neovim中`:messages` 以查找最新的错误日志。

如果您已经安装了另一个代码完成插件，我建议您删除所有这些插件，因为我曾经安装了一个名为YouCompleteMe的代码完成插件，但我无法配置它。当我删除它的所有文件时，我的插件才恢复正常。
--------

### 一些有用的提示

Do `$ pip3 install flake8` 进行如下编码检查:
    
![](2.png)

Run `$ sudo pacman -S ctags` 函数/类/变量列表.当你在C/C++中定义你的函数时，你可以看到一些函数/类/变量列表，这是非常方便的.

--------

