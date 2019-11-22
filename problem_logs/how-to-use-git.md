# oh my git
--------

- **1.查看Git的使用方法 ： git**

- **2.把当前文件夹变为一个git仓库 创建git仓库：git init**

- **3.查看当前仓库文件变化情况：git status**

- **4.添加修改：git add （可使用git add . 来添加当前仓库所有修改）**

- **5.本次还没有提交的更改：git diff（比较工作区与暂存区的区别）**

- **6.回滚，撤销提交操作：git reset**

- **7.向Git提交自己身份（name）：git config --global user.name "xxx"**

- **8.向Git提交自己身份（email）：git config --global user.email "xxx@xx.com"**

- **9.向Git提交内容：git commit -m “xx” （xx为对提交的内容进行描述）**

- **10.让Git不提交某些文件/忽略某些文件：创建文件 .gitignore 并在文件中添加文件名/文件夹名 即可 （若git已经开始追踪某些文件 则需要11）**

- **11.让Git不再追踪某个/某些文件：git rm --cached xx （xx为文件名）**

- **12.Git添加分支：git branch xx （xx为分支名）**

- **13.Git切换分支：git checkout xx （xx为分支名）**

- **14.合并分支：git merge xx（xx为分支名）**

- **15.列出本地分支：git branch**

- **16.删除分支:git branch -d xx (xx为分支名，-D强制删除)**

- **17.添加远程仓库：git remote add origin xxx （xxx为远程地址）**

- **18.设置本地分支追踪远程分支：git push --set-upstream**

- **19.克隆仓库：git clone xxx（xxx为远程地址）**

- **20.删除本地仓库: rm -rf .git** 


--------
# some problems when i use git 


### repeat input password when your push git code

如果我们git clone的下载代码的时候是连接的https://而不是git@git (ssh)的形式，当我们操作git pull/push到远程的时候，总是提示我们输入账号和密码才能操作成功，频繁的输入账号和密码会很麻烦。

解决办法：

git bash进入你的项目目录，输入：

`git config --global credential.helper store`

然后你会在你本地生成一个文本，上边记录你的账号和密码。当然这些你可以不用关心。

然后你使用上述的命令配置好之后，再操作一次git pull，然后它会提示你输入账号密码，这一次之后就不需要再次输入密码了

### push error

提示：更新被拒绝，因为远程版本库包含您本地尚不存在的提交。这通常是因为另外提示：一个版本库已向该引用进行了推送。再次推送前，您可能需要先整合远程变更提示：（如 'git pull ...'）。提示：详见 'Git push --help' 中的 'Note about fast-forwards' 小节。

原因可能是之前上传时创建的.git文件被删除或更改，或者其他人在github上提交过代码．

解决方案如下：
1. 强行上传　　 
`git push -u origin +master`
　　　　　　　

2. 尽量先同步github上的代码到本地，在上面更改之后再上传

### error: pathspec 'modify' did not match any file(s) known to git

resolve:

`$ git commit -a -m "modify"`  
