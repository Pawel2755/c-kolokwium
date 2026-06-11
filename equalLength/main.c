#include <stdio.h>
#include <stdlib.h>

struct element{
    int x;
    struct element * next;
};

int equalLength(struct element* lista1,struct element* lista2){
    if(lista1==NULL || lista2 == NULL){
        return 0;
    }
    struct element* obecny1 = lista1;
    struct element* obecny2 = lista2;
    int l1=0;
    int l2=0;
    while(obecny1!=NULL){
        l1++;
        obecny1=obecny1->next;
    }
    while(obecny2!=NULL){
        l2++;
        obecny2=obecny2->next;
    }
    if(l1==l2){
        return 1;
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
    el3->next=NULL;
    el4->x=4;
    el4->next=el5;
    el5->x=5;
    el5->next=el6;
    el6->x=6;
    el6->next=NULL;



    struct element* lista1 = el1;
    struct element* lista2 = el4;
    printf("%d",equalLength(lista1,lista2));






    return 0;
}
