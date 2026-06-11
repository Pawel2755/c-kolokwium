#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* random;
};

// Funkcja klonuj¹ca listê
struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node* curr = head;

    // FAZA 1: Przeplatanie - Tworzenie kopii wêz³a tu¿ za jego orygina³em
    // Z: A -> B -> C
    // Na: A -> A' -> B -> B' -> C -> C'
    while (curr != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = curr->data;

        newNode->next = curr->next;
        curr->next = newNode;

        curr = newNode->next; // Przeskok do nastêpnego orygina³u
    }

    // FAZA 2: Kopiowanie wskaŸników 'random'
    curr = head;
    while (curr != NULL) {
        if (curr->random != NULL) {
            // Skoro curr->next to nasz klon,
            // a curr->random to oryginalny cel,
            // to curr->random->next jest klonem tego celu!
            curr->next->random = curr->random->next;
        } else {
            curr->next->random = NULL;
        }
        curr = curr->next->next; // Przeskok do nastêpnego orygina³u
    }

    // FAZA 3: Rozdzielenie (odpl¹tanie) list
    // Przywracamy orygina³ i wydobywamy sklonowan¹ listê
    curr = head;
    struct Node* clonedHead = head->next;
    struct Node* cloneCurr = clonedHead;

    while (curr != NULL) {
        curr->next = curr->next->next; // Naprawa wskaŸnika next w oryginale

        if (cloneCurr->next != NULL) {
            cloneCurr->next = cloneCurr->next->next; // Po³¹czenie klonów ze sob¹
        }

        curr = curr->next;
        cloneCurr = cloneCurr->next;
    }

    return clonedHead;
}

// --- Funkcje pomocnicze do testowania ---

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->random = NULL;
    return newNode;
}

void printListWithRandoms(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("Adres: %p | Wartosc: %d |", (void*)curr, curr->data);
        if (curr->random != NULL) {
            printf(" Random na: %d\n", curr->random->data);
        } else {
            printf(" Random na: NULL\n");
        }
        curr = curr->next;
    }
    printf("----------------------------------------\n");
}

int main() {
    // Rêczne tworzenie listy: A(1) -> B(2) -> C(3) -> D(4)
    struct Node* nodeA = createNode(1);
    struct Node* nodeB = createNode(2);
    struct Node* nodeC = createNode(3);
    struct Node* nodeD = createNode(4);

    nodeA->next = nodeB;
    nodeB->next = nodeC;
    nodeC->next = nodeD;

    // Ustawianie losowych wskaŸników
    nodeA->random = nodeC; // A celuje w C
    nodeB->random = nodeA; // B celuje w A
    nodeC->random = nodeC; // C celuje w siebie samego
    nodeD->random = NULL;  // D celuje w NULL

    printf("ORYGINALNA LISTA:\n");
    printListWithRandoms(nodeA);

    // Klonowanie
    struct Node* clonedList = copyRandomList(nodeA);

    printf("SKLONOWANA LISTA (nowe adresy w pamieci, ta sama struktura):\n");
    printListWithRandoms(clonedList);

    printf("WERYFIKACJA ORYGINALU (czy powrocil do normy):\n");
    printListWithRandoms(nodeA);

    // Pamiêtaj o zwolnieniu pamiêci OBU list w docelowym kodzie
    return 0;
}
