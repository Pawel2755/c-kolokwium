#include <stdio.h>
#include <stdlib.h>

struct node {
    double x;
    struct node * next;
};


int findMin(struct node* lista){
    struct node* obecny = lista->next;
    if(obecny==NULL){
        return 0.0;
    }
    int temp=lista->x;
    while(obecny!=NULL){

        if(temp>obecny->x){
            temp = obecny->x;
        }
        obecny=obecny->next;

    }
    return temp;

}


void printlist(struct node* lista){
 struct node* obecny = lista;

    while(obecny!=NULL){
        printf("%d\n",obecny->x);
        obecny=obecny->next;
    }


}


int main()
{
    struct node* el1 = (struct node*)malloc(sizeof(struct node));
    struct node* el2 = (struct node*)malloc(sizeof(struct node));
    struct node* el3 = (struct node*)malloc(sizeof(struct node));

    el1->x=411;
    el1->next=el2;
    el2->x=51;
    el2->next=el3;
    el3->x=25;
    el3->next=NULL;

    struct node* lista=el1;
    printf("%d",findMin(lista));




    return 0;
}
