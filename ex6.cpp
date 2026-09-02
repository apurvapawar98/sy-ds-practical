#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char destination[50];
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;


/* Add destination to queue */
void enqueue()
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("\nMemory allocation failed!\n");
        return;
    }

    printf("\nEnter Destination: ");
    scanf("%s", newNode->destination);

    newNode->next = NULL;

    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("\nReservation request added successfully!\n");
}


/* Remove destination from queue */
void dequeue()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("\nQueue is Empty!\n");
        return;
    }

    temp = front;

    printf("\nProcessing Reservation...\n");
    printf("Destination: %s\n", temp->destination);

    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    free(temp);

    printf("Reservation processed successfully!\n");
}


/* Display all destinations */
void display()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("\nQueue is Empty!\n");
        return;
    }

    temp = front;

    printf("\n----- Waiting Reservations -----\n");

    while (temp != NULL)
    {
        printf("Destination: %s\n", temp->destination);
        temp = temp->next;
    }
}


/* View first destination */
void peek()
{
    if (front == NULL)
    {
        printf("\nQueue is Empty!\n");
        return;
    }

    printf("\n----- First Reservation -----\n");
    printf("Destination: %s\n", front->destination);
}


/* Count waiting reservations */
void count()
{
    struct Node *temp;
    int total = 0;

    temp = front;

    while (temp != NULL)
    {
        total++;
        temp = temp->next;
    }

    printf("\nNumber of waiting reservations = %d\n", total);
}


/* Main function */
int main()
{
    int choice;

    while (1)
    {
        printf("\n\n=================================");
        printf("\n     TICKET RESERVATION SYSTEM");
        printf("\n=================================");

        printf("\n1. Add Destination");
        printf("\n2. Process Reservation");
        printf("\n3. Display Destinations");
        printf("\n4. View First Destination");
        printf("\n5. Count Reservations");
        printf("\n6. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                peek();
                break;

            case 5:
                count();
                break;

            case 6:
                printf("\nProgram terminated.\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
