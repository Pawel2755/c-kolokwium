#include <stdio.h>
#include <stdlib.h>

void toLowerNew(char * tab){
    int i=0;
    while(tab[i]!='\0'){
        if(tab[i] >= 'A' && tab[i] <='Z'){
            tab[i]=tab[i] + ('a' - 'A');
        }
        i++;
    }
}


int main()
{
    char  tab[] = "Abc";
    printf("%s\n",tab);
    toLowerNew(tab);
    printf("%s",tab);
    return 0;
}
