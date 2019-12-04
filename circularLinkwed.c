#include <stdio.h>
#include <stdlib.h>

// ---->
// \   |
// <---|

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node bilge;

bilge *addFront(bilge *head, int key)
{
    bilge *temp = (bilge *)malloc(sizeof(bilge));
    temp->data = key;
    if (head == NULL)
    {
        temp->next = temp;
        head = temp;
    }
    else
    {
        temp->next = head;
        bilge *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = temp;
        head = temp;
    }
    return head;
}

bilge *addLast(bilge *head, int key)
{
    bilge *temp = (bilge *)malloc(sizeof(bilge));
    temp->data = key;
    if (head == NULL)
    {
        temp->next = temp;
        head = temp;
    }
    else
    {
        temp->next = head;
        bilge *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = temp;
        // head = temp;
    }
    return head;
}
