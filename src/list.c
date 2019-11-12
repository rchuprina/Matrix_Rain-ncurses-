#include "header.h"

list *create_node(int y)
{
    list *node = (list *)malloc(sizeof(list));
    int *arr = (int *)malloc(6 * sizeof(int));

    arr[0] = y;
    arr[1] = arr[0] - 1;
    arr[2] = arr[1] - 1;
    arr[3] = arr[2] - 2;
    arr[5] = arr[3] - rand() % 20;
    arr[4] = (arr[5] + arr[3]) / 2;
    node->arr = arr;
    node->next = NULL;
    return node;
}

void add_back(list **head)
{
    int ay = (rand() % 40 + 4) * -1;

    if (*head)
    {
        list *p = *head;

        while (p->next)
            p = p->next;
        if (p->arr[5] > 0)
            p->next = create_node(ay);
        else
            p->next = create_node(p->arr[5] + ay);
    }
    else
        *head = create_node(ay);
}

void pop_front(list **head)
{
    if (*head)
    {
        list *p = (*head)->next;

        free((*head)->arr);
        free(*head);
        *head = p;
    }
}

int size_list(list *head)
{
    int i = 0;

    while (head)
    {
        head = head->next;
        i++;
    }
    return i;
}
