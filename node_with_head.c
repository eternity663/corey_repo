#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define end -1

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *initlist()
{
    NODE *head;
    head = (NODE*) malloc(sizeof(NODE));
    head->next = NULL;
    return (head);
}

NODE *create()
{
    NODE *p1, *p2, *head;
    int a, end_of_list=end;
    printf("Creating a list...\n");
    p2 = head = initlist();
    printf("Input a number... if %d stop:", end_of_list);
    scanf("%d", &a);
    while (a != end)
    {
        p1 = (NODE *) malloc(sizeof(NODE));
        p1->data = a;
        p2->next = p1;
        p2 = p1;
        printf("Input a number... if %d stop:", end_of_list);
        scanf("%d", &a);
    }
    p2->next = NULL;
    return (head);
}

void print(NODE *head)
{
    NODE *p;
    p = head->next;
    if (p!=NULL)
    {
        printf("Output list:");
        while (p!=NULL)
        {
            printf("%d\t", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

NODE *search(NODE *head, int x)
{
    NODE *p;
    p = head->next;
    while (p!=NULL)
    {
        if (p->data == x) return p;
        p = p->next;
    }
    return NULL;
}

NODE *delete_one_node(NODE *head, int num) //delete one node (without considering repeated data for simplification)
{
    NODE *p, *temp;
    p = head;
    while (p->next->data != num && p->next != NULL) {p = p->next;}
    temp = p->next;
    if (p->next != NULL)
    {
        p->next = temp->next;
        free(temp);
        printf("Delete successfully!\n");
    }
    else printf("Node is not found.\n");
    return (head);
}

void free_list(NODE *head)
{
    NODE *p;
    while (head)
    {
        p = head;
        head = head->next;
        free (p);
    }
}

NODE *insert(NODE *head, NODE *s)
{
    NODE *p;
    p = head;
    while ((p->next->data) < (p->next->data) && p->next != NULL)
    {
        p = p->next;
    }
    s->next = p->next;
    p->next = s;
    return (head);
}

NODE *create_sort()
{
    NODE *p, *head=NULL;
    int a, end_of_list = end;
    printf("Creating an increasing list...\n");
    head = initlist();
    printf("Input a number... if %d stop:", end_of_list);
    scanf("%d", &a);
    while (a != end)
    {
        p = (NODE *) malloc(sizeof(NODE));
        p->data = a;
        head = insert(head, p);
        printf("Input a number... if %d stop:", end_of_list);
        scanf("%d", &a);
    }
    return (head);
}

int main()
{
    return 0;
}