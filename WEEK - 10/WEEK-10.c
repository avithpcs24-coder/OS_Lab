#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int top = -1;  // stack pointer

// Producer function
void produce(int item)
{
    if (top == BUFFER_SIZE - 1)
    {
        printf("Buffer is full!\n");
        return;
    }

    buffer[++top] = item;
    printf("Producer has produced: Item %d\n", item);
}

// Consumer function
void consume()
{
    if (top == -1)
    {
        printf("Buffer is empty!\n");
        return;
    }

    printf("Consumer has consumed: Item %d\n", buffer[top--]);
}

int main()
{
    int choice;
    int item = 1;

    while (1)
    {
        printf("\nEnter 1.Producer 2.Consumer 3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                produce(item++);
                break;

            case 2:
                consume();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}


