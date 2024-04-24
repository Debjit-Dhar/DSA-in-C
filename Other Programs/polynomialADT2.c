#include <stdio.h>
#include <stdlib.h>

struct polynomial
{
    float coeff;
    int exp;
};

typedef struct list *listPointer;

struct list
{
    struct polynomial poly;
    listPointer link;
};

listPointer head, cur;

int empty_l(listPointer head)
{
    return (head == NULL); // Return 1 if head=NULL else return 0
}

void init_l()
{
    head = (listPointer)malloc(sizeof(struct list));
    head->link = NULL;
    cur = head;
}

int atend_l(listPointer cur)
{
    if (cur == NULL)
        return 0;
    else
        return ((cur->link) == NULL);
}

void insert_front(listPointer target, listPointer *head)
{
    target->link = *head;
    *head = target;
}

listPointer insert_after(listPointer target, listPointer prev)
{
    target->link = prev->link;
    prev->link = target;
    return target;
}

void print_pattern(float c, int e)
{
    if (c < 0)
    {
        if (e == 1)
            c != -1 ? printf("%.2fx", c) : printf("-x");
        else if (e == 0)
            c != -1 ? printf("%.2f", c) : printf("-1");
        else
            c != -1 ? printf("%.2fx^%d", c, e) : printf("-x^%d", e);
    }
    else
    {
        if (e == 1)
            c != 1 ? printf("+%.2fx", c) : printf("+x");
        else if (e == 0)
            c != 1 ? printf("+%.2f", c) : printf("+1");
        else
            c != 1 ? printf("+%.2fx^%d", c, e) : printf("+x^%d", e);
    }
}

void print_l(listPointer head)
{
    head = head->link;
    if (!empty_l(head))
    {
        while (!atend_l(head))
        {
            print_pattern((head->poly).coeff, (head->poly).exp);
            head = head->link;
        }
        print_pattern((head->poly).coeff, (head->poly).exp);
        printf("\n");
    }
    else
        printf("Empty List.\n");
}

listPointer attach(float c, int e)
{
    listPointer target = (listPointer)malloc(sizeof(struct list));
    (target->poly).coeff = c;
    (target->poly).exp = e;
    cur = insert_after(target, cur);

    return cur;  // Return the newly created node
}

void add(int startA, int finishA, int startB, int finishB)
{
    listPointer startlA = head;
    listPointer startlB = head;
    int c = 0, co = 0;

    while (!atend_l(startlA) || !atend_l(startlB))
    {
        if (co == 2)
            break;

        if (c == startA)
        {
            startlA = startlA->link;
            co++;
        }
        if (c == startB)
        {
            startlB = startlB->link;
            co++;
        }
        c++;
    }
    while (startA <= finishA && startB <= finishB)
    {
        if ((startlA->poly).exp < (startlB->poly).exp)
        {
            attach((startlB->poly).coeff, (startlB->poly).exp);
            startlB = startlB->link;
            startB++;
        }
        else if ((startlA->poly).exp > (startlB->poly).exp)
        {
            attach((startlA->poly).coeff, (startlA->poly).exp);
            startlA = startlA->link;
            startA++;
        }
        else
        {
            attach((startlA->poly).coeff + (startlB->poly).coeff, (startlA->poly).exp);
            startlA = startlA->link;
            startlB = startlB->link;
            startA++;
            startB++;
        }
    }
    for (; startA <= finishA; startA++)
    {
        attach((startlA->poly).coeff, (startlA->poly).exp);
        startlA = startlA->link;
    }
    for (; startB <= finishB; startB++)
    {
        attach((startlB->poly).coeff, (startlB->poly).exp);
        startlB = startlB->link;
    }
    return ;
}

int main()
{
    listPointer target = (listPointer)malloc(sizeof(struct list));
    (target->poly).coeff = 0;
    (target->poly).exp = 0;
    insert_front(target, &head);
    cur = head;
    attach(1, 2);
    attach(1,1);
    attach(1, 0);
    attach(1, 1);
    attach(1, 0);
    print_l(head);
    add(1, 3, 4, 5);
    print_l(head);
    return 0;
}
