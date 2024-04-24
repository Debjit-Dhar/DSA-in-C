#include <stdio.h>
#include <stdlib.h>
struct data
{
    int n;
};
typedef struct clist* clistpointer;
struct clist
{
    struct data dat;
    clistpointer link;
};
clistpointer init_l()
{
    return NULL;
}
int empty_l(clistpointer head)
{
    return head==NULL;
}
int atend_l(clistpointer cur,clistpointer head)
{
    if(cur==NULL)
        return 0;
    else
        return(cur->link==head);
}
void insert_front(clistpointer *head,clistpointer target,clistpointer last)
{
    target->link=*head;
    *head=target;
    last->link=*head;
}
void delete_front(clistpointer *head,clistpointer last)
{
    clistpointer temp=*head;
    *head=(*head)->link;
    free(temp);
    last->link=*head;
}
void insert_after(clistpointer prev,clistpointer target)
{
    target->link=prev->link;
    prev->link=target;
}
void delete_after(clistpointer prev)
{
    clistpointer temp=prev->link;
    prev->link=temp->link;
    free(temp);
}
void print_l(clistpointer cur,clistpointer head)
{
    do
    {
        printf("%d->",cur->dat.n);
        cur=cur->link;
    }while(cur!=head);
    printf("\n");
}

int main() {
    clistpointer head = init_l();
    clistpointer last = NULL; // Pointer to keep track of the last node

    // Insert nodes at the front of the circular linked list
    for (int i = 1; i <= 5; ++i) {
        clistpointer newNode = (clistpointer)malloc(sizeof(struct clist));
        newNode->dat.n = i;

        if (head == NULL) {
            head = newNode;
            last = newNode;
            newNode->link = head; // Circular reference
        } else {
            insert_front(&head, newNode, last);
        }
    }

    // Display the circular linked list
    printf("Circular Linked List: ");
    print_l(head, head);

    // Delete a node from the front of the circular linked list
    delete_front(&head, last);

    // Display the updated circular linked list
    printf("Updated Circular Linked List after deletion: ");
    print_l(head, head);

    // Insert a new node after a specific node
    clistpointer current = head;
    int position = 2; // Insert after the 2nd node
    for (int i = 1; i < position; ++i) {
        current = current->link;
    }

    clistpointer newNode = (clistpointer)malloc(sizeof(struct clist));
    newNode->dat.n = 10; // Data for the new node
    insert_after(current, newNode);

    // Display the updated circular linked list
    printf("Updated Circular Linked List after insertion: ");
    print_l(head, head);

     return 0;
}