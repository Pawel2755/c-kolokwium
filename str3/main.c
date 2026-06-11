#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Bike{
    char model[40];
    int distance_travelled;
};

struct Bike* initBike(char* model,int distance_travelled){
    if(strlen(model)<3 || distance_travelled<=0){
        return NULL;
    }
    struct Bike* rower = (struct Bike*)malloc(sizeof(struct Bike));
    strncpy(rower->model,model,39);
    rower->model[39]='\0';
    rower->distance_travelled=distance_travelled;
    return rower;


};

void increaseDistance(struct Bike* d){
    d->distance_travelled+=500;
}


int main()
{
    struct Bike* rowerzysta = initBike("Romet",1500);
    printf("%s %d\n",rowerzysta->model,rowerzysta->distance_travelled);
    increaseDistance(rowerzysta);
    printf("%s %d\n",rowerzysta->model,rowerzysta->distance_travelled);
    return 0;
}
