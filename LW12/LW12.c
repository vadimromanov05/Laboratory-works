#include<stdio.h>


int main(){
    int number, new_number = 0, sign = 0;
    scanf("%d", &number);
    if (number < 0)
    {
        sign = -1;
        number = - number;
    }
    else if (number > 0)
    {
        sign = 1;
    }
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
    printf("%d", new_number * sign);
}