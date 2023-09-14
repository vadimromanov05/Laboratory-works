```bash
vadim@HuaweiRomanov MINGW64 ~
$ cd /d/Github

vadim@HuaweiRomanov MINGW64 /d/Github
$ mkdir Laboratory-works

vadim@HuaweiRomanov MINGW64 /d/Github
$ cd Laboratory-works

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works
$ git init
Initialized empty Git repository in D:/Github/Laboratory-works/.git/

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works (master)
$ mkdir LW1

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works (master)
$ mkdir LW2 LW3 LW4 LW5

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works (master)
$ mkdir LW6 LW7 LW8 LW9 LW10 LW11 LW12 LW13 LW14 LW15

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works (master)
$ git add --all

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works (master)
$ git commit -m'Связать локальный и удалённый репозитории'
On branch master
nothing to commit, working tree clean

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works (master)
$ git remote add origin git@github.com:vadimromanov05/Laboratory-works.git
error: remote origin already exists.

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works (master)
$ git push -u origin master
Enumerating objects: 4, done.
Counting objects: 100% (4/4), done.
Delta compression using up to 8 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (4/4), 517 bytes | 172.00 KiB/s, done.
Total 4 (delta 0), reused 0 (delta 0), pack-reused 0
To github.com:vadimromanov05/Laboratory-works.git
 * [new branch]      master -> master
branch 'master' set up to track 'origin/master'.

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works (master)
$ git add --all

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works (master)
$ git commit -m'Внести последние изменения в markdown'
[master f5cdf89] Внести последние изменения в markdown
 1 file changed, 25 insertions(+)

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works (master)
$ git push
Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 8 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (4/4), 913 bytes | 913.00 KiB/s, done.
Total 4 (delta 0), reused 0 (delta 0), pack-reused 0
To github.com:vadimromanov05/Laboratory-works.git
   b5ec11b..f5cdf89  master -> master

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works (master)
$ git branch new-task

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works (master)
$ git checkout new-task
Switched to branch 'new-task'

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works (new-task)
$ cd LW1

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW1 (new-task)
$ touch report.md

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW1 (new-task)
$ touch report.md

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW1 (new-task)
$ git add --all

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW1 (new-task)
$ git commit -m'Отправить финальную версию отчёта'

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW1 (new-task)
$ git push

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW1 (new-task)
$ git checkout main

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW1 (main)
$ git merge new-task
```