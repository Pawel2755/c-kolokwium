#include <stdio.h>
#include <stdlib.h>

struct Course{
    char* name;
    int students;
};

int getTotalStudents(struct Course arr[],int n){
    int suma=0;
    for(int i=0;i<n;i++){
        suma+=arr[i].students;
    }
    return suma;

}




int main()
{
    int n=3;
    struct Course kursy[] = {
        {"Analiza",40},{"Algebra",35},{"Fizyka",20}
    };

    printf("%d",getTotalStudents(kursy,n));

    return 0;
}
