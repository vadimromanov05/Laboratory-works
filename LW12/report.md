# Отчёт по лаборатрной работе №12

---

## по курсу "Фундаментальная информатика"


Студент группы М8О-108Б-23 Романов Вадим Михайлович

Работа выполнена

Преподаватель: каф.806 Севастьянов Виктор Сергеевич

1. Тема: Техника работы с целыми числами.
2. Цель работы: Составить программу на Си в целом типе данных, которая для любых допустимых и корректно записанных десятичных чисел этого типа выполняет действие, обозначенное в задании.
3. Задание: удалить все чётные цифры из числа.
4. Идея, метод, алгориитм решения задачи:
   - ввести начальное число
   - через цикл выписать в новое число все нечётные цифры
   - перевернуть новое число через ещё один цикл
   - вывести ответ
5. Сценарий выполнения работы:
   - number - начальное число;
   - new_number - конечное число.
6. Протокол:
```c
#include<stdio.h>


int main(){
    int number, new_number = 0;
    scanf("%d", &number);
    while (number > 0)
    {
        if ((number % 10) % 2 == 1)
        {
            new_number = (new_number * 10) + (number % 10);
        }
        number = number / 10;
    }
    number = new_number;
    new_number = 0;
    while (number > 0)
    {
        new_number = (new_number * 10) + (number % 10);
        number = number / 10;
    }
    printf("%d", new_number);
}
```
```txt
C:\projects_c++\helloworld> gcc -std=c99 -Wall -pedantic LW12.c && C:\projects_c++\helloworld\LW12.exe
123456
135
```
8. Выводы: в результате выполнения лабораторной работы мне удалось ещё ближе познакомиться с убогой системой работы с данными в языке Си. То, что в Python делается в одну строку здесь пришлось растянуть на два неслабых цикла. Ещё больше захотелось влезть в изучение Си подробнее.