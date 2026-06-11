#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node * next;
};

// Funkcja procesuj¹ca listê: wstawia przed n-te wyst¹pienie i usuwa element za nim
struct node* processBeforeNthOccurrence(struct node* head, int target, int n, struct node* newNode) {
    if (head == NULL || n <= 0) return head;

    struct node* current = head;
    struct node* prev = NULL;
    int count = 0;

    while (current != NULL) {
        if (current->value == target) {
            count++;

            // ZnaleŸliœmy n-te wyst¹pienie
            if (count == n) {
                // 1. WSTAWIANIE PRZED:
                if (prev == NULL) {
                    // Przypadek: n-te wyst¹pienie to g³owa listy
                    newNode->next = head;
                    head = newNode;
                } else {
                    // Przypadek: n-te wyst¹pienie jest w œrodku lub na koñcu
                    prev->next = newNode;
                    newNode->next = current;
                }

                // 2. USUWANIE ELEMENTU ZA 'current':
                // (current to nadal to samo n-te wyst¹pienie)
                if (current->next != NULL && current->next->value == target) {
                    struct node* toDelete = current->next;
                    current->next = toDelete->next;
                    // Nie u¿ywamy free() zgodnie z Twoim wymogiem
                }

                break; // Koñczymy po wykonaniu operacji
            }
        }
        // Przesuwamy wskaŸniki
        prev = current;
        current = current->next;
    }

    return head;
}

// ---------------------------------------------------------
// PROSTY TEST
// ---------------------------------------------------------

void printList(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Lista: 7 -> 5 -> 7 -> 9 -> 7 -> 7 -> 2 -> NULL
    struct node n7_1 = {7, NULL};
    struct node n5 = {5, NULL};
    struct node n7_2 = {7, NULL};
    struct node n9 = {9, NULL};
    struct node n7_3 = {7, NULL};
    struct node n7_4 = {7, NULL};
    struct node n2 = {2, NULL};

    n7_1.next = &n5; n5.next = &n7_2; n7_2.next = &n9;
    n9.next = &n7_3; n7_3.next = &n7_4; n7_4.next = &n2;

    struct node newNode = {99, NULL}; // Wêze³ do wstawienia przed

    printf("Przed: "); printList(&n7_1);

    // Target 7, n=3, wstawiamy 99 PRZED trzeci¹ siódemkê
    processBeforeNthOccurrence(&n7_1, 7, 3, &newNode);

    printf("Po:    "); printList(&n7_1);

    return 0;
}
