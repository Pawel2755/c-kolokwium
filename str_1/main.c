#include <stdio.h>
#include <stdlib.h>

struct Airplane{
    char* model;
    int number_of_engines;
};

int numberofengines(struct Airplane arr[],int n){
    int liczbasilnikow = arr[0].number_of_engines;
    for(int i=0;i<n;i++){
        if(liczbasilnikow > arr[i].number_of_engines){
            liczbasilnikow = arr[i].number_of_engines;
        }
    }
    return liczbasilnikow;
}


int main()
{
    struct Airplane samoloty[] ={
        {"Boeing737",4},{"Boeing444",2},{"Boeing222",6}
    };
    int n = sizeof(samoloty)/sizeof(samoloty[0]);
    printf("%d",numberofengines(samoloty,n));


    return 0;
}
