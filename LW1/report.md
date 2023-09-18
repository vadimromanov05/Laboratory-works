# Отчёт по лабораторной работе №1

---

## по курсу "Фундаментальная информатика"


Студент группы М8О-108Б-23 Романов Вадим Михайлович  

Работа выполнена  

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич  

    1. Тема: Git, Github, Gitlab etc  
    2. Цель работы: завести репозиторий в Github и научиться создавать и мержить ветки  
    3. Задание:  
       1) завести репозиторий (общий под все лабораторные работы с отдельной папкой под каждую лр!)  
       2) отчет с листингом в Markdown (листинг - ctrl+c -> ctrl+v из терминала с форматированием в markdown)  
       3) создать отдельную ветку в репозитории под задание  
       4) создать коммит с листингом и отчетом  
       5) смержить ветку в мейн  
    4. Идея, метод, алгоритм решения задачи:  
        1) Установка на компьютер Git  
        2) Создание в диске D новой папки, где будут находиться все репозитории, через командную строку Git  
        3) Создание папок под все лабораторные работы, настоящие и будущие, также через командную строку  
        4) Создание первого отчёта с листингом в Markdown, где отображены действия из пункта 2 и 3  
        5) Создание новой ветки new-task в репозитории под новые задания  
        6) Создание коммита с листингом и отчётом обо всех моих действиях со 2 по 5 пункт вместе с помещением данного отчёта в коммит  
        7) Соединить ветку new-task с веткой main  
    5. Сценарий выполнения работы:  
        Мои команды в Git-е в совокупности должны были создать репозиторий, необходимые папки, а также провести некоторые операции с ветками. Вот список используемых мною команд:  
            |----------------------|-------------------------------|  
            |"cd <название папки>" | "переход в определённую папку"|  
            |"mkdir <название папки>" | "создать папку"|  
            |"git init" | "создать репозиторий"|  
            |"git add <название файла>" | "подготовка файлов к сохранению"|  
            |"git commit -m''" | "содать коммит с сообщением"|  
            |"git push" | "связать локальный и удалённый репозитории"|  
            |"git branch" | "создать новую ветку"|  
            |"touch <название файла>" | "создать файл"|  
            |"git checkout <название ветки>" | "переход на другую ветку"|  
            |"git merge <название ветки>" | "мерженье веток"|  
    6. Протокол:  

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

    7. Замечания автора: Считаю, что объяснения к данной работе необходимо было давать на основе данных Яндекс Практикума. Только в этом курсе есть более-менее исчерпывающие данные касательно темы лабораторной работы.  
    8. Выводы: Данная лабораторная работа была сущим кошмаром, но дальше будет ещё хуже. Учиться работать в Git необходимо в Яндекс Практикуме, а не в Московском авиационном институте, дабы сберечь здоровье. Всё мучительное обучение, возможно, в каком-то смысле и было очень интересно. В любом случае, за эти несколько дней я хотя бы понял, что такое Git, чем он отличается от Github, узнал базовые команды, и за всё это спасибо Яндексу. Теперь я знаю, что там можно хоть чему-то научиться.