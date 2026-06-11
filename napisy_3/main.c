#include <stdio.h>
#include <stdlib.h>

int length (char *napis){
    int i=0;
    while(napis[i] != '\0'){
        i++;
    }
    return i;
}




int main()
{
    char * tab = "dupa00";
    printf("%d",length(tab));
    return 0;
}
