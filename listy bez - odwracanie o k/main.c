#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

// Funkcja pomocnicza: sprawdza, czy w liœcie zosta³o jeszcze co najmniej k elementów
bool hasKNodes(struct Node* head, int k) {
    int count = 0;
    struct Node* curr = head;
    while (curr != NULL && count < k) {
        count++;
        curr = curr->next;
    }
    return count == k;
}

// G³ówna funkcja odwracaj¹ca w grupach
struct Node* reverseKGroup(struct Node* head, int k) {
    // Warunek brzegowy: pusta lista lub k=1 (brak sensu odwracaæ)
    // Sprawdzamy te¿, czy mamy w ogóle pe³n¹ grupê k-elementow¹ do odwrócenia
    if (head == NULL || k == 1 || !hasKNodes(head, k)) {
        return head;
    }

    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;
    int count = 0;

    // Krok 1: Standardowe, iteracyjne odwrócenie dok³adnie k elementów
    while (curr != NULL && count < k) {
        next = curr->next; // Zapisujemy resztê listy
        curr->next = prev; // Odwracamy wskaŸnik
        prev = curr;       // Przesuwamy prev
        curr = next;       // Przesuwamy curr
        count++;
    }

    // Krok 2: Po odwróceniu grupy, oryginalny 'head' sta³ siê jej OSTATNI¥ wartoœci¹.
    // Teraz musimy podpi¹æ ten wêze³ do wyniku odwracania reszty listy.
    // 'next' wskazuje teraz na (k+1)-szy element listy.
    if (next != NULL) {
        head->next = reverseKGroup(next, k);
    }

    // Krok 3: 'prev' to nowa g³owa w³aœnie odwróconej podlisty (k-tej grupy).
    return prev;
}

// --- Funkcje pomocnicze do testowania ---

// Dodawanie na koniec listy (¿eby ³atwiej czytaæ wejœcie: 1->2->3...)
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Tworzymy listê: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    for (int i = 1; i <= 8; i++) {
        append(&head, i);
    }

    int k = 3;

    printf("Oryginalna lista:\n");
    printList(head);
    printf("\nOdwracanie w grupach po k = %d:\n", k);

    // Wywo³anie algorytmu
    head = reverseKGroup(head, k);

    printList(head);
    // Spodziewany wynik: 3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 7 -> 8 -> NULL

    // Zwalnianie pamiêci
    struct Node* current = head;
    struct Node* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    return 0;
}
