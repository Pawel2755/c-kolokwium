#include <stdio.h>
#include <stdlib.h>

struct element{
    int x;
    struct element * next;
};


void usun(struct element* glowa){
    struct element* nowy = glowa->next;
    glowa->next=nowy->next;

}



void printlist(struct element* lista){
    struct element* obecny = lista->next;
    while(obecny!=NULL){
        printf("%d",obecny->x);
        obecny=obecny->next;

    }

}

int main()
{

    struct element* glowa = (struct element*)malloc(sizeof(struct element));
    struct element* el1 = (struct element*)malloc(sizeof(struct element));
    struct element* el2 = (struct element*)malloc(sizeof(struct element));
    struct element* el3 = (struct element*)malloc(sizeof(struct element));

    glowa->next=el1;

    el1->x=1;
    el1->next=el2;
    el2->x=3;
    el2->next=el3;
    el3->x=7;
    el3->next=NULL;

    usun(glowa);
    printlist(glowa);

    return 0;
}
