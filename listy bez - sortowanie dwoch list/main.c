#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// --- Funkcje do zaimplementowania ---

// 1. Funkcja dziel¹ca listê na dwie po³owy (wskazówka: u¿yj wskaŸnika szybkiego i wolnego!)
void frontBackSplit(struct Node* source, struct Node** frontRef, struct Node** backRef) {
    // Twoja implementacja...
    struct Node* fast;
    struct Node* slow;
    slow=source;
    fast=source->next;

    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
    }
    *frontRef=source;
    *backRef = slow->next;
    slow->next=NULL;

}

// 2. Funkcja scalaj¹ca dwie posortowane listy rosn¹co
struct Node* sortedMerge(struct Node* a, struct Node* b) {
    // Twoja implementacja...
    struct Node* reasult = NULL;
    if(a==NULL){
        return b;
    }else if(b==NULL){
        return a;
    }
    if(a->data<=b->data){
        reasult=a;
        reasult->next=sortedMerge(a->next,b);
    }else{
        reasult=b;
        reasult->next=sortedMerge(a,b->next);
    }


    return reasult;
}

// 3. G³ówna funkcja rekurencyjna sortuj¹ca listê
void mergeSort(struct Node** headRef) {
    // Krok 1: Warunek brzegowy (lista pusta lub 1 element)
    // Krok 2: Podziel listê na 'a' i 'b' przy u¿yciu frontBackSplit
    // Krok 3: Wywo³aj mergeSort rekurencyjnie dla 'a' i 'b'
    // Krok 4: Scal 'a' i 'b' przy u¿yciu sortedMerge i przypisz do *headRef

    // Twoja implementacja...
    struct Node* head = *headRef;
    struct Node* a;
    struct Node* b;

    if((head==NULL)|| (head->next == NULL)){
        return;
    }
    frontBackSplit(head,&a,&b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef= sortedMerge(a,b);

}

// --- Funkcje pomocnicze ---

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* a = NULL;

    // Tworzenie nieposortowanej listy: 15 -> 10 -> 5 -> 20 -> 3 -> 2
    push(&a, 2);
    push(&a, 3);
    push(&a, 20);
    push(&a, 5);
    push(&a, 10);
    push(&a, 15);

    printf("Lista przed sortowaniem:\n");
    printList(a);

    // Sortowanie listy
    mergeSort(&a);

    printf("\nLista po sortowaniu (Merge Sort):\n");
    printList(a);

    // Zwolnienie pamiêci
    struct Node* current = a;
    struct Node* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    return 0;
}
