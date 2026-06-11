#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// 1. Wariant dla listy posortowanej - Z³o¿onoœæ O(n)
void removeDuplicatesSorted(struct Node* head) {
    // Pusta lista lub z jednym elementem nie ma duplikatów
    if (head == NULL) return;

    struct Node* current = head;

    // Przechodzimy przez listê, dopóki current i jego s¹siad istniej¹
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            // Znaleziono duplikat bezpoœrednio obok
            struct Node* temp = current->next;    // Zapisujemy wêze³ do usuniêcia
            current->next = temp->next;           // Przepinamy wskaŸnik omijaj¹c duplikat
            free(temp);                           // Zwalniamy pamiêæ!

            // UWAGA: Nie przesuwamy 'current' do przodu!
            // Nastêpny element te¿ mo¿e byæ duplikatem (np. 2 -> 2 -> 2)
        } else {
            // Brak duplikatu, przesuwamy wskaŸnik
            current = current->next;
        }
    }
}

// 2. Wariant dla listy nieposortowanej - Z³o¿onoœæ O(n^2)
void removeDuplicatesUnsorted(struct Node* head) {
    if (head == NULL) return;

    struct Node* current = head;

    // Zewnêtrzna pêtla wybiera element, do którego bêdziemy szukaæ duplikatów
    while (current != NULL) {
        struct Node* runner = current;

        // Wewnêtrzna pêtla szuka duplikatów dla 'current->data' w reszcie listy
        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                // Znaleziono duplikat
                struct Node* temp = runner->next;
                runner->next = temp->next; // Przepiêcie
                free(temp);                // Zwolnienie pamiêci

                // Tu równie¿ nie przesuwamy 'runner',
                // bo nowy 'runner->next' wymaga ponownego sprawdzenia
            } else {
                runner = runner->next;
            }
        }
        current = current->next; // Bierzemy kolejny element jako punkt odniesienia
    }
}

// --- Funkcje pomocnicze do testowania ---

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
    // --- Test wariantu POSORTOWANEGO ---
    struct Node* sortedList = NULL;
    push(&sortedList, 4); push(&sortedList, 4); push(&sortedList, 3);
    push(&sortedList, 2); push(&sortedList, 2); push(&sortedList, 2);
    push(&sortedList, 1);

    printf("Lista POSORTOWANA przed usunieciem:\n");
    printList(sortedList);

    removeDuplicatesSorted(sortedList);

    printf("Lista POSORTOWANA po usunieciu:\n");
    printList(sortedList);

    printf("\n-----------------------------------\n\n");

    // --- Test wariantu NIEPOSORTOWANEGO ---
    struct Node* unsortedList = NULL;
    // Wrzucamy liczby: 1, 2, 5, 2, 1, 8, 1
    push(&unsortedList, 1); push(&unsortedList, 8); push(&unsortedList, 1);
    push(&unsortedList, 2); push(&unsortedList, 5); push(&unsortedList, 2);
    push(&unsortedList, 1);

    printf("Lista NIEPOSORTOWANA przed usunieciem:\n");
    printList(unsortedList);

    removeDuplicatesUnsorted(unsortedList);

    printf("Lista NIEPOSORTOWANA po usunieciu:\n");
    printList(unsortedList);

    // W prawdziwym kodzie tu nast¹pi³oby zwolnienie ca³ej pozosta³ej pamiêci (free)
    return 0;
}
