#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// G³ówna funkcja rozwi¹zuj¹ca zadanie
struct Node* oddEvenList(struct Node* head) {
    // Warunek brzegowy: pusta lista, lista z 1 lub 2 elementami
    // nie wymaga ¿adnej modyfikacji.
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return head;
    }

    struct Node* odd = head;                // Start na 1. pozycji
    struct Node* even = head->next;         // Start na 2. pozycji
    struct Node* evenHead = even;           // Zapamiêtujemy g³owê parzystych

    // Pêtla trwa dopóki istnieje parzysty wêze³ ORAZ wêze³ po nim
    // (Zabezpiecza to przed odwo³aniem siê do NULL->next w listach o parzystej d³ugoœci)
    while (even != NULL && even->next != NULL) {
        // 1. Omijamy jeden parzysty wêze³ i ³¹czymy nieparzyste ze sob¹
        odd->next = even->next;
        odd = odd->next; // Przesuwamy wskaŸnik odd do przodu

        // 2. Omijamy jeden nieparzysty wêze³ i ³¹czymy parzyste ze sob¹
        even->next = odd->next;
        even = even->next; // Przesuwamy wskaŸnik even do przodu
    }

    // 3. Po zakoñczeniu podzia³u, ³¹czymy ogon listy nieparzystej
    // z zapamiêtan¹ g³ow¹ listy parzystej
    odd->next = evenHead;

    return head; // Zwracamy zmodyfikowan¹ g³owê
}

// --- Funkcje pomocnicze do testowania ---

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    // Tworzymy przyk³adow¹ listê: 1 -> 2 -> 3 -> 4 -> 5
    // Zauwa¿, ¿e wpisane dane to te¿ 1,2,3,4,5, co pomaga œledziæ indeksy.
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Lista przed modyfikacja:\n");
    printList(head);

    head = oddEvenList(head);

    printf("\nLista po przegrupowaniu (Nieparzyste przed parzystymi):\n");
    printList(head); // Spodziewany wynik: 1 -> 3 -> 5 -> 2 -> 4 -> NULL

    // --- Drugi test dla listy o parzystej d³ugoœci (np. 1 -> 2 -> 3 -> 4) ---
    struct Node* head2 = createNode(1);
    head2->next = createNode(2);
    head2->next->next = createNode(3);
    head2->next->next->next = createNode(4);

    printf("\nLista nr 2 przed modyfikacja:\n");
    printList(head2);

    head2 = oddEvenList(head2);

    printf("\nLista nr 2 po przegrupowaniu:\n");
    printList(head2); // Spodziewany wynik: 1 -> 3 -> 2 -> 4 -> NULL

    // W prawdziwym œrodowisku nale¿y tu zwolniæ pamiêæ (free)
    return 0;
}
