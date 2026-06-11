#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definicja wêz³a listy jednokierunkowej
struct Node {
    int data;
    struct Node* next;
};

// Funkcja do zaimplementowania (Czêœæ 1)
bool hasCycle(struct Node *head) {
    // Twoja implementacja tutaj
    struct Node* fast = head;

    struct Node* slow = head;
    while(fast!=NULL && fast->next!= NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }

    return false;
}

// Funkcja do zaimplementowania (Czêœæ 2 - Wyzwanie)
struct Node* detectCycleStart(struct Node *head) {
    // Twoja implementacja tutaj

    return NULL;
}

// --- Funkcje pomocnicze do testowania ---

// Tworzy nowy wêze³
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Tworzenie przyk³adowej listy: 1 -> 2 -> 3 -> 4 -> 5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    struct Node* node5 = createNode(5);
    head->next->next->next->next = node5;

    // Tworzenie cyklu: wêze³ 5 wskazuje z powrotem na wêze³ 3
    node5->next = head->next->next;

    if (hasCycle(head)) {
        printf("Lista zawiera cykl!\n");
        struct Node* start = detectCycleStart(head);
        if (start != NULL) {
            printf("Cykl zaczyna sie w wezle z wartoscia: %d\n", start->data);
        }
    } else {
        printf("Lista nie zawiera cyklu.\n");
    }

    // Pamiêtaj o zwolnieniu pamiêci (choæ przy cyklu to bywa podchwytliwe!)
    return 0;
}
