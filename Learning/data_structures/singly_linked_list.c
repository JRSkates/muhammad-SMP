#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtTail(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteNode(struct Node **head, int data)
{
    if (*head == NULL)
        return;

    struct Node *temp = *head;
    struct Node *prev = NULL;

    while (temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    temp = NULL;
}

void displayList(struct Node **head)
{
    struct Node *temp = *head;
    int i = 0;
    while (temp != NULL)
    {
        printf("Node %d: Head: %d\n", i, temp->data);
        temp = temp->next;
        i++;
    }
}

int main(void)
{
    struct Node *head = NULL;

    insertAtTail(&head, 15);
    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtHead(&head, 30);
    insertAtHead(&head, 40);
    insertAtHead(&head, 50);

    displayList(&head);

    puts("After Delete:");

    deleteNode(&head, 30);

    displayList(&head);

    return 0;
}