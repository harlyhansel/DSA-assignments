#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 5
#define NAME_LEN 50

char stack[MAX][NAME_LEN];
int top = -1;

int isValidName(char name[]) {
    for (int i = 0; name[i]; i++)
        if (!isalpha(name[i]) && name[i] != ' ') return 0;
    return 1;
}

void push(char name[]) {
    if (top == MAX - 1) {
        printf("Stack is full!");
        return;
    }
    strcpy(stack[++top], name);
    printf("%s added.\n", name);  // New line after name is added
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Friends in stack:\n");
    for (int i = top; i >= 0; i--) {
        printf("%s\n", stack[i]);  // New line after each name
    }
}

int main() {
    int choice;
    char name[NAME_LEN];

    while (1) {
        for (int i = 0; i < MAX; i++) {
            if (top == MAX - 1) {
                printf("Stack is full! You cannot add more friends.\n");
                break;
            }
            printf("Enter name: ");
            fgets(name, NAME_LEN, stdin);
            name[strcspn(name, "\n")] = 0;  // Remove the newline character
            if (isValidName(name)) push(name);
            else printf("Invalid name! Only letters and spaces allowed.\n");
        }

        printf("\n1. Display Friends\n2. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar();  // Consume the extra newline left by scanf

        if (choice == 1) display();
        else if (choice == 2) break;
        else printf("Invalid choice. Try again.\n");
    }
    return 0;
}
