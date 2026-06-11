#include <stdio.h>
#include <stdlib.h>

int indexLastDigit (char *napis){
    int i=0;
    int j=-1;
    while(napis[i] != '\0'){
        if(napis[0] == '\0'&& napis[i] < '0'&&napis[i] >'9'){
            return -1;
        }
        if(napis[i] >= '0' && napis[i] <= '9'){
            j = i;
        }
        i++;

    }
    return j;

}


int main()
{
    char napis[] = "ABC def";
    printf("%d",indexLastDigit(napis));
    return 0;
}
