#include <stdio.h>
#include <stdlib.h>

struct element{
    int x;
    struct element * next;
};

struct element* odwrocenieok(struct element* lista,int k){
    struct element* obecny = lista;
    struct element* prev =NULL;
    struct element* nextt = NULL;
    int i=0;
    while(obecny!=NULL && i<k ){
        nextt=obecny->next;
        obecny->next=prev;
        prev=obecny;
        obecny=nextt;
        i++;
    }
    if(nextt!=NULL){
        lista->next=odwrocenieok(nextt,k);
    }

    return prev;
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
    printlist(odwrocenieok(lista,3));





    return 0;
}
