#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int accNo;
    char name[50];
    float balance;
};

void createAccount() {
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "ab");

    printf("Enter Account Number: ");
    scanf("%d", &acc.accNo);
    printf("Enter Name: ");
    scanf(" %[^\n]", acc.name);
    printf("Enter Initial Balance: ");
    scanf("%f", &acc.balance);

    fwrite(&acc, sizeof(acc), 1, fp);
    fclose(fp);
    printf("Account created successfully!\n");
}

void displayAllAccounts() {
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "rb");

    printf("\n--- All Accounts ---\n");
    while (fread(&acc, sizeof(acc), 1, fp)) {
        printf("Account No: %d\tName: %s\tBalance: %.2f\n", acc.accNo, acc.name, acc.balance);
    }
    fclose(fp);
}

void searchAccount() {
    int accNo, found = 0;
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "rb");

    printf("Enter account number to search: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {
            printf("Account Found: %d, Name: %s, Balance: %.2f\n", acc.accNo, acc.name, acc.balance);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account not found.\n");

    fclose(fp);
}

void depositMoney() {
    int accNo;
    float amount;
    struct Account acc;
    int found = 0;

    FILE *fp = fopen("accounts.dat", "rb+");

    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {
            acc.balance += amount;
            fseek(fp, -sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);
            printf("Deposit successful. New Balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account not found.\n");

    fclose(fp);
}

void withdrawMoney() {
    int accNo;
    float amount;
    struct Account acc;
    int found = 0;

    FILE *fp = fopen("accounts.dat", "rb+");

    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {
            if (acc.balance >= amount) {
                acc.balance -= amount;
                fseek(fp, -sizeof(acc), SEEK_CUR);
                fwrite(&acc, sizeof(acc), 1, fp);
                printf("Withdrawal successful. Remaining Balance: %.2f\n", acc.balance);
            } else {
                printf("Insufficient balance!\n");
            }
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account not found.\n");

    fclose(fp);
}

void deleteAccount() {
    int accNo, found = 0;
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    printf("Enter Account Number to delete: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo != accNo) {
            fwrite(&acc, sizeof(acc), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("accounts.dat");
    rename("temp.dat", "accounts.dat");

    if (found)
        printf("Account deleted successfully.\n");
    else
        printf("Account not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Bank Management System ---\n");
        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Search Account\n");
        printf("4. Deposit Money\n");
        printf("5. Withdraw Money\n");
        printf("6. Delete Account\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: displayAllAccounts(); break;
            case 3: searchAccount(); break;
            case 4: depositMoney(); break;
            case 5: withdrawMoney(); break;
            case 6: deleteAccount(); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}