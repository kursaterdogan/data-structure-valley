#include <stdio.h>
#include <stdlib.h>

struct student
{
    int no;
    struct student *next;
};

typedef struct student bilge;
bilge *head, *newNode;

void createNodes()
{
    int n, k;
    printf("How many student would you like to add?");
    scanf("%d", &n);
    for (k = 0; k < n; k++)
    {
        if (k == 0)
        {
            newNode = (bilge *)malloc(sizeof(bilge));
            head = newNode;
        }
        else
        {
            newNode->next = (bilge *)malloc(sizeof(bilge));
            newNode = newNode->next;
        }
        printf("No:");
        scanf("%d", &newNode->no);
    }
    newNode->next = NULL;
}

void getStudents()
{
    bilge *p;
    p = head;
    while (p != NULL)
    {
        printf("\n^^^^^^^^^^^^\n");
        printf("StudentNumber:%d\n", p->no);
        printf("\n^^^^^^^^^^^^\n");
        p = p->next;
    }
}

void *addFront(int key)
{
    bilge *temp = (bilge *)malloc(sizeof(bilge));
    temp->no = key;
    temp->next = head;
    head = temp;
}

void *addLast(int key)
{
    bilge *temp = (bilge *)malloc(sizeof(bilge));
    temp->no = key;
    temp->next = NULL;

    bilge *last = (bilge *)malloc(sizeof(bilge));

    if (head == NULL)
        head = temp;
    else
    {
        last = head;

        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = temp;
    }
}

void printReverse(bilge *hat)
{
    if (hat == NULL)
        return;
    else
        printReverse(hat->next);
    printf("Reversed %d\n", hat->no);
}

int countNodes(bilge *hat)
{
    if (hat == NULL)
        return 0;
    return countNodes(hat->next) + 1;
}

void destroy(bilge *hat)
{
    bilge *deleted = (bilge *)malloc(sizeof(bilge));
    deleted = hat;

    while (hat != NULL)
    {
        hat = hat->next;
        free(deleted);
        deleted = hat;
    }
}

void destroyRec(bilge *hat)
{
    if (hat == NULL)
        return;
    destroyRec(hat->next);
    free(hat);
}


void deleteStudent(int studentNo)
{
    bilge *p,*q;
    p=head;
    if(p->no==studentNo)
    {
        head = p->next;
        free(p);
    }
    else
    {
        while (p->next!=NULL)
        {
            q=p;
            p=p->next;
            if(p->no==studentNo) break;
        }
        if (p->no==studentNo)
        {
            q->next = p->next;
            free(p);
        }
        else if (p->next==NULL)
        {
            printf("There is no student with number %d\n",studentNo);
        }
    }
}

void firstEndSwap(bilge *hat) 
{
    bilge *p = hat;
    bilge *q = hat;
    int a = q->no;

    while(p->next!=NULL)
        p = p->next;

    q->no = p->no;
    p->no = a;    
        
}

int main()
{
    createNodes();
    firstEndSwap(head);
    addFront(25);
    addLast(18);
    printReverse(head);
    printf("Your grace %d\n",countNodes(head));
    // destroy(head);
    // destroyRec(head);
    // deleteStudent(1);
    getStudents();
    return 0;
}