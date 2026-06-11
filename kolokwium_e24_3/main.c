#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Song{
    char* title;
    int length;

};


int getLength(struct Song arr[],int n){
    int temp = strlen(arr[0].title);
    int count=0;
    for(int i=0;i<n;i++){
        if(temp>strlen(arr[i].title)){
            temp=arr[i].length;
            count++;

        }
    }
    return arr[count].length;
}


int main()
{
    struct Song piosenka[] = {{"Sen",180},{"Wolnosc",240},{"Lot",150},{"Deszcz",200}};
    int n= sizeof(piosenka)/sizeof(piosenka[0]);

    printf("%d\n",getLength(piosenka,n));
    return 0;
}
