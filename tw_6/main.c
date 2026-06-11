#include <stdio.h>
#include <stdlib.h>

void sortRows(int n,int m,int**tab){
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            for(int k=0;k<m-j-1;k++){
            if(*(*(tab +i)+k)> *(*(tab+(i))+(k+1))){
                int temp = *(*(tab +i)+k);
                *(*(tab +i)+k) = *(*(tab+(i))+(k+1));
                *(*(tab+(i))+(k+1)) = temp;
            }
            }
        }
    }

}




int main()
{
    int n=2,m=3;
    int ** tab = (int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        tab[i] = (int*)malloc(m*sizeof(int));
    }
    tab[0][0] = 6;
    tab[0][1] = 6;
    tab[0][2] = 3;
    tab[1][0] = 4;
    tab[1][1] = 5;
    tab[1][2] = 5;

    printf("%d\n",tab[0][0]);
    sortRows(n,m,tab);
    printf("%d\n",tab[0][0]);
    return 0;
}
