# Отчёт по лабораторной работе №8

---

## по курсу "Фундаментальная информатика"


Студент группы М8О-108Б-23 Романов Вадим Михайлович

Работа выполнена

Преподаватель: каф.806 Севастьянов Виктор Сергеевич

1. Тема: системы программирования на языке С
2. Цель работы: изучение конкретной системы программирования на Си и получение навыков подготовки тестов и отладки программ
3. Задание: 
   - изучить и освоить возможности СП gcc, в том числе основные этапы компиляции и подготовки к выполнению
   - составить и отладить простейшую программу на C в терминальном классе
   - изучить систему программирования на домашнем компьютере (например, Microsoft Visual Studio)
4. Идея, метод, алгоритм решения задачи:
   Посмотреть необходимую для выполнения ЛР информацию в высланных ссылках, а потом перейти к выполнению работы 
5. Сценарий выполнения работы:
   - написать программу "Hello, world" на языке С
   - понять, как нужно запустить программу, чтобы было видно основные этапы её выполнения
   - установить текстовый редактор emacs
   - наконец-таки понять п.2 и записать листинг в протокол
   - обрадоваться завершению выполнения лабораторной работы
6. Протокол:
```c
vadim@HuaweiRomanov MINGW64 ~
$ cd C:/projects_c++

vadim@HuaweiRomanov MINGW64 /c/projects_c++
$ cd helloworld

vadim@HuaweiRomanov MINGW64 /c/projects_c++/helloworld
$ cat LW8$.c
#include <stdio.h>


int main(){
    printf("Hello, world!\n");
}

C:\projects_c++\helloworld>gcc LW8$.c

vadim@HuaweiRomanov MINGW64 /C/projects_c++/helloworld
$ cat compile.exe
далее идёт текст в километр длиной

C:\projects_c++\helloworld>gcc -o compile_error.exe LW8$.c
LW8$.c: In function 'main':
LW8$.c:5:30: error: expected ';' before '}' token
    5 |     printf("Hello, world!\n")
      |                              ^
      |                              ;
    6 | }
      | ~
```
Результат компиляции я записал только для правильного случая. Если ошибиться, то будет выдано лишь то, что написано в протоколе.
7. Выводы: эта лабораторная работа сделана. Я узнал, где можно детально изучить каждый этап выполнения программы, а также начал изучение языка С.
P.S. Забыл отметить, что у меня ушёл весь день на эту лёгкую задачу. Мне пришлось скачать весь Интернет себе на компьютер и 20 раз возвращать его из компьютерного рая (места, в котором нет идиотов вроде меня).