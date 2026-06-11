#include <stdio.h>
#include <stdlib.h>


struct Book{
    char* napis;
    int year;
};

int countBooksAfterYear(struct Book arr[],int n,int yearLimit){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i].year > yearLimit){
            count++;
        }
    }return count;

}





int main()
{
    struct Book ksiazki[] = {
        {"wiedzmin",1990},{"Hobbit",2936},{"gowno",2001}
    } ;
    int n = sizeof(ksiazki)/sizeof(ksiazki[0]);
    int limit = 2000;

    printf("%d\n",countBooksAfterYear(ksiazki,n,limit));
    return 0;
}
