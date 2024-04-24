#include <stdio.h>
#include <stdlib.h>
struct data
{
    int n;
};
typedef struct list_type* listpointer;
struct list_type
{
    struct data dat;
    listpointer link;
};
listpointer init_l()
{
    return NULL;
}
int empty_l(listpointer head)
{
    return (head==NULL);
}
int atend_l(listpointer cur)
{
    if(cur==NULL)
        return 0;
    return (cur->link==NULL);
}
void insert_front(listpointer *head,listpointer target)
{
    target->link=*head;
    *head=target;
}
void delete_front(listpointer* head)
{
    listpointer cur=*head;
    *head=cur->link;
    free(cur);
}
void insert_after(listpointer prev,listpointer target)
{
    target->link=prev->link;
    prev->link=target;
}
void delete_after(listpointer prev)
{
    listpointer cur=prev->link;
    prev->link=cur->link;
    free(cur);
}

int main() {
    listpointer head = init_l(); // Initialize an empty linked list

    // Creating nodes for the linked list
    listpointer node1 = (listpointer)malloc(sizeof(struct list_type));
    node1->dat.n = 10;
    node1->link = NULL;

    listpointer node2 = (listpointer)malloc(sizeof(struct list_type));
    node2->dat.n = 20;
    node2->link = NULL;

    listpointer node3 = (listpointer)malloc(sizeof(struct list_type));
    node3->dat.n = 30;
    node3->link = NULL;

    // Insert nodes into the linked list
    insert_front(&head, node3); // Insert node3 at the front
    insert_front(&head, node2); // Insert node2 at the front
    insert_front(&head, node1); // Insert node1 at the front

    // Display the linked list
    printf("Linked List elements: ");
    listpointer current = head;
    while (current != NULL) {
        printf("%d ", current->dat.n);
        current = current->link;
    }
    printf("\n");

    // Deleting a node from the front of the linked list
    delete_front(&head);

    // Display the updated linked list
    printf("Linked List after deletion from front: ");
    current = head;
    while (current != NULL) {
        printf("%d ", current->dat.n);
        current = current->link;
    }
    printf("\n");

    // Free allocated memory for the remaining nodes
    while (head != NULL) {
        delete_front(&head);
    }

    return 0;
}
