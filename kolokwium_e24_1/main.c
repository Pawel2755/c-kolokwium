#include <stdio.h>
#include <stdlib.h>


void toLower(char tab[]){
    int i=0;
    while(tab[i]!='\0'){
        if(tab[i]>='A' && tab[i]<='Z'){
            tab[i] = tab[i] + ('a'-'A');
        }
        i++;
    }
}



int main()
{
    char  tab[] = "AbC2";
    toLower(tab);
    printf("%s\n",tab);
    return 0;
}
