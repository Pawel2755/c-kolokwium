#include <stdio.h>
#include <stdlib.h>

struct element{
    int x;
    struct element * next;
};


int equalLast (struct element* lista1,struct element* lista2){
    if(lista1==NULL || lista2==NULL){
        return 0;
    }
    struct element* obecny1 = lista1;
    struct element* obecny2 = lista2;
    while(obecny1->next!=NULL){
        obecny1=obecny1->next;
    }
    while(obecny2->next!=NULL){
        obecny2=obecny2->next;
    }
    if(obecny1->x == obecny2->x){
        return 1;
    }
    return 0;

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
     struct element* glowa1 = (struct element*)malloc(sizeof(struct element));
     struct element* glowa2 = (struct element*)malloc(sizeof(struct element));
    struct element* el1 = (struct element*)malloc(sizeof(struct element));
    struct element* el2 = (struct element*)malloc(sizeof(struct element));
    struct element* el3 = (struct element*)malloc(sizeof(struct element));
    struct element* el4 = (struct element*)malloc(sizeof(struct element));
    struct element* el5 = (struct element*)malloc(sizeof(struct element));
    struct element* el6 = (struct element*)malloc(sizeof(struct element));
    glowa1->next=el1;
     glowa2->next=el4;
    el1->x=1;
    el1->next=el2;
    el2->x=2;
    el2->next=el3;
    el3->x=6;
    el3->next=NULL;
    el4->x=4;
    el4->next=el5;
    el5->x=5;
    el5->next=el6;
    el6->x=6;
    el6->next=NULL;



    struct element* lista = el1;
    printf("%d",equalLast(glowa1,glowa2));





    return 0;
}
