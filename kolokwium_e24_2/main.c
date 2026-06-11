#include <stdio.h>
#include <stdlib.h>

int sumBelowMainDiag(int** tab,int n){
    int suma=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            suma +=tab[i][j];
        }
    }
    return suma;

}



int main()
{
    int n=3;
    int ** tab= (int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        tab[i]=(int*)malloc(n*sizeof(int));
    }
    tab[0][0] = 3;
    tab[0][1] = -4;
    tab[0][2] = 5;
    tab[1][0] = 1;
    tab[1][1] = -2;
    tab[1][2] = -33;
    tab[2][0] = -3;
    tab[2][1] = 5;
    tab[2][2] = 7;

    printf("%d",sumBelowMainDiag(tab,n));

    return 0;
}
