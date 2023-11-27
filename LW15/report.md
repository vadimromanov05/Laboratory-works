# Отчёт по лабораторной работе №15

---

## по курсу "Фундаментальная информатика"


Студент группы М8О-108Б-23 Романов Вадим Михайлович

Работа выполнена

Преподаватель: каф.806 Севастьянов Виктор Сергеевич

1. Тема: обработка матриц.
2. Цель работы: составить программу на Си для квадратной матрицы порядка N*N (1 <= N <= 8), из целых чисел, вводимой из стандартного входного текстового файла.
3. Задание: заменить все столбцы, имеющие минимальный элемент матрицы, на столбец с максимальным номером, содержащий её максимальный элемент.
4. Идея, метод, алгоритм решения задачи:
   - разобраться с файловым вводом на Си и понять, как он производится.
   - за 10 минут написать программу обработки массива матрицы и вывести её на экран.
5. Сценарий выполнения работы:
    Как обычно, прилагаю тесты:
    через 4 часа писать их сюда уже лень. Они пойдут отдельными файлами.
6. Протокол:
```c
#include <stdio.h>
#include<stdlib.h>


int maxi(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}


int main(){
    FILE *file;
    int matrix[10][10], check = 0, column;
    int i = 1, j = 1, k, size, max_j = 0, max = 0, min = 999999;
    int min_j[10], count = 0, digit, number = 0;
    

    file = fopen("D:/Github/Laboratory-works/LW15/matrix_3.txt", "r");


   for(k=0; (k < 100) && (feof(file) == 0); k++)
   {
        digit = fgetc(file);
        if ((digit <= 57) && (digit >= 48))
        {
            number = number * 10 + (digit - 48);
        }
        else if (digit == 32)
        {
            if (number >= max)
            {
                max = number;
                max_j = maxi(max_j, j);
            }
            if (number <= min)
            {
                min = number;
            }
            matrix[i][j] = number;
            number = 0;
            j ++;
            size ++;
        }
        else if (digit == 10)
        {
            if (number >= max)
            {
                max = number;
                max_j = maxi(max_j, j);
            }
            if (number <= min)
            {
                min = number;
            }
            matrix[i][j] = number;
            number = 0;
            i ++;
            j = 1;
            size = 0;
        }
        else if (digit == -1)
        {
            if (number >= max)
            {
                max = number;
                max_j = maxi(max_j, j);
            }
            if (number <= min)
            {
                min = number;
            }
            matrix[i][j] = number;
            break;
        }
   }
   fclose(file);
    size ++;

    for (j = 0; j < 10; j++)
    {
        min_j[j] = 0;
    }


    for (j = 1; j <= size; j++)
    {
        check = 0;
        for (i = 1; i <= size; i++)
        {
            if (matrix[i][j] == min)
            {
                check = 1;
            }
        if (check == 1)
        {
            min_j[count] = j;
            count ++;
        }
        }
    }


    for (j = 0; j < 10; j++)
    {
        if (min_j[j] != 0)
        {
            column = min_j[j];
            for (i = 1; i <= size; i++)
            {
                matrix[i][column] = matrix[i][max_j];
            }
        }
    }


    for (i = 1; i <= size; i++)
    {
        for (j = 1; j <= size; j++)
        {
            printf("%d ", matrix[i][j]);
        }
    printf("\n");
    }
}
```
8. Выводы: я что-то говорил про 10 минут в 4 пункте. Так вот, спустя 4 часа заявляю, что это работа не на 10 минут. Ввод ведь не из клавиатуры, а из файла. И ведь в Си я нашёл кучу функций для ввода данных из него, но подошла из этой горы мусора только одна функция. Это вам не Python, где можно скатать код и в ус не дуть: здесь его надо разобрать на запчасти и 10 раз перебрать, чтобы он под мои условия подошёл. В общем, мне было весело.