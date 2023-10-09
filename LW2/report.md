# Отчёт по лабораторной работе №2

---

## по курсу "Фундаментальная информатика"


Студент группы М8О-108Б-23 Романов Вадим Михайлович  

Работа выполнена  

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич  

1. **Тема:** Bash, linux terminal  
2. **Цель работы:** опробовать основные команды языка Bash и научиться работать с удалённой машиной и архивировать  
3. **Задание:**


- Опробовать следующие команды:  
    - who  
    - pwd  
    - ls  
    - cd  
    - cp  
    - mv  
    - rm  
    - cat  
    - ps  
    - tail  
    - head  
    - grep  
    - history  
    - mkdir  
    - rmdir  
    - sudo  
    - echo  
    - ssh  
    - scp  
    - ssh-keygen  
    - ssh-copy-id  


- Использовать основные команды  
- Сохранить листинг в файл  
- Заархивировать  
- Отправить на удаленную машину, там разархивировать  
- Скачать разархивированный файл к себе на машину  
- Составить отчет с листингом в формате markdown  
- Выложить на github через merge веток  
4. **Идея, метод, алгоритм решения задачи:**  
   - Последовательно использовать вышеперечисленные команды и понять смысл их работы, используя командную строку Git  
   - Сохранить листинг с использованием этих команд в отдельном файле, тоже через консоль  
   - Оставить листинг с командами в этом отчёте  
   - Заархивировать файл с командами, отправить его на удалённую машину и с её помощью разархивировать  
   - Снова составить листинг из вышеперечисленных действий на Git-e в форме Markdown на отдельной ветке  
   - Выложить все мои изыскания на Github через соединение данных в ветках  
5. **Сценарий выполнения работы:** 
        Список не описанных мною ранее команд с пояснениями:  

|Команда       | То, что она делает                                                |
|--------------|-------------------------------------------------------------------|  
|"who"         | "отобразить данные пользователя"                                  |  
|"pwd"         | "оказать моё местонахождение в папке"                             |  
|"ls"          | "показать файлы и папки в текущем файле"                          |  
|"cp"          | "копировать файл"                                                 |  
|"mv"          | "переместить файл"                                                |  
|"rm"          | "удалить файл"                                                    |  
|"cat"         | "показать всё содержимое файла"                                   |  
|"ps"          | "показать процессы, протекающие в компьютере"                     |  
|"tail"        | "вывести последние 10 строк из файла"                             |  
|"head"        | "вывести данные с файла, но не все, как в случае с cat"           |  
|"grep"        | "найти строку в файле"                                            |  
|"history"     | "просмотреть историю команд"                                      |  
|"rmdir"       | "удалить папку"                                                   |  
|"sudo"        | "разрешить использовать команды, доступные только администраторам"|  
|"echo"        | "вывести указанную строку на экран"                               |  
|"ssh"         | "выполнить команду на удалённой машине"                           |  
|"scp"         | "удалённое копирование файла"                                     |  
|"ssh-keygen"  | "сгенерировать публичный и приватный ключи"                       |  
|"ssh-copy-id" | "установить ключ SSH на авторизованные ключи удаленного сервера"  |  

6. **Протокол**: 
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
$ tar -cf first-archive.tar /d/Github/Laboratory-works/LW2/comands.md
tar: Removing leading `/' from member names

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

v_romanov@vds2476450:~$ scp -c /d/Github/Laboratory-works/LW2/first-archive.tar v_romanov@185.5.249.140:/LW2/
usage: scp [-346BCpqrTv] [-c cipher] [-F ssh_config] [-i identity_file]
            [-J destination] [-l limit] [-o ssh_option] [-P port]
            [-S program] source ... target

<<<<<<< HEAD
=======
vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ scp /d/Github/Laboratory-works/LW2/first-archive.tar v_romanov@185.5.249.140:~
v_romanov@185.5.249.140's password:
Permission denied, please try again.
v_romanov@185.5.249.140's password:
first-archive.tar                             100%   20KB 228.4KB/s   00:00

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ ssh v_romanov@185.5.249.140                                                   v_romanov@185.5.249.140's password:
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Mon Sep 25 09:48:21 2023 from 178.176.73.139

v_romanov@vds2476450:~/LW2$ tar -xvf first-archive.tar
comands.md
v_romanov@vds2476450:~/LW2$ ls
comands.md  first-archive.tar

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ scp v_romanov@185.5.249.140:~/LW2/comands.md /d/Github/Laboratory-works/
v_romanov@185.5.249.140's password:
comands.md                                                                                                                                                                      100% 9305   115.1KB/s   00:00

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ git add --all

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ git checkout new-task
Switched to branch 'new-task'
Your branch is up to date with 'origin/new-task'.

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (new-task)
$ git add --all

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (new-task)
$ git commit -m'Занести финальные изменения в новую ветку'

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (new-task)
$ git push

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (new-task)
$ git checkout master

vadim@HuaweiRomanov MINGW64 /d/Github/Laboratory-works/LW2 (master)
$ git merge new-task
>>>>>>> new-task
```
```
8. **Вывод**:  к моему удивлению, эта лабораторная работа далась мне чуть легче, чем предыдущая. У меня ушло на неё немного меньше времени 
и я научился работать с удалённой машиной на ОС Unix. Кроме этого, меня ещё поразили многие команды(grep, ps, ssh, tar и scp), отработанные на этой ЛР. Пришлось также искать и новые источники информации(habr, stackoverflow и другие), кроме Яндекс Практикума, что тоже можно вписать в список приобретённых знаний и навыков. В целом, если эта работа пройдёт защиту, то можно считать её не очень страшной и довольно интересной.