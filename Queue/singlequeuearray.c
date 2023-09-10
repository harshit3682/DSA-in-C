#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int capacity;
    int size;
    int *arr;
    int front;
    int rear;
};
void initialize(struct queue *q1, int cap)
{
    q1->capacity = cap;
    q1->size = 0;
    q1->front = q1->rear = -1;
    q1->arr = (int *)malloc(cap * sizeof(int));
}
int isempty(struct queue *q1)
{
    if (q1->front == -1)
    {
        printf("Queue is empty.\n");
        return 1;
    }
    if (q1->front == q1->rear)
    {
        printf("All the elements are dequeued, hence queue is empty. ");
        return 1;
    }
    return 0;
}
int isfull(struct queue *q1)
{

    if (q1->rear == q1->capacity - 1)
    {
        printf("Queue overflow ");
        return 1;
    }

    return 0;
}
void enqueue(struct queue *q1, int val)
{
    if (isfull(q1))
    {
        printf(" Not possible");
        return;
    }
    if (isempty(q1))
    {
        q1->front = 0;
    }

    q1->rear++;
    q1->arr[q1->rear] = val;
    q1->size++;

    printf("The element %d is inserted into queue.", val);
}
int dequeue(struct queue *q1)
{
    if (isempty(q1))
    {
        printf("Stack Underflow\n");
        return 0;
    }
    int val = q1->arr[q1->front];
    q1->front++;
    return val;
}

void front(struct queue *q1)
{
    if (isempty(q1))
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("\nThe front most element is %d at index %d", q1->arr[q1->front], q1->front);
}
void display(struct queue *q1)
{
    printf("\nThe elements are as: ");
    for (int i = q1->front; i <= q1->rear; i++)
    {
        printf("%d ", q1->arr[i]);
    }
}
void deallocate(struct queue *q1)
{
    free(q1->arr);
}
void main()
{
    int cap, n, val, ch;
    struct queue ptr;
    printf("Enter the capacity: ");
    scanf("%d", &cap);
    initialize(&ptr, cap);

    do
    {
        printf("\n\nStack Operations:");
        printf("\n1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n5. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &n);
            enqueue(&ptr, n);
            break;
        case 2:
            val = dequeue(&ptr);
            printf("The popped out element is %d.", val);
            break;
        case 3:
            front(&ptr);
            break;
        case 4:
            display(&ptr);
            break;
        case 5:
            printf("Exiting....");
            deallocate(&ptr);
            exit(0);
        default:
            printf("Plz enter a valid choice..");
        }
    } while (ch != 5);
}