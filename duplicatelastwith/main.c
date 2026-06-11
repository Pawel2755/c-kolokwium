#include <stdio.h>
#include <stdlib.h>

struct element{
    int x;
    struct element * next;
};

void duplicatelast(struct element* lista){
    if(lista==NULL){
        return;
    }
    struct element* obecny=lista;
    while(obecny->next!=NULL){
        obecny=obecny->next;
    }
    struct element* nowy = (struct element*)malloc(sizeof(struct element));
    nowy->x=obecny->x;
    nowy->next=NULL;
    obecny->next=nowy;


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
    struct element* el6 = (struct element*)malloc(sizeof(struct element));

    el1->x=1;
    el1->next=el2;
    el2->x=2;
    el2->next=el3;
    el3->x=3;
    el3->next=el4;
    el4->x=4;
    el4->next=el5;
    el5->x=5;
    el5->next=el6;
    el6->x=6;
    el6->next=NULL;



    struct element* lista = el1;
    duplicatelast(lista);
    printlist(lista);






    return 0;
}
