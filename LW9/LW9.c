#include <stdio.h>
#include <math.h>


int main(){
    int i, j, l, k, i1, j1, l1, limit;
    i = -7;
    j = -19;
    l = 4;
    scanf("%d", &limit);
    for (k = 1; k <= limit; k++) {
        i1 = j1 = l1 = 0;
        if (((i * j) >= (i * l)) && ((i * j) >= (j * l)))
        {
            i1 = (i * j) % 30 + k;
        }
        else if (((i * l) >= (i * j)) && ((i * l) >= (j * l)))
        {
            i1 = (i * l) % 30 + k;
        }
        else
        {
            i1 = (j * l) % 30 + k;
        }

        if ((j - l) >= 0)
        {
            j1 = j - l; 
        }
        else
        {
            j1 = l - j;
        }
        if (i = 0)
        {
            j1 = 0;
        }
        else if (i < 0)
        {
            j1 = -j1;
        }
        if ((((i - l) >= 0) && (j > 0)) || (((i - l) < 0) && (j < 0)))
        {
            j1 = j1 - (i - l);
        }
        else if ((((i - l) < 0) && (j > 0)) || (((i - l) >= 0) && (j < 0)))
        {
            j1 = j1 - (l - i);
        }

        if ((i - l) >= (j - l))
        {
            l1 = i - l;
        }
        else
        {
            l1 = j - l;
        }
        if (l <= l1)
        {
            l1 = l;
        }
        if (j >= l1)
        {
            l1 = j;
        }
        if (i <= l1)
        {
            l1 = i;
        }
    
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
    }
}