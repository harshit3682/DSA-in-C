#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insert_first(struct Node **head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Memory not allocated!");
        return;
    }
    ptr->data = data;
    ptr->next = NULL;
    if (*head == NULL)
    {
        *head = ptr;
    }
    else
    {
        ptr->next = *head;
        *head = ptr;
    }

    printf("Inserted element=%d", ptr->data);
}
void insert_last(struct Node **head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Memory not allocated!");
        return;
    }
    ptr->data = data;
    ptr->next = NULL;
    if (*head == NULL)
    {
        *head = ptr;
    }
    else
    {
        struct Node *p = *head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
    }

    printf("Inserted element=%d", ptr->data);
}
void delete_first(struct Node **head)
{
    if (*head == NULL)
    {
        printf("None elements to delete!");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    printf("Deleted element=%d", temp->data);
    free(temp);
}
void delete_last(struct Node **head)
{
    if (*head == NULL)
    {
        printf("None elements to delete!");
        return;
    }
    struct Node *temp = *head;
    struct Node *prev;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    printf("Deleted element=%d", temp->data);
    free(temp);
}
void traversal(struct Node **head)
{
    if (*head == NULL)
    {
        printf("None elements to display!");
        return;
    }
    struct Node *ptr = *head;
    printf("Elements are as: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct Node *head = NULL;
    int ch, n1, n2;
    do
    {
        printf("\n\n1.Insert at front.\n2.Insert at last\n3.Delete from front\n4.Delete from last\n5.Display\n6.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &n1);
            insert_first(&head, n1);
            break;
        case 2:
            printf("Enter the element: ");
            scanf("%d", &n2);
            insert_last(&head, n2);
            break;
        case 3:
            delete_first(&head);
            break;
        case 4:
            delete_last(&head);
            break;
        case 5:
            traversal(&head);
            break;
        case 6:
            printf("Exitting...");
            exit(0);
        }
    } while (ch != 6);
}