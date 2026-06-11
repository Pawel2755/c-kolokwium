#include <stdio.h>
#include <stdlib.h>

void swapItems(int n,int m, int **tab1,int **tab2){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int temp = *(*(tab2 +i)+j);
            *(*(tab2+i)+j) = *(*(tab1+i)+j);
            *(*(tab1+i)+j) = temp;
        }
    }


}


int main()
{
    int n=2,m=3;
    int **tab1 = (int**)malloc(n*sizeof(int*));
    int **tab2 = (int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        tab1[i] = (int*)malloc(m*sizeof(int));
        tab2[i] = (int*)malloc(m*sizeof(int));
    }
    tab1[0][0] = 1;
    tab1[0][1] = 2;
    tab1[0][2] = 3;
    tab1[1][0] = 4;
    tab1[1][1] = 5;
    tab1[1][2] = 6;

    tab2[0][0] = 6;
    tab2[0][1] = 5;
    tab2[0][2] = 4;
    tab2[1][0] = 3;
    tab2[1][1] = 2;
    tab2[1][2] = 1;

    printf("%d\n",tab1[0][0]);
    printf("%d\n",tab2[0][0]);
    swapItems(n,m,tab1,tab2);
    printf("%d\n",tab1[0][0]);
    printf("%d\n",tab2[0][0]);

    return 0;
}
