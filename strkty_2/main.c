#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Apartment{
    char address[100];
    int number_of_residents;
};

struct Apartment* initApartment(char*address,int mieszkancy){
    int dlugosc_adresu = strlen(address);
    if(!(dlugosc_adresu >=5 && mieszkancy >0)){
        return NULL;
    }
    struct Apartment* nowe=(struct Apartment*)malloc(sizeof(struct Apartment));
    strncpy(nowe->address, address, 99);
    nowe->number_of_residents = mieszkancy;
    return nowe;

};
void increaseResidents (struct Apartment* m){
    m -> number_of_residents += 2;

}

int main()
{
    struct Apartment* osoba = initApartment("dupafd",45);
    printf("%s %d\n",osoba->address,osoba->number_of_residents);
    return 0;
}
