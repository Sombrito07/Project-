#include <stdio.h>

struct account {
    int accountNumber;
    char name[50];
    float balance;
};

void createAccount(struct account bank[], int *totalAccounts) {
    printf("Enter account number: ");
    scanf("%d", &bank[*totalAccounts].accountNumber);
    printf("Enter account holder name: ");
    scanf("%s", bank[*totalAccounts].name);
    printf("Enter initial balance: ");
    scanf("%f", &bank[*totalAccounts].balance);
    (*totalAccounts)++;
    printf("Account created successfully!\n");
}

void depositMoney(struct account bank[], int totalAccounts) {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < totalAccounts; i++) {
        if (bank[i].accountNumber == accountNumber) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            bank[i].balance += amount;
            printf("Deposit successful!\n");
            return;
        }
    }
    printf("Account not found!\n");
}

void withdrawMoney(struct account bank[], int totalAccounts) {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < totalAccounts; i++) {
        if (bank[i].accountNumber == accountNumber) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (bank[i].balance < amount) {
                printf("Insufficient balance!\n");
                return;
            }
            bank[i].balance -= amount;
            printf("Withdrawal successful!\n");
            return;
        }
    }
    printf("Account not found!\n");
}

void displayBalance(struct account bank[], int totalAccounts) {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < totalAccounts; i++) {
        if (bank[i].accountNumber == accountNumber) {
            printf("Account holder name: %s\n", bank[i].name);
            printf("Account balance: %.2f\n", bank[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

int main() {
    struct account bank[100];
    int totalAccounts = 0;
    int choice;
    while (1) {
        printf("\n");
        printf("1. Create account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Display balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAccount(bank, &totalAccounts);
                break;
            case 2:
                depositMoney(bank, totalAccounts);
                break;
            case 3:
                withdrawMoney(bank, totalAccounts);
                break;
            case 4:
                displayBalance(bank, totalAccounts);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
