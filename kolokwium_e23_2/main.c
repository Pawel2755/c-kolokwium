#include <stdio.h>
#include <stdlib.h>


int maxElement(int** tab,int n,int m){
    int temp = *(*(tab+0)+0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(temp< *(*(tab+i)+j)){
                temp = *(*(tab+i)+j);
            }
        }
    }
    return temp;


}



int main()
{
    int n=3,m=3;
    int ** tab= (int**)malloc(sizeof(int*));
    for(int i=0;i<n;i++){
        tab[i]=(int*)malloc(sizeof(int));
    }
    tab[0][0] = 3;
    tab[0][1] = 4;
    tab[0][2] = -3;
    tab[1][0] = -3;
    tab[1][1] = 2;
    tab[1][2] = 11;
    tab[2][0] = -1;
    tab[2][1] = 8;
    tab[2][2] = 9;


    printf("%d",maxElement(tab,n,m));

    return 0;
}
