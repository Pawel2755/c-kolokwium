#include <stdio.h>
#include <stdlib.h>

struct element{
    int x;
    struct element * next;
};

void addTwo(struct element* lista,int a,int b){
    struct element* nowy1 = (struct element*)malloc(sizeof(struct element));
    struct element* nowy2 = (struct element*)malloc(sizeof(struct element));
    nowy1->x=a;
    nowy2->x=b;
    nowy2->next=lista->next->next;
    nowy1->next=nowy2;
    lista->next=nowy1;


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
    struct element* el4 = (struct element*)malloc(sizeof(struct element));
    struct element* el5 = (struct element*)malloc(sizeof(struct element));
    struct element* el6 = (struct element*)malloc(sizeof(struct element));
    glowa->next=el1;

    el1->x=4;
    el1->next=el2;
    el2->x=4;
    el2->next=el3;
    el3->x=4;
    el3->next=el4;
    el4->x=4;
    el4->next=el5;
    el5->x=4;
    el5->next=el6;
    el6->x=4;
    el6->next=NULL;



    struct element* lista = el1;
    addTwo(glowa,7,8);
    printlist(glowa);





    return 0;
}
