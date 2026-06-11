#include <stdio.h>
#include <stdlib.h>

struct Book{
    char* napis;
    int year;

};
int countBooksAfterYear(struct Book arr[],int n,int yearLimit){

    int count=0;
    for(int i=0;i<n;i++){
    if(arr[i].year>yearLimit){
        count++;
    }
    }
    return count;


}


int main()
{
    printf("Hello world!\n");
    return 0;
}
