#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;//düğümde tutulacak veri
    struct Node* next;//bir sonraki düğümün bellek adresini tutar
} Node;
//yeni bir düğüm oluşturmak için fonksiyon
Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("hatta:bellek ayarlanamadı!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;//ilk oluşturulduğunda bir sonraki düğümğ göstermez

    return newNode;
}
void insertAtEnd(Node** headRef, int value) {
    Node* newNode = createNode(value);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void deleteNode(Node** headRef, int key) {
    Node* temp = *headRef;
    Node* prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("-> %d Listede bulunamadı!\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("-> %d Listeden silindi!\n", key);
}
void printList(Node* head) {
    Node* temp = head;
    printf("Liste: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(Node** headRef) {
    Node* current = *headRef;
    Node* nextNode;
    
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *headRef = NULL;
    printf("tüm bellek temizlendi.\n");
}
int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printList(head);

    deleteNode(&head, 20);
    printList(head);

    deleteNode(&head, 40); // Listede olmayan bir düğümü silmeye çalışıyoruz

    freeList(&head);
    return 0;
}
