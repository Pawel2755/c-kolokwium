#include <stdio.h>
#include <stdlib.h>


void transArr(int n,int **tab){
    for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        int temp = *(*(tab +i)+j);
        *(*(tab + i)+j) = *(*(tab +j)+i);
        *(*(tab +j)+i) = temp;
    }
    }

}

int main()
{
    int n=2;
    int ** tab = (int**)malloc(n* sizeof(int*));
    for(int i=0;i<n;i++){
        tab[i] = (int*)malloc(n*sizeof(int));
    }
    tab[0][0] = 1;
    tab[0][1] = 2;
    tab[1][0] = 3;
    tab[1][1] = 4;
    printf("%d\n",tab[0][1]);
    transArr(n,tab);
    printf("%d\n",tab[0][1]);
    return 0;
}
