# Отчёт по лабораторной работе №21

---

## по курсу "Алгоритмы и структуры данных"


Студент группы М8О-108Б-23 Романов Вадим Михайлович

Работа выполнена

Преподаватель: каф.806 Севастьянов Виктор Сергеевич

1. Тема: Программирование на интерпретируемых командных языках
2. Цель работы: составить программу выполнения заданных действий на одном из интерпретируемых языков ОС Unix
3. Задание: рекурсивный обход указанного каталога и замена всех разделителей пути с \ на / в файлах с именем Makefile
4. Идея, метод, алгоритм решения задачи:
"Я художник, я так вижу" - так хотелось мне обозначить смысл моей работы. В переводе на нормальный я должен был заменить разделители пути с \ на / в файлах с именем Makefile. Именно так я и сделал. Не знаю, что сюда добавить.
5. Сценарий выполнения работы:
- сразу же сделать компу поблажку и выполнять весь скрипт в диске D (чтобы он не пал смертью храбрых)
- в самом начале позабоититься о вводе переменных и защите от издевательств над компьютером
- составить реальную рекурсию, которая будет заменять все \ на / в Makefile-ах (как она работает, рассказать трудно)
6. Протокол:
```bash
#!/bin/bash
cd /d/D
read -p "Введите название каталога: "  catalog

if [ -s $catalog ];
then
    echo "Вы ввели какую-то фигню, дальше работаем с диском D";
    catalog="D"; 
else 
    while [ -s $(find . -type d -name "$catalog") ];
    do 
        echo "Эмм... Вы ввели что-то не то, попробуйте ещё раз";
        read catalog;
    done;
fi

main_catalog=$catalog;

function rewrite {
   cd "$(find /d/D -name "$catalog")";
   for arg in $(ls -R $(find /d/D -name "$catalog"));
   do
      if [ -d $arg ];
      then
         catalog=$arg;
         rewrite;
      else
         if [ $arg = "Makefile" ];
         then
            touch file.txt;
            cat $arg | tr '/' '\\' > file.txt;
            cat file.txt > $arg;
            rm -f file.txt;
         fi;
      fi;
   done
   if [ $catalog != $main_catalog ];
   then
      cd ..;
      catalog=$(pwd | awk -F'/' '{print $NF}');
   fi;
}

rewrite;
```
8. Выводы: я составил то, что от меня требовалось, хоть на это и ушло 2 недели. Для компа это была самая страшная лаба из всех: на 2 дня у него сломался файл из самого ядра винды, отчего компьютер не работал всё это время. В любом случае, работа выполнена на 100 %.