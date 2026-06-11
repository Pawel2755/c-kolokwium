#include <stdio.h>
#include <stdlib.h>



int firstDiffIndex(char* a,char* b){
    int i=0;
    while(a[i]!='\0' && b[i] != '\0'){
        if(a[i]!=b[i]){
            return i;
        }
        i++;


    }
    return -1;

}

int main()
{
    char  a[] = "koteki";
    char  b[] = "koteki";
    printf("%d",firstDiffIndex(a,b));
    return 0;
}
