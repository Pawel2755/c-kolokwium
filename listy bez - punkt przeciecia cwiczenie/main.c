#include <stdio.h>
#include <stdlib.h>

struct element{
    int x;
    struct element * next;
};

int dlugosc(struct element* lista){
    int i=0;
    while(lista!=NULL){
        i++;
        lista=lista->next;
    }
    return i;
}


struct element* punkt(struct element* lista1,struct element* lista2){
    struct element* wsk1 = lista1;
    struct element* wsk2 = lista2;
    int dl1 =dlugosc(lista1);
    int dl2 = dlugosc(lista2);
    if(dl1>dl2){
        int temp1 = dl1-dl2;
        for(int i=0;i<temp1;i++){
            wsk1=wsk1->next;
        }
    }else if(dl2>dl1){
        int temp2 = dl2-dl1;
        for(int i=0;i<temp2;i++){
            wsk2=wsk2->next;
        }
    }
    while(wsk1 != wsk2){
        wsk1=wsk1->next;
        wsk2=wsk2->next;
    }
    return wsk1;


};



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
    el2->next=el5;
    el3->x=3;
    el3->next=el4;
    el4->x=4;
    el4->next=el5;
    el5->x=5;
    el5->next=el6;
    el6->x=6;
    el6->next=NULL;



    struct element* lista1 = el1;

    struct element* lista2 = el3;
    struct element* punktp = punkt(lista1,lista2);
    printf("%d",punktp->x);



    return 0;
}
