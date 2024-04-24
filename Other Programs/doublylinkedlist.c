#include <stdio.h>
#include <stdlib.h>
typedef struct list* listpointer;
struct list
{
    int data;
    listpointer linkprev;
    listpointer linknext;
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
    else
        return ((cur->linknext)==NULL);
}
void insert_front(listpointer *head,listpointer target)
{
    if(*head==NULL)
        *head=target;
    else
    {
        target->linkprev=init_l();
        target->linknext=*head;
        (*head)->linkprev=target;
        *head=target;
    }
}
void insert_after(listpointer prev,listpointer target)
{
    target->linkprev=prev;
    target->linknext=prev->linknext;
    prev->linknext=target;
}
void delete_front(listpointer*head)
{
    listpointer temp=*head;
    *head=temp->linknext;
    temp->linkprev=NULL;
    free(temp);
}
void delete_after(listpointer prev)
{
    listpointer temp=prev->linknext;
    prev->linknext=temp->linknext;
    if(!atend_l(temp))
        (temp->linknext)->linkprev=prev;
    
    free(temp);
}
void print_l(listpointer head)
{
    listpointer cur=head;
    while(cur!=NULL)
    {
        printf("%d->",(cur->data));
        cur=cur->linknext;
    }
    printf("\n");
    cur = head;
    while (cur->linknext != NULL) {
    cur = cur->linknext;
    }

    printf("Backward Doubly Linked List: ");
    while (cur != NULL) 
    {
        printf("%d->", cur->data);
        cur = cur->linkprev;
    }
    printf("\n");
    printf("\n");
}

int main() {
    listpointer head = init_l();
    int data;
    int choice;
    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at the front\n");
        printf("2. Insert after a node\n");
        printf("3. Delete at the front\n");
        printf("4. Delete after a node\n");
        printf("5. Print the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert at the front
                printf("Enter data to insert: ");
                scanf("%d", &data);
                listpointer new_node = (listpointer)malloc(sizeof(struct list));
                new_node->data = data;
                new_node->linkprev = NULL;
                new_node->linknext = NULL;
                insert_front(&head, new_node);
                printf("Node inserted at the front.\n");
                break;

            case 2:
                // Insert after a node
                {
                    int after_data;
                    printf("Enter data of the node after which to insert: ");
                    scanf("%d", &after_data);

                    listpointer cur = head;
                    while (cur != NULL && cur->data != after_data)
                        cur = cur->linknext;

                    if (cur == NULL)
                        printf("Node with given data not found.\n");
                    else {
                        int data;
                        printf("Enter data to insert: ");
                        scanf("%d", &data);
                        listpointer new_node = (listpointer)malloc(sizeof(struct list));
                        new_node->data = data;
                        new_node->linkprev = NULL;
                        new_node->linknext = NULL;

                        insert_after(cur, new_node);
                        printf("Node inserted after a node.\n");
                    }
                    break;
                }

            case 3:
                // Delete at the front
                delete_front(&head);
                printf("Node deleted from the front.\n");
                break;

            case 4:
                // Delete after a node
                {
                    int after_data;
                    printf("Enter data of the node after which to delete: ");
                    scanf("%d", &after_data);

                    listpointer cur = head;
                    while (cur != NULL && cur->data != after_data)
                        cur = cur->linknext;

                    if (cur == NULL)
                        printf("Node with given data not found or cannot delete after the last node.\n");
                    else
                        delete_after(cur);

                    printf("Node deleted after a node.\n");
                    break;
                }

            case 5:
                // Print the list
                printf("Doubly Linked List: ");
                print_l(head);
                printf("\n");
                break;

            case 6:
                // Free allocated memory before exiting
                while (head != NULL) {
                    listpointer temp = head;
                    head = head->linknext;
                    free(temp);
                }
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
