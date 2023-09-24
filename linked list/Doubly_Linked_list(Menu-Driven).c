#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
};
int insert_before_value(struct node **head, struct node **tail, int value)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("memory not allocated");
        return 0;
    }
    int data;
    printf("Enter the value to be inserted: ");
    scanf("%d", &data);
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;

    struct node *temp = *head;

    while ((temp->data != value) && (temp != NULL))
    {
        temp = temp->next;
    }
    ptr->next = temp;
    ptr->prev = temp->prev;
    if (temp->prev != NULL)
    {
        temp->prev->next = ptr;
    }

    else
    {
        *head = ptr;
        printf("\nValue inserted");
        return 0;
    }
    temp->prev = ptr->next;
    printf("\nValue inserted");
}
int insert_after_value(struct node **head, struct node **tail, int value)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("memory not allocated");
        return 0;
    }
    int data;
    printf("Enter the value to be inserted: ");
    scanf("%d", &data);
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;

    struct node *temp = *head;
    struct node *temp1 = NULL;
    while ((temp->data != value) && (temp != NULL))
    {
        temp = temp->next;
    }
    temp1 = temp->next;
    if (temp1 != NULL)
    {
        ptr->prev = temp;
        ptr->next = temp1;
        temp->next = ptr;
        temp1->prev = ptr;
        return 1;
    }
    else
    {
        (*tail)->next = ptr;
        ptr->prev = *tail;
        *tail = (*tail)->next;
        return 0;
    }
}

int insert_last(struct node **head, struct node **tail, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (ptr == NULL)
    {
        printf("memory not allocated");
        return 0;
    }
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    if ((*head != NULL) && (*tail != NULL))
    {
        temp->next = ptr;
        ptr->prev = temp;
        *tail = (*tail)->next;
        printf("\nValue inserted");
        return 1;
    }
    else
    {
        *head = ptr;
        *tail = ptr;
        printf("\nValue inserted");
        return 0;
    }
}

int insert_first(struct node **head, struct node **tail, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("memory not allocated");
        return 0;
    }
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    if (!(*head))
    {
        *head = ptr;
        *tail = ptr;
        printf("\nValue inserted");
        return 0;
    }
    ptr->next = *head;
    (*head)->prev = ptr;
    *head = ptr;
    printf("\nValue inserted");
}

void print(struct node **head)
{
    struct node *temp = *head;
    printf("Elements are as: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void main()
{
    struct node *head = NULL;
    struct node *tail = NULL;
    int ch, n1, n2, k;
    do
    {
        printf("\n\n1.Insert at front.\n2.Insert at end");
        printf("\n3.Insertion before value k\n4.Insertion after value K\n5.Display\n6.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &n1);
            insert_first(&head, &tail, n1);
            break;
        case 2:
            printf("Enter the element: ");
            scanf("%d", &n2);
            insert_last(&head, &tail, n2);
            break;

        case 3:
            printf("Enter value before which new node to be inserted: ");
            scanf("%d", &k);
            insert_before_value(&head, &tail, k);
            break;
        case 4:
            printf("Enter value after which new node to be inserted: ");
            scanf("%d", &k);
            insert_after_value(&head, &tail, k);
            break;

        case 5:
            print(&head);
            break;
        case 6:
            printf("Exitting...");
            free(head);
        }
    } while (ch != 6);
}