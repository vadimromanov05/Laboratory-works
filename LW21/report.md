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
"Я художник, я так вижу" - так хотелось мне обозначить смысл моей работы. В переводе на нормальный я должен был вывести всё содержимое заданной папки и заменить разделители пути с \ на / в файлах с именем Makefile. Именно так я и сделал. Не знаю, что сюда добавить.
5. Сценарий выполнения работы:
- сразу же сделать компу поблажку и выполнять весь скрипт в диске D (чтобы он не пал смертью храбрых)
- в самом начале позабоититься о вводе переменных и защите от издевательств над компьютером
- после построения защитных систем создать один-единственный цикл, выполняющий всю работу скрипта, а именно:
   - поиск ввобще всех файлов и директорий в нашем каталоге
   - вывод на экран полных адресов данных файлов и директорий согласно поставленному заданию 
6. Протокол:
```bash
vadim@HuaweiRomanov MINGW64 ~ #Это диск D без корзины, маленькая поблажка для меня (чтобы компьютер не падал смерьтю храбрых)
$ cd /d/D

vadim@HuaweiRomanov MINGW64 /d/D
$ echo Введите название каталога
Введите название каталога

vadim@HuaweiRomanov MINGW64 /d/D
$ read catalog
First_directory #здесь название каталога

vadim@HuaweiRomanov MINGW64 /d/D
$ while [ -s $(find . -type d -name "$catalog") ] #проверка на издевательства
> do
> echo "Эм... Такой директории нет, пробуйте ещё раз"
> read catalog
> done


vadim@HuaweiRomanov MINGW64 /d/D
$ for arg in $(find /d/D -name "$catalog")
> do
> echo -e "$(find $(find /d/D -name "$catalog") -name 'Makefile.txt')" | tr '/' '\\'
> echo -e "$(find $(find /d/D -name "$catalog") -not -name 'Makefile.txt')"
> done
\d\D\Github\Laboratory-works\LW21\First_directory\Makefile.txt
\d\D\Github\Laboratory-works\LW21\First_directory\Second_directory\Makefile.txt
/d/D/Github/Laboratory-works/LW21/First_directory
/d/D/Github/Laboratory-works/LW21/First_directory/First_file.txt
/d/D/Github/Laboratory-works/LW21/First_directory/Second_directory
/d/D/Github/Laboratory-works/LW21/First_directory/Second_directory/Second_file.txt
```
8. Выводы: обход получился не совсем рекурсивный. Кажется, мне удалось сломать систему и сделать скрипт через один цикл. Он прекрасно работает и его ничто не остановит (кроме моей тупости, разве что). Как говорил Конфуций: "Если код работает, то ничего в нём не трогай". Но я не такой умный, как он.