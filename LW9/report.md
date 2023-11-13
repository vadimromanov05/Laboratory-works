# Отчёт по лабораторной работе №9

---

## по курсу "Фундаментальная информатика"


Студент группы М8О-108Б-23 Романов Вадим Михайлович

Работа выполнена

Преподаватель: каф.806 Севастьянов Виктор Сергеевич

1. Тема: системы программирования на языке С
2. Цель работы: составление и отладка простейшей программы на языке С итеративного характера с целочисленными реккурентными соотношениями, задающими некоторое регулярное движение точки в целочисленной системе координат (i, j) с дискретным временем k и динамическим параметром движения k
3. Задание: эллипс с центром в точке (20, 0) и проходящий через точки (10, 0), (30, 0), (20, 5), (20, -5).
   - i0 = -7; j0 = -19; l0 = 4
   - i(k+1) = max(ik*jk, ik*lk, jk*lk) mod 30 + k
   - j(k+1) = |jk - lk| * sign(ik) - |ik - lk| * sign(jk)
   - l(k+1) = min(ik, max(jk, min(lk, max(ik - lk, jk - lk))))
   Реализовать цель лабораторной работы 
4. Идея, метод, алгоритм решения задачи:
   Сценарий и алгоритм до боли простой (в Python). Всего-то нужно написать цикл for и использовать парочку арифметических операций. И вывести для каждой итерации полученный результат. Делать это до тех пор, пока координаты не окажутся в эллипсе.
5. Сценарий выполнения работы:
   - Ощутить, что такое настоящая боль
   - Полюбить Python с его библиотеками
   - Поблагодарить Гвидо Ван Россума за избавление от страданий
   - С божьей помощью написать эту простенькую программу, в которой циклы валятся непонятно от чего (и не только циклы)
6. Протокол:
```c
#include <stdio.h>
#include <math.h>


int max(int a, int b)
{
    if (a >= b)
    {
        return(a);
    }
    else
    {
        return(b);
    }
}


int min(int a, int b)
{
    if (a <= b)
    {
        return(a);
    }
    else
    {
        return(b);
    }
}


int abs(int a)
{
    if (a >= 0)
    {
        return(a);
    }
    else
    {
        return(-a);
    }
}


int sign(int a)
{
    if (a > 0)
    {
        return(1);
    }
    else if (a < 0)
    {
        return(-1);
    }
    else
    {
        return(0);
    }
}


int main(){
    int i, j, l, k, i1, j1, l1;
    i = -7;
    j = -19;
    l = 4;
    k = 1;
    while ((pow(0.5 * (i - 20), 2) + pow(j, 2)) > 25) {
        i1 = j1 = l1 = 0;
        i1 = max(i * j, max(i * l, j * l)) % 30 + k;
        j1 = abs(j - l) * sign(i) - abs(i - l) * sign(j);
        l1 = min(i, max(j, min(l, max(i - l, j - l))));
        j = j1;
        l = l1;
        i = i1;
        printf("%s ",  "iteration:");
        printf("%d\n", k);
        printf("i = %d; ", i);
        printf("j = %d; ", j);
        printf("l = %d. \n", l);

        if ((pow(0.5 * (i - 20), 2) + pow(j, 2)) <= 25)
        {
            printf("%s. \n", "Coordinats are in ellipse");
        }
        else
        {
            printf("%s. \n", "Coordinats are not in ellipse");
        }
        k = k + 1;
    }
}
```
```txt
C:\projects_c++\helloworld> gcc -std=c99 -Wall -pedantic 1.c && C:\projects_c++\helloworld\1.exe
iteration: 1
i = 14; j = -12; l = -11.
Coordinats are not in ellipse.
iteration: 2
i = 14; j = 26; l = -11.
Coordinats are not in ellipse.
iteration: 3
i = 7; j = 12; l = 14.
Coordinats are not in ellipse.
iteration: 4
i = 22; j = -5; l = 7.
Coordinats are not in ellipse.
iteration: 5
i = 9; j = 27; l = 7.
Coordinats are not in ellipse.
iteration: 6
i = 9; j = 18; l = 9.
Coordinats are not in ellipse.
iteration: 7
i = 19; j = 9; l = 9.
Coordinats are not in ellipse.
iteration: 8
i = 29; j = -10; l = 9.
Coordinats are not in ellipse.
iteration: 9
i = 30; j = 39; l = 9.
Coordinats are not in ellipse.
iteration: 10
i = 10; j = 9; l = 30.
Coordinats are not in ellipse.
iteration: 11
i = 11; j = 1; l = 9.
Coordinats are in ellipse.
```
8. Выводы: что-то мне расхотелось учить дальше язык C. Мне и азов плюсов с головой хватило. Я понял, что такое ад для программистов и понял, что пора эту жесть нормально изучать. Точка.