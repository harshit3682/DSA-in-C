#include <stdio.h>
#include <stdlib.h>
struct node
{
    float coeff;
    int expo;
    struct node *next;
};

struct node *insert(struct node *head, float coff, int exo)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->coeff = coff;
    new->expo = exo;
    new->next = NULL;

    if (head == NULL || exo > head->expo)
    {
        new->next = head;
        head = new;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL && temp->expo > new->expo)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
    return head;
}
struct node *create(struct node *head)
{
    int n, c, e;
    printf("Enter the number of terms in expression: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficient: ");
        scanf("%f", &c);
        printf("Enter the exponential power: ");
        scanf("%d", &e);

        head = insert(head, c, e);
    }
    return head;
}
struct node *print(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%fx^%d", temp->coeff, temp->expo);
        if (temp->next != NULL)
        {
            printf("+");
        }
        temp = temp->next;
    }
}
struct node *polyadd(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo == ptr2->expo)
        {
            insert(head3, ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            insert(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->next;
        }
        else if (ptr2->expo > ptr1->expo)
        {
            insert(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL)
    {
        insert(head3, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        insert(head3, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->next;
    }

    // print(head3);
    return head3;
}

void main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *ptr1 = NULL;
    struct node *ptr2 = NULL;

    printf("Enter the first polynomial:\n");
    ptr1 = create(head1);

    printf("\nEnter the second polynomial:\n ");
    ptr2 = create(head2);

    struct node *head3 = polyadd(ptr1, ptr2);
    printf("\nAdded polynomial is: ");
    print(head3);
}