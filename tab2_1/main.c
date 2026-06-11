#include <stdio.h>
#include <stdlib.h>


int minvalidx(int rows,int cols,int tab[rows][cols],int col){
    int min=tab[0][col];
    for(int i=0;i<rows;i++){
        if(tab[i][col] < min){
            min = tab[i][col];
        }
    }return min;


}

int main()
{
    int rows=3,cols=2,col=1;
    int tab[3][2] = {{1,5},{3,4},{5,6}};
    printf("%d",minvalidx(rows,cols,tab,col));
    return 0;
}
