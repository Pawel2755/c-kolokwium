#include <stdio.h>
#include <stdlib.h>


int sumArray(int n,int m,int**tab){
    int suma=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            suma += *(*(tab+i)+j);
        }
    }
    return suma;

}




int main()
{
    int n=2,m=3;
    int ** tab = (int**)malloc(n* sizeof(int*));
    for(int i=0;i<n;i++){
        tab[i] = (int*)malloc(m*sizeof(int));
    }
    tab[0][0] = 1;
    tab[0][1] = 2;
    tab[0][2] = 3;
    tab[1][0] = 4;
    tab[1][1] = 5;
    tab[1][2] = 6;

    printf("%d",sumArray(n,m,tab));
    return 0;
}
