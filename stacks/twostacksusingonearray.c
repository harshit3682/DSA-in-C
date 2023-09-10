#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct stack
{
    int size;
    int capacity;
    int *arr;
    int top1;
    int top2;
};
void initialize(struct stack *s1, int cap)
{
    s1->capacity = cap;
    s1->top1 = -1;
    s1->top2 = cap;
    s1->size = 0;
    s1->arr = (int *)malloc(cap * sizeof(int));
}

void push1(struct stack *s1, int val)
{
    if ((s1->top2 - s1->top1) > 1)
    {
        s1->top1++;
        s1->arr[s1->top1] = val;
        s1->size++;
        printf("The element %d is inserted into the stack.", val);
    }
    else
    {
        printf("stack overflow");
        return;
    }
}
void push2(struct stack *s1, int val)
{
    if ((s1->top2 - s1->top1) > 1)
    {
        s1->top2--;
        s1->arr[s1->top2] = val;
        s1->size++;
        printf("The element %d is inserted into the stack.", val);
    }
    else
    {
        printf("stack overflow");
        return;
    }
}
int pop1(struct stack *s1)
{
    int x = s1->arr[s1->top1];
    s1->top1--;
    s1->size--;
    return x;
}
int pop2(struct stack *s1)
{
    int x = s1->arr[s1->top2];
    s1->top2++;
    s1->size--;
    return x;
}
void display(struct stack *s1, int cap)
{
    for (int i = 0; i < cap; i++)
    {
        printf("%d ", s1->arr[i]);
    }
}
void main()
{ // jab ptr lenge struct stack ka tab memory allocate karni padegi
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    int cap, ch, n, val;
    printf("Enter the capacity: ");
    scanf("%d", &cap);
    initialize(ptr, cap);
    do
    {
        printf("\n\nStack Operations:\n 1. Push1\n 2. Push2\n 3. Pop1\n 4. Pop2\n 5. Display\n 6. Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {

        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &n);
            push1(ptr, n);
            break;

        case 2:
            printf("Enter the element to insert: ");
            scanf("%d", &n);
            push2(ptr, n);
            break;

        case 3:
            val = pop1(ptr);
            printf("\nThe popped out element is %d", val);
            break;

        case 4:
            val = pop2(ptr);
            printf("\nThe popped out element is %d", val);
            break;

        case 5:
            display(ptr, cap);
            break;

        case 6:
            printf("\nExitting..");
            exit(0);

        default:
            printf("  Plz enter a valid choice ");
        }
    } while (ch != 6);
    getch();
}
