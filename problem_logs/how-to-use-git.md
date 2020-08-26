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


If we `git clone` to download by https instead of git@git(ssh) or `git push/pull`, git always hint us to input account/password, which make us disgust

Resolve:

`git bash` into your local repository and input

`git config --global credential.helper store`

after execute this command, it is auto product a txt file in which record your account and password

`git push` input the last password   

### push error

Tips: refuse to update, because of not exist local commit included by remote repository

Reason: the repository you want to push was been used(remote add origin master..) by other local repository and see 'Git push --help to find more information'

Resolve:

1. force to push　　 

`git push -u origin +master`
　　　　　　　

2. download your remote repository to modify then commit
    
`git clone [your remoterepositiry page]`  

### error: pathspec 'modify' did not match any file(s) known to git

Resolve:

`$ git commit -a -m "modify"`  
