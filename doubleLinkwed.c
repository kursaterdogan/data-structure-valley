#include <stdio.h>
#include <stdlib.h>

//        head=100               2.200
//  prev | data | next    prev | data | next

// DLLs compared to SLLs

// Advantages
// -can be traversed in either
// -direction(may be essential for some programs)
// -some operations such as deletions and inserting inserting before a node become easier

// Disadvantages
// -requires more spaces
// -list manipulations are slower('cause more links must be changed)
// -grater chance of having bugs('cause more links must be manipulated)

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
    temp->prev = NULL;
    temp->next = head;
    if (head == NULL)
        head->prev = temp;
    head = temp;
    return head;
}

bilge *addLast(bilge *head, int key)
{
    bilge *temp = (bilge *)malloc(sizeof(bilge));
    bilge *last = head;
    temp->data = key;
    temp->next = NULL;
    if (head == NULL)
    {
        temp->prev = NULL;
        head = temp;
    }
    else
    {
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = temp;
        temp->prev = last;
    }
    return head;
}

// if we use like that &*head will be change

void *printRev(bilge *head)
{
    if (head == NULL)
        printf("List is empty");
    else
    {

        while (head->next != NULL)
        {
            head = head->next;
        }
        // head = head->prev;
        // ======
        // head->prev not printing last previous one

        while (head != NULL)
        {
            printf("%d\n", head->data);
            head = head->prev;
        }
    }
}
// void *printRevRec(bilge *head)

bilge *singleToDeleteNode(bilge *head, int key)
{
    if (head == NULL)
        return NULL;
    bilge *temp = head;
    if (head->data == key)
    {
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
    else
    {
        while (temp->next != NULL && temp->next->data != key)
        {
            temp = temp->next;
            if (temp->next == NULL)
                return head;
            bilge *deletedNode = temp->next;
            if (deletedNode->next != NULL)
                temp->next = deletedNode->next;
            deletedNode->next->prev = temp;
            free(deletedNode);
        }
    }
    return head;
}

bilge *deleteNode(bilge *head, int key)
{
    if (head == NULL)
        return NULL;
    bilge *temp = head;
    if (head->data == key)
    {
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
    else
    {
        while (temp != NULL && temp->data != key)
        {
            temp = temp->next;
            if (temp == NULL)
                return head;
            temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            free(temp);
        }
    }
    return head;
}
