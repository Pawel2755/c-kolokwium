#include <stdio.h>
#include <stdlib.h>

void sqEndCols(int n,int m,int **tab){
    for(int i=0;i<n;i++){
        *(*(tab+i)+(m-1)) = ( *(*(tab+i)+(m-1)) *  *(*(tab+i)+(m-1)));
    }


}


int main()
{
    int n=2,m=3;
    int ** tab = (int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        tab[i] = (int*)malloc(m*sizeof(int));
    }
    tab[0][0] = 1;
    tab[0][1] = 2;
    tab[0][2] = 3;
    tab[1][0] = 4;
    tab[1][1] = 5;
    tab[1][2] = 6;

    printf("%d\n",tab[1][2]);
    sqEndCols(n,m,tab);
    printf("%d\n",tab[1][2]);
    return 0;
}
