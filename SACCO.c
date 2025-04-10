#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define HASH_SIZE 10
#define MAX_USERS 50
#define MAX_PASSWORD_LENGTH 20
#define MAX_USER_ID_LENGTH 20

#define DEPOSIT 1
#define WITHDRAW 2

int balance = 0;

// Transaction storage
int transaction_amounts[MAX_TRANSACTIONS];
int transaction_types[MAX_TRANSACTIONS];
char transaction_users[MAX_TRANSACTIONS][MAX_USER_ID_LENGTH];
int next[MAX_TRANSACTIONS];
int head = -1;
int tail = -1;
int transaction_count = 0;

// User balances (hashed)
int user_balances[HASH_SIZE];

// Stack for last N transactions
int stack[MAX_TRANSACTIONS];
int stack_top = -1;

// Queue for FIFO transaction order
int queue[MAX_TRANSACTIONS];
int front = 0, rear = 0;

// User management
char user_ids[MAX_USERS][MAX_USER_ID_LENGTH];
char passwords[MAX_USERS][MAX_PASSWORD_LENGTH];
int user_exists[MAX_USERS] = {0};
int user_count = 0;
char current_user_id[MAX_USER_ID_LENGTH] = "";

// Hash string to int
int hash_string(const char* str) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash = (hash * 31 + str[i]) % HASH_SIZE;
    }
    return hash;
}

int find_user_index(const char* user_id) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(user_ids[i], user_id) == 0) return i;
    }
    return -1;
}

void signup() {
    char id[MAX_USER_ID_LENGTH];
    char pw[MAX_PASSWORD_LENGTH];

    printf("Enter a new user ID: ");
    scanf("%s", id);

    if (find_user_index(id) != -1) {
        printf("User ID already exists.\n");
        return;
    }

    printf("Enter a password: ");
    scanf("%s", pw);

    strcpy(user_ids[user_count], id);
    strncpy(passwords[user_count], pw, MAX_PASSWORD_LENGTH);
    user_exists[user_count] = 1;
    user_count++;

    printf("Sign-up successful! Please log in.\n");
}

void login() {
    char id[MAX_USER_ID_LENGTH];
    char pw[MAX_PASSWORD_LENGTH];

    printf("Enter your user ID: ");
    scanf("%s", id);

    int index = find_user_index(id);
    if (index == -1) {
        printf("User ID not found.\n");
        return;
    }

    printf("Enter your password: ");
    scanf("%s", pw);

    if (strcmp(passwords[index], pw) == 0) {
        strcpy(current_user_id, id);
        printf("Login successful. Welcome, %s!\n", id);
    } else {
        printf("Incorrect password.\n");
    }
}

void add_transaction(int type, int amount) {
    if (transaction_count >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached.\n");
        return;
    }

    transaction_types[transaction_count] = type;
    transaction_amounts[transaction_count] = amount;
    strncpy(transaction_users[transaction_count], current_user_id, MAX_USER_ID_LENGTH);
    next[transaction_count] = -1;

    if (head == -1) {
        head = transaction_count;
    } else {
        next[tail] = transaction_count;
    }
    tail = transaction_count;
    transaction_count++;
}

void push_stack(int index) {
    if (stack_top < MAX_TRANSACTIONS - 1) {
        stack[++stack_top] = index;
    }
}

void enqueue(int index) {
    if ((rear + 1) % MAX_TRANSACTIONS != front) {
        queue[rear] = index;
        rear = (rear + 1) % MAX_TRANSACTIONS;
    }
}

void deposit(int amount) {
    int hash_index = hash_string(current_user_id);
    user_balances[hash_index] += amount;

    balance += amount;

    add_transaction(DEPOSIT, amount);
    push_stack(transaction_count - 1);
    enqueue(transaction_count - 1);

    printf("Deposited: %d\n", amount);
}

void withdraw(int amount) {
    int hash_index = hash_string(current_user_id);

    if (user_balances[hash_index] >= amount) {
        user_balances[hash_index] -= amount;
        balance -= amount;

        add_transaction(WITHDRAW, amount);
        push_stack(transaction_count - 1);
        enqueue(transaction_count - 1);

        printf("Withdrawn: %d\n", amount);
    } else {
        printf("Insufficient balance.\n");
    }
}

void show_statement() {
    printf("\n--- Transaction Statement for %s ---\n", current_user_id);
    int i = head;
    while (i != -1) {
        if (strcmp(transaction_users[i], current_user_id) == 0) {
            if (transaction_types[i] == DEPOSIT) {
                printf("Deposit: %d\n", transaction_amounts[i]);
            } else if (transaction_types[i] == WITHDRAW) {
                printf("Withdraw: %d\n", transaction_amounts[i]);
            }
        }
        i = next[i];
    }
    printf("-----------------------------------\n");
}

void show_balance() {
    int hash_index = hash_string(current_user_id);
    printf("Current balance for %s: %d\n", current_user_id, user_balances[hash_index]);
}

int main() {
    int choice, amount;

    while (1) {
        if (strlen(current_user_id) == 0) {
            printf("\n--- SACCO Login System ---\n");
            printf("1. Sign Up\n");
            printf("2. Login\n");
            printf("3. Exit\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    signup();
                    break;
                case 2:
                    login();
                    break;
                case 3:
                    exit(0);
                default:
                    printf("Invalid choice.\n");
            }
        } else {
            printf("\n--- WELCOME to our SACCO, %s ---\n", current_user_id);
            printf("\Would You Like To?\n");
            printf("1. Deposit\n");
            printf("2. Withdraw\n");
            printf("3. Show Statement\n");
            printf("4. Show Balance\n");
            printf("5. Logout\n");
            printf("6. Exit\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter amount to deposit: ");
                    scanf("%d", &amount);
                    deposit(amount);
                    break;
                case 2:
                    printf("Enter amount to withdraw: ");
                    scanf("%d", &amount);
                    withdraw(amount);
                    break;
                case 3:
                    show_statement();
                    break;
                case 4:
                    show_balance();
                    break;
                case 5:
                    printf("Logged out.\n");
                    strcpy(current_user_id, "");
                    break;
                case 6:
                    exit(0);
                default:
                    printf("Invalid option.\n");
            }
        }
    }

    return 0;
}


