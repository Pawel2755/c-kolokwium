#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node * next;
};

// Funkcja pomocnicza: odwracanie listy (zwraca now¹ g³owê)
struct node* reverseList(struct node* head) {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* nextTemp = NULL;

    while (current != NULL) {
        nextTemp = current->next; // Zapisz nastêpny
        current->next = prev;     // Odwróæ wskaŸnik
        prev = current;           // Przesuñ prev
        current = nextTemp;       // Przesuñ current
    }
    return prev;
}

// G³ówna funkcja sprawdzaj¹ca palindrom
int isPalindrome(struct node* head) {
    // Pusta lista lub lista z jednym elementem jest palindromem
    if (head == NULL || head->next == NULL) {
        return 1;
    }

    // 1. ZNALEZIENIE ŒRODKA (Technika ¿ó³wia i zaj¹ca)
    struct node* slow = head;
    struct node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;          // Wolny przesuwa siê o 1
        fast = fast->next->next;    // Szybki przesuwa siê o 2
    }
    // Gdy szybki dojdzie do koñca, wolny jest na œrodku (lub na koñcu pierwszej po³owy)

    // 2. ODWRÓCENIE DRUGIEJ PO£OWY
    struct node* secondHalfHead = reverseList(slow->next);

    // 3. PORÓWNANIE OBU CZÊŒCI
    struct node* p1 = head;               // WskaŸnik na pocz¹tek pierwszej po³owy
    struct node* p2 = secondHalfHead;     // WskaŸnik na pocz¹tek odwróconej drugiej po³owy
    int isPalin = 1; // Flaga wyniku

    while (isPalin == 1 && p2 != NULL) {
        if (p1->value != p2->value) {
            isPalin = 0; // Znaleziono niezgodnoœæ
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    // 4. PRZYWRÓCENIE ORYGINALNEGO STANU LISTY (Opcjonalne, ale profesjonalne)
    slow->next = reverseList(secondHalfHead);

    return isPalin;
}

// ---------------------------------------------------------
// FUNKCJE POMOCNICZE I PRZYPADKI TESTOWE
// ---------------------------------------------------------

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void append(struct node** head_ref, int new_value) {
    struct node* newNode = createNode(new_value);
    struct node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void freeList(struct node* head) {
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Test 1: Palindrom parzysty (1 -> 2 -> 2 -> 1)
    struct node* list1 = NULL;
    append(&list1, 1);
    append(&list1, 2);
    append(&list1, 2);
    append(&list1, 1);

    printf("Test 1 (1->2->2->1): %d (Oczekiwane 1)\n", isPalindrome(list1));

    // Test 2: Palindrom nieparzysty (1 -> 2 -> 3 -> 2 -> 1)
    struct node* list2 = NULL;
    append(&list2, 1);
    append(&list2, 2);
    append(&list2, 3);
    append(&list2, 2);
    append(&list2, 1);

    printf("Test 2 (1->2->3->2->1): %d (Oczekiwane 1)\n", isPalindrome(list2));

    // Test 3: Brak palindromu (1 -> 2 -> 3 -> 4)
    struct node* list3 = NULL;
    append(&list3, 1);
    append(&list3, 2);
    append(&list3, 3);
    append(&list3, 4);

    printf("Test 3 (1->2->3->4): %d (Oczekiwane 0)\n", isPalindrome(list3));

    // Zwalnianie pamiêci
    freeList(list1);
    freeList(list2);
    freeList(list3);

    return 0;
}
