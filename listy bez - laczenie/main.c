#include <stdio.h>
#include <stdlib.h>




struct element{
    int x;
    struct element * next;
};


void polacz(struct element* lista1,struct element* lista2){
    struct element* obecny = lista1;
    while(obecny->next!=NULL){
        obecny=obecny->next;
    }
    obecny->next=lista2;

}



void printlist(struct element* lista){
    struct element* obecny = lista;
    while(obecny!=NULL){
        printf("%d",obecny->x);
        obecny=obecny->next;

    }

}

int main()
{

    struct element* el1 = (struct element*)malloc(sizeof(struct element));
    struct element* el2 = (struct element*)malloc(sizeof(struct element));
    struct element* el3 = (struct element*)malloc(sizeof(struct element));
    struct element* el4 = (struct element*)malloc(sizeof(struct element));
    struct element* el5 = (struct element*)malloc(sizeof(struct element));

    el1->x=1;
    el1->next=el2;
    el2->x=2;
    el2->next=el3;
    el3->x=3;
    el3->next=NULL;
    el4->x=4;
    el4->next=el5;
    el5->x=5;
    el5->next=NULL;


    struct element* lista1 = el1;
    struct element* lista2 =el4;
    polacz(lista1,lista2);
    printlist(lista1);


    return 0;
}




