#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Funkcja pomocnicza obliczaj¹ca d³ugoœæ listy
int getLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// G³ówna funkcja znajduj¹ca punkt przeciêcia
struct Node* getIntersectionNode(struct Node* headA, struct Node* headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }

    // 1. Oblicz d³ugoœci obu list
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    struct Node* ptrA = headA;
    struct Node* ptrB = headB;

    // 2. Zniweluj ró¿nicê w d³ugoœciach
    if (lenA > lenB) {
        int diff = lenA - lenB;
        for (int i = 0; i < diff; i++) {
            ptrA = ptrA->next;
        }
    } else if (lenB > lenA) {
        int diff = lenB - lenA;
        for (int i = 0; i < diff; i++) {
            ptrB = ptrB->next;
        }
    }

    // 3. Przesuwaj wskaŸniki jednoczeœnie, a¿ siê spotkaj¹
    while (ptrA != NULL && ptrB != NULL) {
        if (ptrA == ptrB) {
            return ptrA; // Znaleziono punkt przeciêcia
        }
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }

    // Jeœli pêtla siê zakoñczy³a bez znalezienia przeciêcia
    return NULL;
}

// --- Funkcje pomocnicze do testowania ---

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Wspólna czêœæ (ogon Y): 8 -> 9 -> 10
    struct Node* common = createNode(8);
    common->next = createNode(9);
    common->next->next = createNode(10);

    // Lista A: 1 -> 2 -> (wspólna czêœæ)
    struct Node* headA = createNode(1);
    headA->next = createNode(2);
    headA->next->next = common;

    // Lista B: 4 -> 5 -> 6 -> (wspólna czêœæ)
    struct Node* headB = createNode(4);
    headB->next = createNode(5);
    headB->next->next = createNode(6);
    headB->next->next->next = common;

    // Testowanie
    struct Node* intersection = getIntersectionNode(headA, headB);

    if (intersection != NULL) {
        printf("Znaleziono przeciecie w wezle o wartosci: %d\n", intersection->data);
    } else {
        printf("Listy sie nie przecinaja.\n");
    }

    // UWAGA: W pe³nym programie nale¿y ostro¿nie zwalniaæ pamiêæ,
    // aby nie spróbowaæ zwolniæ wspó³dzielonych wêz³ów (common) dwukrotnie!

    return 0;
}
