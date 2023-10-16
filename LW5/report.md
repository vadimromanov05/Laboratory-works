# Отчёт по лаборатороной работе №5

---

## по курсу "Фундаметальная информатика"


Студент группы М8О-108Б-23 Романов Вадим Михайлович

Работа выполнена

Преподаватель: каф.806 Севастьянов Виктор Сергеевич

1. Тема: Программирование машин Тьюринга
2. Цель работы: составить программу машины Тьюринга в четвёрках, выполняющюю заданное действие над словами, записанными на ленте
3. Задание: перевести число из девятеричной сиситемы в троичную
4. Идея, метод, алгоритм решения задачи:
    1) перейти в начало строки
    2) "перепрыгнуть" через незначащие нули
    3) запомнить первое число в девятеричной системе счисления и стереть его
    4) перейти в конец строки и перебраться через пробел
    5) поставить это число в троичной системе счисления согласно таблицы внизу (для первых цифр незначащие нули убираются)
    6) вернуться в начало начальной строки и вернуть стёртое число
    7) те же действия проделать со всеми остальными цифрами (с п. iii по п. vi)
    8) перейти в конец новой строки и завершить работу

5. Сценарий выполнения работы:
   Список использованных мною команд на машине Тьюринга:

|Команда              |То, что она делает                                                 |
|---------------------|-------------------------------------------------------------------|
|run_to_begin         |перйти в начало строки в первый раз                                |
|run_to_digits        |"перепрыгнуть" через незначащие нули                               |
|fin_place_zero       |поставить ноль в случае ввода только n нулей                       |
|copy                 |запомнить цифру                                                    |
|jump_(digit)         |прыжок через стёртую нами цифру                                    |
|copy_(digit)         |переход в конец начальной строки                                   |
|run_(digit)          |переход в конец второй цифры и постановка там первой цифры         |
|place_(digit)        |постановка второй цифры                                            |
|come_back_(digit)    |вернуться в начало второй строки                                   |
|new_come_back_(digit)|вернуться к стёртому символу в первой строке и вернуть его на место|
|jump_2(digit)        |перейти к новой цифре                                              |
|run_to_fin           |перейти в конец новой строки для завершения работы                 |
|fin                  |завершить работу                                                   |

Тесты:

|Девятеричная система счисления|Троичная система счисления|
|------------------------------|--------------------------|
|0123456780                    |10210111220212200         |
|000123                        |10210                     |
|876543210                     |222120121110020100        |
|111                           |10101                     |
|n * '0', n in N               |0                         |

   Команды с first_ имеют тот же принцип работы, что и их "коллеги". Они нужны для постановки единицы и двойки в начало строки без нулей в начале, 
а также для незначащих нулей. Под digit подразумевается текущая цифра, которую обрабатывает программа. 
   Также для выполнения всех требований эта машина Тьюринга представлена и в формате tu4 (в отдельном файле), но там я бы ничего не смог объяснить
в наглядном виде. Поэтому в протоколе представлена "очеловеченная версия" машины Тьюринга.

6. Протокол
```txt
00, ,<,run_to_begin

run_to_begin,0,<,run_to_begin run_to_begin,1,<,run_to_begin run_to_begin,2,<,run_to_begin run_to_begin,3,<,run_to_begin run_to_begin,4,<,run_to_begin run_to_begin,5,<,run_to_begin run_to_begin,6,<,run_to_begin run_to_begin,7,<,run_to_begin run_to_begin,8,<,run_to_begin run_to_begin, ,>,run_to_digits
//идём в начало строки


74, ,>,run_to_digits

run_to_digits,0,>,run_to_digits run_to_digits,1,=,copy_first run_to_digits,2,=,copy_first
run_to_digits,3,=,copy_first run_to_digits,4,=,copy_first run_to_digits,5,=,copy_first
run_to_digits,6,=,copy_first run_to_digits,7,=,copy_first run_to_digits,8,=,copy_first
run_to_digits, ,>,fin_place_zero


75, ,>,fin_place_zero

fin_place_zero, ,0,run_to_fin
//подарок специально для Вас на случай, если Вы миллион нулей перед числом поставите и ничего другого не будет.


01, ,>,copy

copy,0, ,jump_zero  copy,1, ,jump_one  copy,2, ,jump_two  copy,3, ,jump_three  copy,4, ,jump_four
copy,5, ,jump_five  copy,6, ,jump_six  copy,7, ,jump_seven  copy,8, ,jump_eight  copy, ,>,run_to_fin
//считываем число и стираем его (Зайцев разрешал)


02, ,>,jump_zero

jump_zero, ,>,copy_zero
//перепрыгиваем через пробел


03, ,>,copy_zero

copy_zero,0,>,copy_zero copy_zero,1,>,copy_zero copy_zero,2,>,copy_zero copy_zero,3,>,copy_zero
copy_zero,4,>,copy_zero copy_zero,5,>,copy_zero copy_zero,6,>,copy_zero copy_zero,7,>,copy_zero
copy_zero,8,>,copy_zero copy_zero, ,>,run_zero
//идём вдоль начальной строки до пробела


04, ,>,run_zero

run_zero,0,>,run_zero run_zero,1,>,run_zero run_zero,2,>,run_zero run_zero,3,>,run_zero 
run_zero,4,>,run_zero run_zero,5,>,run_zero run_zero,6,>,run_zero run_zero,7,>,run_zero
run_zero,8,>,run_zero run_zero, ,0,place_zero
//веселимся после пробела в новой строке и в конце ставим 00


05, ,>,place_zero

place_zero,0,>,place_zero place_zero, ,0,come_back_zero


06, ,<,come_back_zero

come_back_zero,0,<,come_back_zero come_back_zero,1,<,come_back_zero come_back_zero,2,<,come_back_zero
come_back_zero,3,<,come_back_zero come_back_zero,4,<,come_back_zero come_back_zero,5,<,come_back_zero
come_back_zero,6,<,come_back_zero come_back_zero,7,<,come_back_zero come_back_zero,8,<,come_back_zero
come_back_zero, ,<,new_come_back_zero
//возвращаемся к началу нового числа


07, ,<,new_come_back_zero

new_come_back_zero,0,<,new_come_back_zero new_come_back_zero,1,<,new_come_back_zero new_come_back_zero,2,<,new_come_back_zero new_come_back_zero,3,<,new_come_back_zero
new_come_back_zero,4,<,new_come_back_zero new_come_back_zero,5,<,new_come_back_zero
new_come_back_zero,6,<,new_come_back_zero new_come_back_zero,7,<,new_come_back_zero
new_come_back_zero,8,<,new_come_back_zero new_come_back_zero, ,0,jump_2_zero
//возвращаемся к букве, которую мы стёрли (цифра - это тоже буква), и возвращаем её на место (точь в точь по Зайцеву)


08, ,>,jump_2_zero

jump_2_zero,0,>,copy
//переходим к новой букве (цифре)

//с нулём всё!


09, ,>,jump_one
jump_one, ,>,copy_one
//перепрыгиваем через пробел


10, ,>,copy_one

copy_one,0,>,copy_one copy_one,1,>,copy_one copy_one,2,>,copy_one copy_one,3,>,copy_one
copy_one,4,>,copy_one copy_one,5,>,copy_one copy_one,6,>,copy_one copy_one,7,>,copy_one
copy_one,8,>,copy_one copy_one, ,>,run_one
//идём вдоль начальной строки до пробела


11, ,>,run_one

run_one,0,>,run_one run_one,1,>,run_one run_one,2,>,run_one run_one,3,>,run_one 
run_one,4,>,run_one run_one,5,>,run_one run_one,6,>,run_one run_one,7,>,run_one
run_one,8,>,run_one run_one, ,0,place_one
//веселимся после пробела в новой строке и в конце ставим 01


12, ,>,place_one

place_one,0,>,place_one place_one, ,1,come_back_one


13, ,<,come_back_one

come_back_one,0,<,come_back_one come_back_one,1,<,come_back_one come_back_one,2,<,come_back_one
come_back_one,3,<,come_back_one come_back_one,4,<,come_back_one come_back_one,5,<,come_back_one
come_back_one,6,<,come_back_one come_back_one,7,<,come_back_one come_back_one,8,<,come_back_one
come_back_one, ,<,new_come_back_one
//возвращаемся к началу нового числа


14, ,<,new_come_back_one

new_come_back_one,0,<,new_come_back_one new_come_back_one,1,<,new_come_back_one
new_come_back_one,2,<,new_come_back_one new_come_back_one,3,<,new_come_back_one
new_come_back_one,4,<,new_come_back_one new_come_back_one,5,<,new_come_back_one
new_come_back_one,6,<,new_come_back_one new_come_back_one,7,<,new_come_back_one
new_come_back_one,8,<,new_come_back_one new_come_back_one, ,1,jump_2_one
//возвращаемся к букве, которую мы стёрли (цифра - это тоже буква), и возвращаем её на место (точь в точь по Зайцеву)


15, ,>,jump_2_one
jump_2_one,1,>,copy
//переходим к новой букве (цифре)

//с единицей всё!


16, ,>,jump_two
jump_two, ,>,copy_two


17, ,>,copy_two

copy_two,0,>,copy_two copy_two,1,>,copy_two copy_two,2,>,copy_two copy_two,3,>,copy_two
copy_two,4,>,copy_two copy_two,5,>,copy_two copy_two,6,>,copy_two copy_two,7,>,copy_two
copy_two,8,>,copy_two copy_two, ,>,run_two
//идём вдоль начальной строки до пробела


18, ,>,run_two

run_two,0,>,run_two run_two,1,>,run_two run_two,2,>,run_two run_two,3,>,run_two 
run_two,4,>,run_two run_two,5,>,run_two run_two,6,>,run_two run_two,7,>,run_two
run_two,8,>,run_two run_two, ,0,place_two
//веселимся после пробела в новой строке и в конце ставим 02


19, ,>,place_two
place_two,0,>,place_two place_two, ,2,come_back_two


20, ,<,come_back_two

come_back_two,0,<,come_back_two come_back_two,1,<,come_back_two come_back_two,2,<,come_back_two
come_back_two,3,<,come_back_two come_back_two,4,<,come_back_two come_back_two,5,<,come_back_two
come_back_two,6,<,come_back_two come_back_two,7,<,come_back_two come_back_two,8,<,come_back_two
come_back_two, ,<,new_come_back_two
//возвращаемся к началу нового числа


21, ,<,new_come_back_two

new_come_back_two,0,<,new_come_back_two new_come_back_two,1,<,new_come_back_two
new_come_back_two,2,<,new_come_back_two new_come_back_two,3,<,new_come_back_two
new_come_back_two,4,<,new_come_back_two new_come_back_two,5,<,new_come_back_two
new_come_back_two,6,<,new_come_back_two new_come_back_two,7,<,new_come_back_two
new_come_back_two,8,<,new_come_back_two new_come_back_two, ,2,jump_2_two
//возвращаемся к букве, которую мы стёрли (цифра - это тоже буква), и возвращаем её на место (точь в точь по Зайцеву)


22, ,>,jump_2_two
jump_2_two,2,>,copy
//переходим к новой букве (цифре)

//с двойкой всё!


23, ,>,jump_three
jump_three, ,>,copy_three
//перепрыгиваем через пробел


24, ,>,copy_three

copy_three,0,>,copy_three copy_three,1,>,copy_three copy_three,2,>,copy_three copy_three,3,>,copy_three
copy_three,4,>,copy_three copy_three,5,>,copy_three copy_three,6,>,copy_three copy_three,7,>,copy_three
copy_three,8,>,copy_three copy_three, ,>,run_three
//идём вдоль начальной строки до пробела


25, ,>,run_three

run_three,0,>,run_three run_three,1,>,run_three run_three,2,>,run_three run_three,3,>,run_three 
run_three,4,>,run_three run_three,5,>,run_three run_three,6,>,run_three run_three,7,>,run_three
run_three,8,>,run_three run_three, ,1,place_three

26, ,>,place_three

place_three,1,>,place_three place_three, ,0,come_back_three
//веселимся после пробела в новой строке и в конце ставим 10


27, ,<,come_back_three

come_back_three,0,<,come_back_three come_back_three,1,<,come_back_three 
come_back_three,2,<,come_back_three come_back_three,3,<,come_back_three 
come_back_three,4,<,come_back_three come_back_three,5,<,come_back_three
come_back_three,6,<,come_back_three come_back_three,7,<,come_back_three
come_back_three,8,<,come_back_three come_back_three, ,<,new_come_back_three
//возвращаемся к началу нового числа


28, ,<,new_come_back_three

new_come_back_three,0,<,new_come_back_three new_come_back_three,1,<,new_come_back_three new_come_back_three,2,<,new_come_back_three new_come_back_three,3,<,new_come_back_three
new_come_back_three,4,<,new_come_back_three new_come_back_three,5,<,new_come_back_three
new_come_back_three,6,<,new_come_back_three new_come_back_three,7,<,new_come_back_three
new_come_back_three,8,<,new_come_back_three new_come_back_three, ,3,jump_2_three
//возвращаемся к букве, которую мы стёрли (цифра - это тоже буква), и возвращаем её на место (точь в точь по Зайцеву)

29, ,>,jump_2_three
jump_2_three,3,>,copy
//переходим к новой букве (цифре)

//с тройкой всё!


30, ,>,jump_four
jump_four, ,>,copy_four
//перепрыгиваем через пробел


31, ,>,copy_four

copy_four,0,>,copy_four copy_four,1,>,copy_four copy_four,2,>,copy_four copy_four,3,>,copy_four
copy_four,4,>,copy_four copy_four,5,>,copy_four copy_four,6,>,copy_four copy_four,7,>,copy_four
copy_four,8,>,copy_four copy_four, ,>,run_four
//идём вдоль начальной строки до пробела


32, ,>,run_four

run_four,0,>,run_four run_four,1,>,run_four run_four,2,>,run_four run_four,3,>,run_four 
run_four,4,>,run_four run_four,5,>,run_four run_four,6,>,run_four run_four,7,>,run_four
run_four,8,>,run_four run_four, ,1,place_four


33, ,>,place_four

place_four,1,>,place_four place_four, ,1,come_back_four
//веселимся после пробела в новой строке и в конце ставим 11


34, ,<,come_back_four

come_back_four,0,<,come_back_four come_back_four,1,<,come_back_four 
come_back_four,2,<,come_back_four come_back_four,3,<,come_back_four
come_back_four,4,<,come_back_four come_back_four,5,<,come_back_four
come_back_four,6,<,come_back_four come_back_four,7,<,come_back_four
come_back_four,8,<,come_back_four come_back_four, ,<,new_come_back_four
//возвращаемся к началу нового числа


35, ,<,new_come_back_four

new_come_back_four,0,<,new_come_back_four new_come_back_four,1,<,new_come_back_four new_come_back_four,2,<,new_come_back_four new_come_back_four,3,<,new_come_back_four
new_come_back_four,4,<,new_come_back_four new_come_back_four,5,<,new_come_back_four
new_come_back_four,6,<,new_come_back_four new_come_back_four,7,<,new_come_back_four
new_come_back_four,8,<,new_come_back_four new_come_back_four, ,4,jump_2_four
//возвращаемся к букве, которую мы стёрли (цифра - это тоже буква), и возвращаем её на место (точь в точь по Зайцеву)


36, ,>,jump_2_four
jump_2_four,4,>,copy
//переходим к новой букве (цифре)

//с четвёркой всё!


37, ,>,jump_five
jump_five, ,>,copy_five
//перепрыгиваем через пробел


38, ,>,copy_five

copy_five,0,>,copy_five copy_five,1,>,copy_five copy_five,2,>,copy_five copy_five,3,>,copy_five
copy_five,4,>,copy_five copy_five,5,>,copy_five copy_five,6,>,copy_five copy_five,7,>,copy_five
copy_five,8,>,copy_five copy_five, ,>,run_five
//идём вдоль начальной строки до пробела


39, ,>,run_five

run_five,0,>,run_five run_five,1,>,run_five run_five,2,>,run_five run_five,3,>,run_five 
run_five,4,>,run_five run_five,5,>,run_five run_five,6,>,run_five run_five,7,>,run_five
run_five,8,>,run_five run_five, ,1,place_five


40, ,>,place_five

place_five,1,>,place_five place_five, ,2,come_back_five
//веселимся после пробела в новой строке и в конце ставим 12


41, ,<,come_back_five

come_back_five,0,<,come_back_five come_back_five,1,<,come_back_five 
come_back_five,2,<,come_back_five come_back_five,3,<,come_back_five
come_back_five,4,<,come_back_five come_back_five,5,<,come_back_five
come_back_five,6,<,come_back_five come_back_five,7,<,come_back_five
come_back_five,8,<,come_back_five come_back_five, ,<,new_come_back_five
//возвращаемся к началу нового числа


42, ,<,new_come_back_five

new_come_back_five,0,<,new_come_back_five new_come_back_five,1,<,new_come_back_five new_come_back_five,2,<,new_come_back_five new_come_back_five,3,<,new_come_back_five
new_come_back_five,4,<,new_come_back_five new_come_back_five,5,<,new_come_back_five
new_come_back_five,6,<,new_come_back_five new_come_back_five,7,<,new_come_back_five
new_come_back_five,8,<,new_come_back_five new_come_back_five, ,5,jump_2_five
//возвращаемся к букве, которую мы стёрли (цифра - это тоже буква), и возвращаем её на место (точь в точь по Зайцеву)


43, ,>,jump_2_five
jump_2_five,5,>,copy
//переходим к новой букве (цифре)

//с пятёркой всё!


44, ,>,jump_six
jump_six, ,>,copy_six
//перепрыгиваем через пробел


45, ,>,copy_six

copy_six,0,>,copy_six copy_six,1,>,copy_six copy_six,2,>,copy_six copy_six,3,>,copy_six
copy_six,4,>,copy_six copy_six,5,>,copy_six copy_six,6,>,copy_six copy_six,7,>,copy_six
copy_six,8,>,copy_six copy_six, ,>,run_six
//идём вдоль начальной строки до пробела


46, ,>,run_six

run_six,0,>,run_six run_six,1,>,run_six run_six,2,>,run_six run_six,3,>,run_six 
run_six,4,>,run_six run_six,5,>,run_six run_six,6,>,run_six run_six,7,>,run_six
run_six,8,>,run_six run_six, ,2,place_six


47, ,>,place_six

place_six,2,>,place_six place_six, ,0,come_back_six
//веселимся после пробела в новой строке и в конце ставим 20


48, ,<,come_back_six

come_back_six,0,<,come_back_six come_back_six,1,<,come_back_six 
come_back_six,2,<,come_back_six come_back_six,3,<,come_back_six
come_back_six,4,<,come_back_six come_back_six,5,<,come_back_six
come_back_six,6,<,come_back_six come_back_six,7,<,come_back_six
come_back_six,8,<,come_back_six come_back_six, ,<,new_come_back_six
//возвращаемся к началу нового числа


49, ,<,new_come_back_six

new_come_back_six,0,<,new_come_back_six new_come_back_six,1,<,new_come_back_six 
new_come_back_six,2,<,new_come_back_six new_come_back_six,3,<,new_come_back_six 
new_come_back_six,4,<,new_come_back_six new_come_back_six,5,<,new_come_back_six 
new_come_back_six,6,<,new_come_back_six new_come_back_six,7,<,new_come_back_six 
new_come_back_six,8,<,new_come_back_six new_come_back_six, ,6,jump_2_six
//возвращаемся к букве, которую мы стёрли (цифра - это тоже буква), и возвращаем её на место (точь в точь по Зайцеву)


50, ,>,jump_2_six
jump_2_six,6,>,copy
//переходим к новой букве (цифре)

//с шестёркой всё!


51, ,>,jump_seven
jump_seven, ,>,copy_seven
//перепрыгиваем через пробел


52, ,>,copy_seven

copy_seven,0,>,copy_seven copy_seven,1,>,copy_seven copy_seven,2,>,copy_seven copy_seven,3,>,copy_seven
copy_seven,4,>,copy_seven copy_seven,5,>,copy_seven copy_seven,6,>,copy_seven copy_seven,7,>,copy_seven
copy_seven,8,>,copy_seven copy_seven, ,>,run_seven
//идём вдоль начальной строки до пробела


53, ,>,run_seven

run_seven,0,>,run_seven run_seven,1,>,run_seven run_seven,2,>,run_seven run_seven,3,>,run_seven 
run_seven,4,>,run_seven run_seven,5,>,run_seven run_seven,6,>,run_seven run_seven,7,>,run_seven
run_seven,8,>,run_seven run_seven, ,2,place_seven


54, ,>,place_seven

place_seven,2,>,place_seven place_seven, ,1,come_back_seven
//веселимся после пробела в новой строке и в конце ставим 21


55, ,<,come_back_seven

come_back_seven,0,<,come_back_seven come_back_seven,1,<,come_back_seven 
come_back_seven,2,<,come_back_seven come_back_seven,3,<,come_back_seven
come_back_seven,4,<,come_back_seven come_back_seven,5,<,come_back_seven
come_back_seven,6,<,come_back_seven come_back_seven,7,<,come_back_seven
come_back_seven,8,<,come_back_seven come_back_seven, ,<,new_come_back_seven
//возвращаемся к началу нового числа


56, ,<,new_come_back_seven

new_come_back_seven,0,<,new_come_back_seven new_come_back_seven,1,<,new_come_back_seven new_come_back_seven,2,<,new_come_back_seven new_come_back_seven,3,<,new_come_back_seven 
new_come_back_seven,4,<,new_come_back_seven new_come_back_seven,5,<,new_come_back_seven 
new_come_back_seven,6,<,new_come_back_seven new_come_back_seven,7,<,new_come_back_seven 
new_come_back_seven,8,<,new_come_back_seven new_come_back_seven, ,7,jump_2_seven
//возвращаемся к букве, которую мы стёрли (цифра - это тоже буква), и возвращаем её на место (точь в точь по Зайцеву)


57, ,>,jump_2_seven
jump_2_seven,7,>,copy
//переходим к новой букве (цифре)

//с семёркой всё!


58, ,>,jump_eight
jump_eight, ,>,copy_eight
//перепрыгиваем через пробел


59, ,>,copy_eight

copy_eight,0,>,copy_eight copy_eight,1,>,copy_eight copy_eight,2,>,copy_eight copy_eight,3,>,copy_eight
copy_eight,4,>,copy_eight copy_eight,5,>,copy_eight copy_eight,6,>,copy_eight copy_eight,7,>,copy_eight
copy_eight,8,>,copy_eight copy_eight, ,>,run_eight
//идём вдоль начальной строки до пробела


60, ,>,run_eight

run_eight,0,>,run_eight run_eight,1,>,run_eight run_eight,2,>,run_eight run_eight,3,>,run_eight 
run_eight,4,>,run_eight run_eight,5,>,run_eight run_eight,6,>,run_eight run_eight,7,>,run_eight
run_eight,8,>,run_eight run_eight, ,2,place_eight


61, ,>,place_eight

place_eight,2,>,place_eight place_eight, ,2,come_back_eight
//веселимся после пробела в новой строке и в конце ставим 22


62, ,<,come_back_eight

come_back_eight,0,<,come_back_eight come_back_eight,1,<,come_back_eight 
come_back_eight,2,<,come_back_eight come_back_eight,3,<,come_back_eight
come_back_eight,4,<,come_back_eight come_back_eight,5,<,come_back_eight
come_back_eight,6,<,come_back_eight come_back_eight,7,<,come_back_eight
come_back_eight,8,<,come_back_eight come_back_eight, ,<,new_come_back_eight
//возвращаемся к началу нового числа


63, ,<,new_come_back_eight

new_come_back_eight,0,<,new_come_back_eight new_come_back_eight,1,<,new_come_back_eight new_come_back_eight,2,<,new_come_back_eight new_come_back_eight,3,<,new_come_back_eight 
new_come_back_eight,4,<,new_come_back_eight new_come_back_eight,5,<,new_come_back_eight 
new_come_back_eight,6,<,new_come_back_eight new_come_back_eight,7,<,new_come_back_eight 
new_come_back_eight,8,<,new_come_back_eight new_come_back_eight, ,8,jump_2_eight
//возвращаемся к букве, которую мы стёрли (цифра - это тоже буква), и возвращаем её на место (точь в точь по Зайцеву)


64, ,>,jump_2_eight
jump_2_eight,8,>,copy
//переходим к новой букве (цифре)

//с восьмёркой всё!


65, ,>,copy_first

copy_first,0,>,copy copy_first,1, ,jump_first_one copy_first,2, ,jump_first_two
copy_first,3, ,jump_three copy_first,4, ,jump_four copy_first,5, ,jump_five
copy_first,6, ,jump_six copy_first,7, ,jump_seven copy_first,8, ,jump_eight
copy_first, ,>,run_to_fin


66, ,>,jump_first_one

jump_first_one, ,>,copy_first_one


67, ,>,copy_first_one

copy_first_one,0,>,copy_first_one copy_first_one,1,>,copy_first_one copy_first_one,2,>,copy_first_one
copy_first_one,3,>,copy_first_one copy_first_one,4,>,copy_first_one copy_first_one,5,>,copy_first_one
copy_first_one,6,>,copy_first_one copy_first_one,7,>,copy_first_one copy_first_one,8,>,copy_first_one
copy_first_one, ,>,run_first_one


68, ,>,run_first_one

run_first_one,0,>,run_first_one run_first_one,1,>,run_first_one run_first_one,2,>,run_first_one
run_first_one,3,>,run_first_one run_first_one,4,>,run_first_one run_first_one,5,>,run_first_one
run_first_one,6,>,run_first_one run_first_one,7,>,run_first_one run_first_one,8,>,run_first_one
run_first_one, ,1,come_back_one

// первая постановка единицы


69, ,>,jump_first_two

jump_first_two, ,>,copy_first_two


70, ,>,copy_first_two

copy_first_two,0,>,copy_first_two copy_first_two,1,>,copy_first_two copy_first_two,2,>,copy_first_two
copy_first_two,3,>,copy_first_two copy_first_two,4,>,copy_first_two copy_first_two,5,>,copy_first_two
copy_first_two,6,>,copy_first_two copy_first_two,7,>,copy_first_two copy_first_two,8,>,copy_first_two
copy_first_two, ,>,run_first_two


71, ,>,run_first_two

run_first_two,0,>,run_first_two run_first_two,1,>,run_first_two run_first_two,2,>,run_first_two
run_first_two,3,>,run_first_two run_first_two,4,>,run_first_two run_first_two,5,>,run_first_two
run_first_two,6,>,run_first_two run_first_two,7,>,run_first_two run_first_two,8,>,run_first_two
run_first_two, ,1,come_back_two

// первая постановка двойки


72, ,>,run_to_fin

run_to_fin,0,>,run_to_fin run_to_fin,1,>,run_to_fin run_to_fin,2,>,run_to_fin run_to_fin,3,>,run_to_fin
run_to_fin,4,>,run_to_fin run_to_fin,5,>,run_to_fin run_to_fin,6,>,run_to_fin run_to_fin,7,>,run_to_fin
run_to_fin,8,>,run_to_fin run_to_fin, ,=,fin
//идём к концу второй строки, чтобы завершить работу


73, ,#,fin
fin, ,#,fin
//завершаем работу
```

8. Вывод: это было очень весёлая, страшная и тяжёлая лабораторная работа одновременно. Пришлось методом проб и ошибок учиться программировать на эмуляторе машины Тьюринга (Яндекс ещё не развился до курсов по этой теме, да и в остальном Интернете информации тоже особенно не было). Пусть и не сразу, но с помощью информации из лекций Зайцева Валентина Евгениевича удалось научиться копировать числа в нормированном виде. Программа очень тяжёлая, громоздкая, но рабочая (я не смог её сломать). Предстоит много работы в этом направлении. Может быть, есть даже способ копировать всю строку разом, а не по цифре.