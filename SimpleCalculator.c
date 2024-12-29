#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
void performOperation(int choice);

int main() {
    int choice;

    do {
        system("cls"); // Clear the screen (use "clear" for Linux/Mac)
        displayMenu();
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 5) {
            performOperation(choice);
        } else if (choice != 6) {
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    printf("Thank you for using the calculator. Goodbye!\n");
    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("=====================================\n");
    printf("          Simple Calculator          \n");
    printf("=====================================\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exit\n");
    printf("=====================================\n");
}

// Function to perform the selected operation
void performOperation(int choice) {
    double num1, num2, result;

    printf("\nEnter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    switch (choice) {
        case 1:
            result = num1 + num2;
            printf("\nResult (%.2lf + %.2lf): %.2lf\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("\nResult (%.2lf - %.2lf): %.2lf\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("\nResult (%.2lf * %.2lf): %.2lf\n", num1, num2, result);
            break;
        case 4:
            if (num2 != 0) {
                result = num1 / num2;
                printf("\nResult (%.2lf / %.2lf): %.2lf\n", num1, num2, result);
            } else {
                printf("\nError: Division by zero is not allowed.\n");
            }
            break;
        case 5:
            if ((int)num2 != 0) {
                int modResult = (int)num1 % (int)num2;
                printf("\nResult (%d %% %d): %d\n", (int)num1, (int)num2, modResult);
            } else {
                printf("\nError: Modulus by zero is not allowed.\n");
            }
            break;
    }

    printf("\nPress Enter to return to the menu...");
    getchar(); // To consume newline left by scanf
    getchar(); // Wait for Enter key
}
