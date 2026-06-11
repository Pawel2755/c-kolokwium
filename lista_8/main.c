#include <stdio.h>
#include <stdlib.h>

struct element {
    int x;
    struct element * next;
};


void addLast(struct element* glowa,int a){

    if(glowa==NULL){
        printf("Blad");
        return;
    }

    struct element* el1=(struct element*)malloc(sizeof(struct element));

    el1 ->x=a;
    el1->next = NULL;

    struct element*obecny = glowa;

    while(obecny -> next != NULL){
        obecny = obecny->next;
    }
    obecny ->next=el1;


};




int main()
{
    struct element* glowa = (struct element*)malloc(sizeof(struct element));
    glowa -> next =NULL;


    addLast(glowa,5);
    printf("%d",glowa->next->x);
    addLast(glowa,7);
    printf("%d",glowa->next->next->x);


    return 0;
}
