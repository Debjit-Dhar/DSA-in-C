#include <stdio.h>
#include <stdlib.h> 

typedef struct Node* NodePointer;

typedef struct Node {
    int data;
    NodePointer next;
} Node;

NodePointer createNode(int data) {
    NodePointer newNode = (NodePointer)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int atend_l(NodePointer head, NodePointer cur) {
    return (cur->next == head);
}

void insert_front(NodePointer* head, int data) {
    NodePointer newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        newNode->next = (*head)->next;
        (*head)->next = newNode;
    }
}

void insert_after(NodePointer prev, int data) {
    if (prev == NULL) {
        printf("Previous node is NULL.\n");
        return;
    }

    NodePointer newNode = createNode(data);
    newNode->next = prev->next;
    prev->next = newNode;
}

void delete_after(NodePointer prev) {
    if (prev == NULL || prev->next == NULL) {
        printf("Previous node is NULL or the next node is NULL.\n");
        return;
    }

    NodePointer toDelete = prev->next;
    prev->next = toDelete->next;
    free(toDelete);
}

void delete_front(NodePointer* head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    NodePointer toDelete = (*head)->next;
    (*head)->next = toDelete->next;
    free(toDelete);

    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    }
}

void print_l(NodePointer head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    NodePointer current = head->next;
    printf("List: ");
    //printf("%d->",(head->data));
    do {
        printf("%d->", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    NodePointer head = NULL;

    insert_front(&head, 4);
    insert_after(head, 5);
    insert_after(head->next, 6);

    print_l(head);

    delete_front(&head);
    print_l(head);

    delete_after(head);
    print_l(head);

    return 0;
}