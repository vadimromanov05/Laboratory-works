# Отчёт по лабораторной работе №13

---

## по курсу "Фундаментальная информатика"


Студент группы М8О-108Б-23 Романов Вадим Михайлович

Работа выполнена

Преподаватель: каф.806 Севастьянов Виктор Сергеевич

1. Тема: Множества
2. Цель работы: составить программу проверки характеристик введённых последовательностей слов и печати развёрнутого ответа.
3. Задание: проверить, есть ли гласная, согласная, не входящая ни в одно слово.
4. Идея, метод, алгоритм решения задачи: 
- не использовать советы из текста лабы и сделать всё самому;
- придумать программу на основе опыта из Python;
- написать кучу функций, делающих программирование приятным;
- понять, что для каждого массива нужно писать функцию отдельно;
- написать все функции и сделать выполнение программы возможным;
- преобразовать все буквы в их ASCII-коды и проверить на этой основе наличие/отсутствие букв;
- все ненайденные ASCII-коды преобразовать обратно в буквы и вывести на экран.
5. Сценарий выполнения работы: 
Понадобятся многострадальные тесты:

|Входные данные                                                                |Выходные данные|
|------------------------------------------------------------------------------|---------------|
|You have three comma operators in each of the three terms of the for statement|B D G J K L Q W|
|qwertyuiopasdffghjklzxcvbnm                                                   |NO             |
|qwertyuiopasdffghjklzxcvb                                                     |N M            |


И краткое описание моих функций

|Функция|То, что она делает                   |
|-------|-------------------------------------|
|ord    |преобразование символа в ASCII-код   |
|char   |преобразование ASCII-кода в символ   |
|check  |поиск пустого места в массиве        |
|find   |поиск недостающих символов           |
|in     |проверка символа на наличие в массиве|

6. Протокол: 
```c
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
    

int ord(char a)
{ 
    return ("%d", a);
}


int check_vowels(int a[5])
{
    int i;
    for (i = 0; i <= 5; i++)
    {
        if (a[i] == 0){return 0;}
    }
    return 1;
}


int check_consonants(int a[20])
{
    int i;
    for (i = 0; i <= 20; i++)
    {
        if (a[i] == 0){return 0;}
    }
    return 1;
}


int inAnswer_Vowels(int list[5], char b, int c)
{
    int i;
    for (i = 0; i < c; i++)
    {
        if (list[i] == ord(b))
        {
            return 1;
        }
    }
    return 0;
}


int inAnswer_Consonants(int list[20], char b, int c)
{
    int i;
    for (i = 0; i < c; i++)
    {
        if (list[i] == ord(b))
        {
            return 1;
        }
    }
    return 0;
}


int inVowels(char b)
{
    int i;
    int vowels[] = {65, 69, 73, 79, 85, 89};
    for (i = 0; i <= 6; i++)
    {
        if (vowels[i] == ord(b))
        {
            return 1;
        }
    }
    return 0;
}


int inConsonants(char b)
{
    int i;
    int consonants[] = {66, 67, 68, 70, 71, 72, 74, 75, 76, 77, 78, 80, 81, 82, 83, 84, 86, 87, 88, 90};
    for (i = 0; i <= 21; i++)
    {
        if (consonants[i] == ord(b))
        {
            return 1;
        }
    }
    return 0;
}


char chr(int a)
{
    return ("%c", a);
}


int find_void_vowels(int a[5])
{
    int i = 0;
    while (a[i] != 0)
    {i ++;}
    return i;
}


int find_void_consonants(int a[20])
{
    int i = 0;
    while (a[i] != 0)
    {i ++;}
    return i;
}


char find_vowel(int a[5])
{
    int i, j, check;
    int vowels[] = {65, 69, 73, 79, 85, 89};
    for (i = 0; i <= 5; i++){
        check = 0;
        for (j = 0; j <= 5; j++){
            if (vowels[i] == a[j])
            {check = 1;}
        }
        if (check == 0)
        {
            a[find_void_vowels(a)] = vowels[i];
            return chr(vowels[i]);
        }
    }
    return 0;
}


char find_consonants(int a[20])
{
    int i = 0, j = 0, check;
    int consonants[] = {66, 67, 68, 70, 71, 72, 74, 75, 76, 77, 78, 80, 81, 82, 83, 84, 86, 87, 88, 90};
    for (i = 0; i <= 20; i++){
        check = 0;
        for (j = 0; j <= 20; j++){
            if (consonants[i] == a[j])
            {check = 1;}
        }
        if (check == 0){
            a[find_void_consonants(a)] = consonants[i];
            return chr(consonants[i]);
        }
    }
    return 0;
}


int main(){
    char symbol;
    int vowels_count = 0, consonant_count = 0, i = 0, answer_vowels[5], answer_consonants[20], num_symbol;
    for (i = 0; i <= 5; i++)
    {
        answer_vowels[i] = 0;
    }
    for (i = 0; i <= 21; i++)
    {
        answer_consonants[i] = 0;
    }
    while ((symbol = getchar()) != EOF)
    {
        if ((ord(symbol) != 10) && (ord(symbol) != 9)  && (ord(symbol) != 32)  && (ord(symbol) != 44))
            {
                num_symbol = ord(symbol);
                if (num_symbol >= 97) {num_symbol -= 32;}
                if ((inVowels(num_symbol)) && (inAnswer_Vowels(answer_vowels, num_symbol, vowels_count) == 0))
                {
                    answer_vowels[vowels_count] = num_symbol;
                    vowels_count ++;
                }
                if ((inConsonants(num_symbol)) && (inAnswer_Consonants(answer_consonants, num_symbol, consonant_count) == 0))
                {
                    answer_consonants[consonant_count] = num_symbol;
                    consonant_count ++;
                }
            }
    }
    if (((check_consonants(answer_consonants)) == 1) && (check_vowels(answer_vowels) == 1))
    {
        printf("%s", "NO");
    }
    if (check_consonants(answer_consonants) == 0)
    {
        printf("%s\n", "There is/are not this/these consonant/s:");
        for (i = consonant_count; i <= 19; i++)
        {
            printf("%c ", find_consonants(answer_consonants));
        }
    }
    if (check_vowels(answer_vowels) == 0)
    {
        printf("\n%s\n", "There is/are not this/these vowel/s:");
        for (i = vowels_count; i <= 5; i++)
        {
            printf("%c ", find_vowel(answer_vowels));
        }
    }
}
```
8. Выводы: хоть я и очень упростил себе задачу в этой ЛР, но поставленной цели я всё же достиг. Я-таки смог создать рабочую программу для нахождения отсутствующих английских гласных/согласных. Кроме того, мне удалось освоить некоторые приколы из языка Си, о которых я ещё не успел узнать до этого (как писать функции ord и chr, как заставить Си переваривать функции с массивами и как найти последний элемент массива).