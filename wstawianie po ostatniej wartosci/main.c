#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node * next;
};

// Funkcja wstawiaj¹ca nowy element PRZED ostatnim wyst¹pieniem 'target'
struct node* insertBeforeLastOccurrence(struct node* head, int target, int new_value) {
    struct node* last = NULL;         // Ostatnie wyst¹pienie
    struct node* prev_to_last = NULL; // Element TU¯ PRZED ostatnim wyst¹pieniem

    struct node* current = head;
    struct node* prev_current = NULL; // Idzie krok za current

    // 1. Przeszukiwanie listy
    while (current != NULL) {
        if (current->value == target) {
            last = current;
            prev_to_last = prev_current; // Zapamiêtujemy, co by³o przed 'last'
        }
        // Przesuwamy oba wskaŸniki do przodu
        prev_current = current;
        current = current->next;
    }

    // 2. Wstawianie elementu (jeœli znaleziono)
    if (last != NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Blad alokacji pamieci!\n");
            return head;
        }
        newNode->value = new_value;

        // Przypadek A: Ostatnie wyst¹pienie jest na samej g³owie listy
        if (prev_to_last == NULL) {
            newNode->next = head; // Nowy element wskazuje na star¹ g³owê
            return newNode;       // Zwracamy nowy element jako NOW¥ g³owê listy
        }
        // Przypadek B: Ostatnie wyst¹pienie jest gdzieœ w œrodku lub na koñcu
        else {
            newNode->next = last;              // Nowy element wskazuje na 'last'
            prev_to_last->next = newNode;      // Poprzednik wskazuje na nowy element
        }
    } else {
        printf("Liczba %d nie wystepuje na liscie.\n", target);
    }

    return head; // Zwracamy g³owê (zmienion¹ lub nie)
}

// ---------------------------------------------------------
// FUNKCJE POMOCNICZE I PRZYPADKI TESTOWE
// ---------------------------------------------------------

struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}

void append(struct node** head_ref, int new_value) {
    struct node* newNode = createNode(new_value);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void printList(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
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
    struct node* list = NULL;

    // Tworzymy listê: 4 -> 1 -> 4 -> 8 -> NULL
    append(&list, 4);
    append(&list, 1);
    append(&list, 4); // To jest ostatnie wyst¹pienie czwórki
    append(&list, 8);

    printf("Lista poczatkowa:\n");
    printList(list);

    // Test 1: Wstawiamy 99 przed ostatnim wyst¹pieniem '4' (gdzieœ w œrodku)
    printf("\nWstawiamy '99' PRZED ostatnim wystapieniem '4':\n");
    list = insertBeforeLastOccurrence(list, 4, 99);
    printList(list);
    // Oczekiwane: 4 -> 1 -> 99 -> 4 -> 8 -> NULL

    // Test 2: Sytuacja brzegowa - wstawiamy przed g³ow¹
    // Szukamy '1', które wystêpuje tylko raz, zaraz za pierwsz¹ '4'
    // W obecnej liœcie (4 -> 1 -> 99 -> 4 -> 8) nie zademonstruje to wstawienia przed g³owê

    // Zróbmy now¹ listê dla testu brzegowego: 7 -> 2 -> 3 -> NULL
    struct node* list2 = NULL;
    append(&list2, 7);
    append(&list2, 2);
    append(&list2, 3);

    printf("\n--- Nowa lista ---\n");
    printList(list2);

    printf("\nWstawiamy '55' PRZED ostatnim wystapieniem '7' (ktore jest glowa):\n");
    list2 = insertBeforeLastOccurrence(list2, 7, 55);
    printList(list2);
    // Oczekiwane: 55 -> 7 -> 2 -> 3 -> NULL

    // Zwalnianie pamiêci
    freeList(list);
    freeList(list2);

    return 0;
}
