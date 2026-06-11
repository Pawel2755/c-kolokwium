#include <stdio.h>
#include <stdlib.h>

void swap2nd(int n,int m, int **tab){
    if(n<4){
        return;
    }
    for(int j=0;j<m;j++){
        int temp = *(*(tab+1)+j);
        *(*(tab+1)+j) = *(*(tab+(n-2))+j);
        *(*(tab+(n-2))+j) = temp;
    }

}




int main()
{
    int n=5,m=3;
    int **tab = (int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        tab[i] = (int*)malloc(m*sizeof(int));
    }
    tab[0][0] =1;
    tab[0][1] =2;
    tab[0][2] =3;
    tab[1][0] =4;
    tab[1][1] =5;
    tab[1][2] =6;
    tab[2][0] =7;
    tab[2][1] =8;
    tab[2][2] =9;
    tab[3][0] =10;
    tab[3][1] =11;
    tab[3][2] =12;
    tab[4][0] =13;
    tab[4][1] =14;
    tab[4][2] =15;

    printf("%d\n",tab[1][0]);
    printf("%d\n",tab[3][0]);
    swap2nd(n,m,tab);
    printf("%d\n",tab[1][0]);
    printf("%d\n",tab[3][0]);
    return 0;
}
