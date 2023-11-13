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