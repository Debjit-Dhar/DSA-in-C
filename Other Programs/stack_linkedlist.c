#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct data {
    int n;
};

typedef struct list* listpointer;

struct list {
    struct data dat;
    listpointer link;
};

listpointer init_l() {
    return NULL;
}

int empty_l(listpointer head) {
    return (head == NULL);
}

void delete_l(listpointer head) {
    free(head);
}

void insert_front(listpointer* head, listpointer target) {
    target->link = *head;
    *head = target;
}

void delete_front(listpointer* head) {
    
    listpointer cur = *head;
    *head = (*head)->link;
    free(cur);
}

struct stack {
    int top;
    listpointer head;
};

struct stack s;

void s_create() {
    s.head = init_l();
    s.top = -1;
    
}

int s_empty() {
    if (empty_l(s.head) || s.top == -1)
        return 1;
    return 0;
}

void dispose() {
    while (!s_empty()) {
        delete_front(&s.head);
        s.top--;
    }
}

int s_full() {
    return (s.top == MAX - 1);
}

void push(struct data d) {
    if (!s_full()) {
        listpointer target = (listpointer)malloc(sizeof(*target));
        if (!target) {
            perror("Malloc Error.\n");
            return;
        }
        target->dat = d;
        insert_front(&s.head, target);
        s.top++;
    } else {
        printf("Stack Overflow.\n");
    }
}

void pop() {
    if (!s_empty()) {
        printf("%d\n", ((s.head)->dat).n);
        delete_front(&s.head);
        s.top--;
    } else {
        printf("Stack Underflow.\n");
    }
}

int main() {
    struct data d1, d2, d3; // Sample data elements
    d1.n = 10;
    d2.n = 20;
    d3.n = 30;

    s_create(); // Initializing the stack

    printf("Is stack empty? %d\n", s_empty()); // Check if stack is empty

    // Pushing elements onto the stack
    push(d1);
    push(d2);
    push(d3);

    printf("Is stack full? %d\n", s_full()); // Check if stack is full

    // Popping elements from the stack
    printf("Popping elements from the stack:\n");
    pop();
    pop();
    pop();
    pop();

    printf("Is stack empty? %d\n", s_empty()); // Check if stack is empty

    dispose(); // Freeing memory

    return 0;
}
