#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS


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
    else if (a = 0)
    {
        return(0);
    }
    else
    {
        return(-1);
    }
}


int main(){
    int i, j, l, k, i1, j1, l1, limit;
    i = -7;
    j = -19;
    l = 4;
    for (k = 1; k <= (scanf("%lf", &limit)); k++) {
        i1 = max(i * j, max(i * l, j * l)) % 30 + k;
        j1 = abs(j - l) * sign(i) - abs(i - l) * sign(j);
        l1 = min(i, max(j, min(l, max(i - l, j - l))));
        i = i1;
        j = j1;
        l = l1;
        printf("%d", k);
    }
}