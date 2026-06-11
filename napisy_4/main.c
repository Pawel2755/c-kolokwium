#include <stdio.h>
#include <stdlib.h>

int cmpStrNew(char tab1[],char tab2[]){
    int i=0;
    while(tab1[i]==tab2[i]){
        if(tab1[i] == '\0'){
            return 1;
        }
        i++;
    }
    return 0;

}



int main()
{
    char tab1[] = "abc";
    char tab2[] = "abc";
    printf("%d",cmpStrNew(tab1,tab2));
    return 0;
}
