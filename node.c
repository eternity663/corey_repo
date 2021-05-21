#include <stdio.h>
#include <malloc.h>
#include "node_def.h"
#define end -1

/*
typedef struct node
{
    int data;
    struct node *next;
} NODE;
*/

struct node *create() //create a linked list
{
    struct node *p1, *p2, *head;
    int a, end_of_list = end;
    head = NULL;
    printf("Creating a list...\n");
    printf("Input a number... if %d stop:", end_of_list);
    scanf("%d", &a);
    while (a != end)
    {
        p1 = (struct node *) malloc(sizeof(struct node));
        p1->data = a;
        if (head == NULL) {head =p2 =p1;}
        else {
            p2->next = p1;
            p2 = p1;
        }
        printf("Input a number... if %d stop:", end_of_list);
        scanf("%d", &a);
    }
    if (head!=NULL) p2->next = NULL;
    return (head);
}

struct node *search(struct node *head, int x) //search for a node whose data equals to x and simultaneously iterate the list
{
    struct node *p;
    p = head;
    while (p!=NULL)
    {
        if (p->data == x) return p;
        p = p->next;
    }
    return NULL;
}

struct node *delete_one_node(struct node *head, int num) //delete one node (without considering repeated data for simplification)
{
    struct node *p1, *p2;
    if (head == NULL)
    {
        printf("List is null.\n");
        return (NULL);
    }
    p1 = head;
    while (p1->data != num && p1->next != NULL)
    {
        p2 = p1;
        p1 = p1->next;
    }
    if (p1->data == num)
    {
        if (p1==head) head = p1->next;
        else p2->next = p1->next;
        free(p1);
    }
    else printf("Node is not found.\n");
    return (head);
}

struct node *insert(struct node *head, struct node *p)
{
    struct node *p1, *p2;
    if (head == NULL)
    {
        head = p;
        p->next = NULL;
        return (head);
    }
    p2=p1=head;
    while ((p->data) > (p1->data) && p1->next != NULL)
    {
        p2 = p1;
        p1 = p1->next;
    }
    if ((p->data) <= (p1->data))
    {
        p->next = p1;
        if (head == p1) head = p;
        else p2->next = p;
    }
    else
    {
        p1->next = p;
        p->next = NULL;
    }
    return (head);
}

struct node *create_sort()
{
    struct node *p, *head=NULL;
    int a, end_of_list = end;
    printf("Creating an increasing list...\n");
    printf("Input a number... if %d stop:", end_of_list);
    scanf("%d", &a);
    while (a != end)
    {
        p = (struct node *) malloc(sizeof(struct node));
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