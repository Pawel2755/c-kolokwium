#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

// Funkcja do zaimplementowania
void removeCycle(struct Node *head) {
    // 1. Krok pierwszy: U¿yj algorytmu Floyda, aby wykryæ, czy cykl w ogóle istnieje.
    // 2. Krok drugi: Jeœli cykl istnieje, znajdŸ jego pocz¹tek (zgodnie ze screenem).
    // 3. Krok trzeci: ZnajdŸ wêze³, który zamyka cykl i ustaw jego 'next' na NULL.

    // Twoja implementacja tutaj...

    struct Node* slow = head;
    struct Node* fast = head;
    bool isCycle = false;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            isCycle=true;
            break;
        }
    }

    slow=head;
    if(slow==fast){
        while(fast->next!=slow){
            fast=fast->next;
        }
        fast->next = NULL;
    }
    else{
        while(slow->next!= fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL;
    }


}

// --- Funkcje pomocnicze ---

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Funkcja bezpiecznie wypisuj¹ca listê (zabezpieczenie na max 20 elementów w razie b³êdu)
void printListSafe(struct Node *head) {
    struct Node *temp = head;
    int count = 0;
    while (temp != NULL && count < 20) {
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    }
    if (count == 20) {
        printf("[BLAD: Lista nadal zapetlona lub za dluga!]\n");
    } else {
        printf("NULL\n");
    }
}

int main() {
    // Tworzenie listy: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    struct Node* node6 = createNode(6);
    head->next->next->next->next->next = node6;

    // Tworzenie cyklu: wêze³ 6 wskazuje z powrotem na wêze³ 3
    node6->next = head->next->next;

    printf("Proba wypisania listy przed usunieciem cyklu:\n");
    printListSafe(head); // Powinno wypisaæ 20 elementów i wyrzuciæ b³¹d zapêtlenia

    // Wywo³anie Twojej funkcji
    removeCycle(head);

    printf("\nProba wypisania listy po usunieciu cyklu:\n");
    printListSafe(head); // Powinno wypisaæ: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL

    // Zwalnianie pamiêci (teraz jest bezpieczne, bo nie ma cyklu)
    struct Node* current = head;
    struct Node* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    return 0;
}
