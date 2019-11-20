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
１．强行上传　　 
`git push -u origin +master`
　　　　　　　

2． 尽量先同步github上的代码到本地，在上面更改之后再上传

### error: pathspec 'modify' did not match any file(s) known to git

resolve:

`$ git commit -a -m "modify"`  
