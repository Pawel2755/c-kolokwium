#include <stdio.h>
#include <stdlib.h>





int main()
{
    int n=2;
    int **tab = malloc(n * sizeof(int *));
    for(int i=0;i<n;i++){
        tab[i] = malloc(n * sizeof(int));

    }
    tab[0][0] = 1;
    tab[0][1] = 2;
    tab[0][2] = 3;
    tab[1][0] = 4;
    tab[1][1] = 5;
    tab[1][2] = 6;

    return 0;
}
