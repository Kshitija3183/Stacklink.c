#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};

struct Node* top = NULL;
void push() 
{
    int element;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) 
{
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter the element to push: ");
    scanf("%d", &element);
    
    newNode->data = element;
    newNode->next = top;
    top = newNode;
    
    printf("Element %d pushed into stack\n", element);
}
void pop()
 {
    if (top == NULL)
 {
        printf("Stack Underflow\n");
        return;
    }

    struct Node* temp = top;
    printf("Element %d popped from stack\n", top->data);
    top = top->next;
    
    free(temp);
}
void display()
 {
    if (top == NULL)
 {
        printf("Stack is empty\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack elements are: ");
    while (temp != NULL)
 {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
 {
    int choice;

    while (1)
 {
        printf("\n** Stack Menu **\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
 {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}      
