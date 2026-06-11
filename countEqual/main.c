#include <stdio.h>
#include <stdlib.h>

struct element{
    int x;
    struct element * next;
};

int countEqual(struct element* lista,int d){
    int i=0;
    struct element* obecny = lista->next;
    while(obecny!=NULL){
        if(obecny->x==d){
            i++;
        }
        obecny=obecny->next;
    }

    return i;
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
    printf("%d",countEqual(glowa,4));





    return 0;
}
