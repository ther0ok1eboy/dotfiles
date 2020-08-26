# Operations of vim: 
--------

- **i: 写入模式、i插入之前、a插入之后、A行尾插入、I行首插入、o下行插入、O上行插入**

- **x: 删除光标后一个字符**

- **d: + ←→删除光标←→字符（d +3←）、dd删除一行（其实是剪切，p粘贴）**

- **y+ ←→: 复制光标←→字符 （y+3←）**

- **c: 删除并进入写入模式、w 光标向下移动一个词、cw删除一个词并进入写入模式、b光标到上一个词 、ci+符号 把符号中的词删掉进入写入模式，yi+符号/di+符号 把符号中的词复制/剪切不进入写入模式**

- **f: 找词 f+字母 光标跳到最近的字母 df+字母 删除光标到字母**

- **u: 搜索、n下 N上**

- **gf: open a file under the path (go to file)**

- **Ctrl + o: back to last index(whatever this index at different file)**

- **Ctrl + i: back to next index(suit at gf)**

```c
esc 回到正常模式
：w保存
：q退出vim
：source $MYVIMRC 刷新vim
jkhl上下左右
：split 上下分屏 、：vsplit 左右分屏 Q退出
~/.vim/vimrc
noremap a b a键改b键
map a b a键改b键
syntax on 打开高亮
set number 显示行号
set wildmenu ：命令补全
set hlsearch /搜索高亮
set incsearch 一面输入一面高亮
set ignorecase 忽略大小写43：35美化！
```
--------

# vim插件安装方法:
```c
1 curl -fLo ~/.vim/autoload/plug.vim --create-dirs \
    https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
```
```c
2 write 'call plug#begin('~/.vim/plugged')   /*plug1 syntax*/ /*plug2 syntax*/...   call plug#end()' in .vimrc	
```
```c
3 write 'Plug 'vim-airline/vim-airline' in your .vimrc then Esc=>:PlugInstall=>restart (if PlugInstall is not a command, go .vim file then mkdir plug)
```

```c
4 cd $HOME/.vim && mkdir colors && cd colors && wget  https://raw.githubusercontent.com/connorholyday/vim-snazzy/master/colors/snazzy.vim then write 'Plug 'connorholyday/vim-snazzy'' then write 'colorscheme snazzy' after call plug#end() syntax then restart
```

	

