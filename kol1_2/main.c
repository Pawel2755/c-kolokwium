#include <stdio.h>
#include <stdlib.h>

struct elem{
    int i;
    struct elem* next;
};


int countNeg(struct elem* glowa){
    int count=0;
    struct elem* obecny = glowa->next;
    while(obecny!=NULL){
        if(obecny->i<0){
            count++;
        }
        obecny=obecny->next;
    }
    return count;

}






int main()
{
    struct elem* glowa = (struct elem*)malloc(sizeof(struct elem));
    struct elem* el1 = (struct elem*)malloc(sizeof(struct elem));
    struct elem* el2 = (struct elem*)malloc(sizeof(struct elem));
    struct elem* el3 = (struct elem*)malloc(sizeof(struct elem));
    glowa -> next = el1;

    el1->i=-10;
    el1->next=el2;
    el2->i=20;
    el2->next=el3;
    el3->i=30;
    el3->next=NULL;

    printf("%d",countNeg(glowa));

    return 0;
}
