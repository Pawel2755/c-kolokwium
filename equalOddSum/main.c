#include <stdio.h>
#include <stdlib.h>

struct element{
    int x;
    struct element * next;
};

int equalOddSum(struct element* lista1, struct element* lista2){
    if(lista1==NULL || lista2==NULL || lista1->next==NULL || lista2->next==NULL){
        return 0;
    }

    int suma1=0;
    int suma2=0;
    struct element* obecny1 = lista1;
    struct element* obecny2 = lista2;
    while(obecny1!=NULL){
        if(obecny1->x%2!=0){
            suma1+=obecny1->x;
        }
        obecny1=obecny1->next;
    }
    while(obecny2!=NULL){
        if(obecny2->x%2!=0){
            suma2+=obecny2->x;
        }
        obecny2=obecny2->next;
    }
    if(suma1==suma2){
        return 1;
    }else{
        return 0;
    }

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
    printf("%d",equalOddSum(glowa1,glowa2));





    return 0;
}
