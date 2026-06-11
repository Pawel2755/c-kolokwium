#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Apartment{
    char address[100];
    int number_of_residents;
};

struct Apartment* initApartment(char* address,int number_of_residents){
    if(strlen(address)< 5 || number_of_residents<=0){
        return NULL;
    }

    struct Apartment* blok = (struct Apartment*)malloc(sizeof(struct Apartment));
    strncpy(blok->address,address,99);
    blok -> address[99] = '\0';
    blok->number_of_residents = number_of_residents;
    return blok;


};

void increaseResidents(struct Apartment* r){
    r->number_of_residents+=2;
}





int main()
{
    struct Apartment* mieszkanie = initApartment("Bajkowa 12",6);
    printf("%s %d\n",mieszkanie->address,mieszkanie->number_of_residents);
    return 0;
}
