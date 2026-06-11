#include <stdio.h>
#include <stdlib.h>
struct node {
    int value;
    struct node * next;
};

struct node* removebefore(struct node* lista,int target){

    if(lista->value==target){
        return lista;
    }
    if(lista->next->value==target){
        struct node* nowy=lista;
        lista=lista->next;
        free(nowy);
        return lista;
    }
    struct node* obecny = lista;
    while(obecny->next!=NULL&& obecny->next->next!=NULL){
        if(obecny->next->next->value==target){
            struct node* dousun = obecny->next;
            obecny->next=dousun->next;
            free(dousun);
            break;
        }
        obecny=obecny->next;
    }

    return lista;

};



void printlist(struct node* lista){
    struct node* obecny = lista;
    while(obecny!=NULL){
        printf("%d",obecny->value);
        obecny=obecny->next;

    }

}


int main()
{
    struct node* el1 = (struct node*)malloc(sizeof(struct node));
    struct node* el2 = (struct node*)malloc(sizeof(struct node));
    struct node* el3 = (struct node*)malloc(sizeof(struct node));
    struct node* el4 = (struct node*)malloc(sizeof(struct node));
    struct node* el5 = (struct node*)malloc(sizeof(struct node));
    struct node* el6 = (struct node*)malloc(sizeof(struct node));

    el1->value=1;
    el1->next=el2;
    el2->value=2;
    el2->next=el3;
    el3->value=2;
    el3->next=el4;
    el4->value=4;
    el4->next=el5;
    el5->value=5;
    el5->next=el6;
    el6->value=6;
    el6->next=NULL;

    struct node* lista = el1;

    printlist(removebefore(lista,4));
    return 0;
}
