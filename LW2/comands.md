```bash
vadim@HuaweiRomanov MINGW64 ~
$ cd /d/Github/Laboratory-works
```bash
vadim@HuaweiRomanov MINGW64 ~
$ cd /d/Github/Laboratory-works

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works (master)
$ cd LW2

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ touch report.md

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ touch comands.md

root@HuaweiRomanov:~# who
root     pts/1        2023-09-14 19:21

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ pwd
/d/Github/Laboratory-works/LW2

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ ls
comands.md  report.md

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ cd ..

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works (master)
$ cd LW2

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ mkdir test

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ cp comands.md test/

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ rm comands.md

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ cd test

$ cat report.md
Студент группы М8О-108Б-23 Романов Вадим Михайлович
...

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2/test (master)
$ mkdir test2

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2/test (master)
$ mv comands.md ./test2

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2/test (master)
$ rm -r test2
 
vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ rmdir test

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ ps
      PID    PPID    PGID     WINPID   TTY         UID    STIME COMMAND
     1606    1605    1606       7088  pty0      197609 09:03:55 /usr/bin/bash
     1605       1    1605      18960  ?         197609 09:03:55 /usr/bin/mintty
     1714    1606    1714      19660  pty0      197609 09:14:22 /usr/bin/ps

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ tail report.md
$ rm comands.md

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ cd test


'```'
    7. Замечания автора:

    8. Вывод:

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ head report.md
Студент группы М8О-108Б-23 Романов Вадим Михайлович

Работа выполнена

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

    1. Тема: Bash, linux terminal
    2. Цель работы: опробовать основные команды языка Bash и научиться работать с удалённой машиной и архивировать
    3. Задание:
        1) Опробовать следующие команды:

root@HuaweiRomanov:~# grep bash /etc/passwd
root:x:0:0:root:/root:/bin/bash

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ history
    1  pwd
    2  cd ~
    3  pwd
    4  cd ~
    5  pwd
    6  ls
    7  pwd
    8  cd github
    9  cd c
   10  cd program files
   11  cd Desktop
   12  cd desktop
   13  ls
   14  cd 'Мои документы'
   15  pwd
   16  cd ~
...

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ mkdir test

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ rmdir test

root@HuaweiRomanov:~# sudo -l
Matching Defaults entries for root on HuaweiRomanov:
    env_reset, mail_badpass,
    secure_path=/usr/local/sbin\:/usr/local/bin\:/usr/sbin\:/usr/bin\:/sbin\:/bin\:/snap/bin,
    use_pty

User root may run the following commands on HuaweiRomanov:
    (ALL : ALL) ALL

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ echo 'Hello, world!'
Hello, world!

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ ssh -p vadim@HuaweiRomanov
Bad port 'vadim@HuaweiRomanov'

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ ssh-keygen -t ed25519 -C "vadim.romanov.05@list.ru"
Generating public/private ed25519 key pair.
Enter file in which to save the key (/c/Users/vadim/.ssh/id_ed25519):

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ ssh-copy-id vadim@HuaweiRomanov
/usr/bin/ssh-copy-id: INFO: Source of key(s) to be installed: "/c/Users/vadim/.ssh/id_ed25519.pub"
/usr/bin/ssh-copy-id: INFO: attempting to log in with the new key(s), to filter

/usr/bin/ssh-copy-id: ERROR: ssh: connect to host huaweiromanov port 22: Connect

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works (master)
$ cd LW2

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ touch report.md

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ touch comands.md

root@HuaweiRomanov:~# who
root     pts/1        2023-09-14 19:21

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ pwd
/d/Github/Laboratory-works/LW2

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ ls
comands.md  report.md

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ cd ..

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works (master)
$ cd LW2

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ mkdir test

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ cp comands.md test/

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ rm comands.md

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ cd test

$ cat report.md
Студент группы М8О-108Б-23 Романов Вадим Михайлович
...

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2/test (master)
$ mkdir test2

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2/test (master)
$ mv comands.md ./test2

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2/test (master)
$ rm -r test2
 
vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ rmdir test

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ ps
      PID    PPID    PGID     WINPID   TTY         UID    STIME COMMAND
     1606    1605    1606       7088  pty0      197609 09:03:55 /usr/bin/bash
     1605       1    1605      18960  ?         197609 09:03:55 /usr/bin/mintty
     1714    1606    1714      19660  pty0      197609 09:14:22 /usr/bin/ps

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ tail report.md
$ rm comands.md

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ cd test


'```'
    7. Замечания автора:

    8. Вывод:

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ head report.md
Студент группы М8О-108Б-23 Романов Вадим Михайлович

Работа выполнена

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

    1. Тема: Bash, linux terminal
    2. Цель работы: опробовать основные команды языка Bash и научиться работать с удалённой машиной и архивировать
    3. Задание:
        1) Опробовать следующие команды:

root@HuaweiRomanov:~# grep bash /etc/passwd
root:x:0:0:root:/root:/bin/bash

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ history
    1  pwd
    2  cd ~
    3  pwd
    4  cd ~
    5  pwd
    6  ls
    7  pwd
    8  cd github
    9  cd c
   10  cd program files
   11  cd Desktop
   12  cd desktop
   13  ls
   14  cd 'Мои документы'
   15  pwd
   16  cd ~
...

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ mkdir test

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ rmdir test

root@HuaweiRomanov:~# sudo -l
Matching Defaults entries for root on HuaweiRomanov:
    env_reset, mail_badpass,
    secure_path=/usr/local/sbin\:/usr/local/bin\:/usr/sbin\:/usr/bin\:/sbin\:/bin\:/snap/bin,
    use_pty

User root may run the following commands on HuaweiRomanov:
    (ALL : ALL) ALL

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ echo 'Hello, world!'
Hello, world!

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works (master)
$ ssh v_romanov@185.5.249.140
v_romanov@185.5.249.140's password:
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.


The programs included with the Ubuntu system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Ubuntu comes with ABSOLUTELY NO WARRANTY, to the extent permitted by
applicable law.

v_romanov@vds2476450:~$



```