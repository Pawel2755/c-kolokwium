#include <stdio.h>
#include <stdlib.h>

struct element {
    int x;
    struct element * next;
};


struct element* removeSecondLastWithoutHead(struct element* glowa){
    struct element* obecny = glowa;
    while(obecny->next->next->next!=NULL){
        obecny=obecny->next;
    }
    struct element* przedostatni = obecny->next;
    obecny->next = przedostatni->next;


};


int main()
{
    struct element* glowa = (struct element*)malloc(sizeof(struct element));
    struct element* el1 = (struct element*)malloc(sizeof(struct element));
    struct element* el2 = (struct element*)malloc(sizeof(struct element));
    struct element* el3 = (struct element*)malloc(sizeof(struct element));
    glowa->x=0;
    glowa->next=el1;

    el1->x=10;
    el1->next=el2;
    el2->x=20;
    el2->next=el3;
    el3->x=30;
    el3->next=NULL;

    struct element* obecny = glowa->next;

    while(obecny!=NULL){
        printf("%d\n",obecny->x);
        obecny=obecny->next;
    }
    removeSecondLastWithoutHead(glowa);
    obecny=glowa->next;
    while(obecny!=NULL){
        printf("%d\n",obecny->x);
        obecny=obecny->next;
    }


    return 0;
}
