#include <stdio.h>
#include <stdlib.h>

struct element{
    int x;
    struct element * next;
};

int wykryjpetle(struct element* lista){
    if(lista== NULL || lista->next==NULL){
        return 0;
    }
    struct element* slow=lista;
    struct element* fast = lista;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return 1;
        }

    }
    return 0;

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
    el6->next=el4;



    struct element* lista = el1;
    printf("%d",wykryjpetle(lista));



    return 0;
}
