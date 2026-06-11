#include <stdio.h>
#include <stdlib.h>


void replaceDigits(char tab[]){
    int i=0;
    while(tab[i]!='\0'){
        if(tab[i]>='0' && tab[i]<='9'){
            tab[i] = '#';
        }
        i++;
    }

}


int main()
{
    char tab[] = "a1b2c";
    replaceDigits(tab);
    printf("%s",tab);



    return 0;
}
