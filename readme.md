skdflsdkifbnglide

create a new repository on the command line
~~~S
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin git@github.com:zhoufangquan/codeC-.git
git push -u origin main
~~~

# git clone的用法：
~~~s
$ git clone <版本库的url>
~~~
例如克隆TensorFlow：
~~~s
$ git clone https://github.com/tensorflow/tensorflow.git
~~~
或者使用SSH协议：
~~~s
$ git clone git@github.com:tensorflow/tensorflow.git
~~~
这样就会在本地生成一个目录，该目录与远程仓库同名。
However，如果本地目录不想与远程仓库同名怎么办？？也有办法，将目录名作为git clone命令的第二个参数:
~~~s
$ git clone <版本库的网址> <本地目录名>
~~~

# git pull的用法：
git pull是拉取远程分支更新到本地仓库的操作。比如远程仓库里的学习资料有了新内容，需要把新内容下载下来的时候，就可以使用git pull命令。事实上，git pull是相当于从远程仓库获取最新版本，然后再与本地分支merge（合并）。
　　即：git pull = git fetch + git merge

注：git fetch不会进行合并，执行后需要手动执行git merge合并，而git pull拉取远程分之后直接与本地分支进行合并。更准确地说，git pull是使用给定的参数运行git fetch，并调用git merge将检索到的分支头合并到当前分支中。

~~~S
$ git pull <远程主机名> <远程分支名>:<本地分支名>
~~~
举例：将远程主机origin的master分支拉取过来，与本地的branchtest分支合并。
~~~S
$ git pull origin master:branchtest
~~~
如果将冒号和后面的branchtest去掉，则表示将远程origin仓库的master分支拉取下来与本地当前分支合并。
以上的git pull操作如果用git fetch来表示：
~~~S
$ git fetch origin master:brantest
$ git merge brantest
~~~
相比起来，git fetch更安全也更符合实际要求，因为可以在merge前，我们可以查看更新情况，根据实际情况再决定是否合并。


# git fetch更新本地仓库的两种用法：

~~~s
# 方法一
$ git fetch origin master                #从远程的origin仓库的master分支下载代码到本地的origin maste
$ git log -p master.. origin/master      #比较本地的仓库和远程参考的区别
$ git merge origin/master                #把远程下载下来的代码合并到本地仓库，远程的和本地的合并
~~~

~~~s
# 方法二
$ git fetch origin master:temp           #从远程的origin仓库的master分支下载到本地并新建一个分支temp
$ git diff temp                          #比较master分支和temp分支的不同
$ git merge temp                         #合并temp分支到master分支
$ git branch -d temp                     #删除temp
~~~
