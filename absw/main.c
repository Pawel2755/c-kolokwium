#include <stdio.h>
#include <stdlib.h>

struct node {
    int x;
    struct node * next;
};

void absss(struct node* lista){
    struct node* obecny = lista->next;
    if(lista==NULL){
        return;
    }
    while(obecny!=NULL){
        if(obecny->x< 0 ){
            obecny->x = -obecny->x;
        }
        obecny=obecny->next;
    }


}

void printlist(struct node* lista){
    struct node* obecny = lista->next;
    while(obecny!=NULL){
        printf("%d\n",obecny->x);
        obecny=obecny->next;

    }

}


int main()
{
    struct node* glowa = (struct node*)malloc(sizeof(struct node));
    struct node* el1 = (struct node*)malloc(sizeof(struct node));
    struct node* el2 = (struct node*)malloc(sizeof(struct node));
    struct node* el3 = (struct node*)malloc(sizeof(struct node));

    glowa->next=el1;

    el1->x=-2;
    el1->next=el2;
    el2->x=-3;
    el2->next=el3;
    el3->x=-1;
    el3->next=NULL;

    absss(glowa);
    printlist(glowa);


    return 0;
}
