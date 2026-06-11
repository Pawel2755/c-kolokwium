#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node * next;
};

int countZero(struct node* lista){
    int i=0;
    struct node* obecny = lista;
    while(obecny!=NULL){
        if(obecny->value==0){
            i++;
        }
        obecny=obecny->next;
    }
    return i;

}


int main()
{
    struct node* el1 =(struct node*)malloc(sizeof(struct node));
    struct node* el2 =(struct node*)malloc(sizeof(struct node));
    struct node* el3 =(struct node*)malloc(sizeof(struct node));
    struct node* el4 =(struct node*)malloc(sizeof(struct node));

    el1->value=4;
    el1->next =el2;
    el2->value=0;
    el2->next =el3;
    el3->value=3;
    el3->next =el4;
    el4->value=0;
    el4->next=NULL;

    struct node* lista = el1;
    printf("%d",countZero(lista));

    return 0;
}
