#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *temp;

void insertion() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void deletion() {
    struct node *prev;

    if (head == NULL) {
        printf("The list is empty\n");
    }
    else if (head->next == NULL) {   // single node case
        free(head);
        head = NULL;
        printf("Node deleted\n");
    }
    else {
        temp = head;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
        printf("Node deleted\n");
    }
}

void traversal() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Insertion\n2. Deletion\n3. Traversal\n4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertion(); break;
            case 2: deletion(); break;
            case 3: traversal(); break;
            case 4: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
}
//the end of the code
