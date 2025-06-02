#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define M_PI if not available
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Function prototypes
void displayMenu();
void performOperation(int choice);

int main() {
    int choice;

    do {
        system("cls"); // For Windows. Use "clear" for Linux/Mac.
        displayMenu();
        printf("Enter your choice (1-13): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 12) {
            performOperation(choice);
        } else if (choice != 13) {
            printf("Invalid choice! Please try again.\n");
            getchar(); getchar(); // Wait for user
        }
    } while (choice != 13);

    printf("Thank you for using the scientific calculator. Goodbye!\n");
    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("========================================\n");
    printf("          Scientific Calculator         \n");
    printf("========================================\n");
    printf(" 1.  Addition\n");
    printf(" 2.  Subtraction\n");
    printf(" 3.  Multiplication\n");
    printf(" 4.  Division\n");
    printf(" 5.  Modulus\n");
    printf(" 6.  Sine (sin)\n");
    printf(" 7.  Cosine (cos)\n");
    printf(" 8.  Tangent (tan)\n");
    printf(" 9.  Logarithm (base e)\n");
    printf("10.  Square Root\n");
    printf("11.  Power (x^y)\n");
    printf("12.  Exponential (e^x)\n");
    printf("13.  Exit\n");
    printf("========================================\n");
}

// Function to perform the selected operation
void performOperation(int choice) {
    double num1, num2, result;

    switch (choice) {
        case 1:
            printf("\nEnter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("Result: %.2lf\n", result);
            break;
        case 2:
            printf("\nEnter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("Result: %.2lf\n", result);
            break;
        case 3:
            printf("\nEnter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("Result: %.2lf\n", result);
            break;
        case 4:
            printf("\nEnter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            if (num2 != 0)
                result = num1 / num2;
            else {
                printf("Error: Division by zero.\n");
                goto pause;
            }
            printf("Result: %.2lf\n", result);
            break;
        case 5:
            printf("\nEnter two integers: ");
            scanf("%lf %lf", &num1, &num2);
            if ((int)num2 != 0)
                printf("Result: %d\n", (int)num1 % (int)num2);
            else
                printf("Error: Modulus by zero.\n");
            break;
        case 6:
            printf("\nEnter angle in degrees: ");
            scanf("%lf", &num1);
            result = sin(num1 * M_PI / 180);
            printf("Result: sin(%.2lf°) = %.4lf\n", num1, result);
            break;
        case 7:
            printf("\nEnter angle in degrees: ");
            scanf("%lf", &num1);
            result = cos(num1 * M_PI / 180);
            printf("Result: cos(%.2lf°) = %.4lf\n", num1, result);
            break;
        case 8:
            printf("\nEnter angle in degrees: ");
            scanf("%lf", &num1);
            if (fmod(fabs(num1), 180) == 90) {
                printf("Error: tan(%.2lf°) is undefined.\n", num1);
                goto pause;
            }
            result = tan(num1 * M_PI / 180);
            printf("Result: tan(%.2lf°) = %.4lf\n", num1, result);
            break;
        case 9:
            printf("\nEnter a positive number: ");
            scanf("%lf", &num1);
            if (num1 > 0)
                result = log(num1);
            else {
                printf("Error: Logarithm of non-positive number.\n");
                goto pause;
            }
            printf("Result: log(%.2lf) = %.4lf\n", num1, result);
            break;
        case 10:
            printf("\nEnter a non-negative number: ");
            scanf("%lf", &num1);
            if (num1 >= 0)
                result = sqrt(num1);
            else {
                printf("Error: Square root of negative number.\n");
                goto pause;
            }
            printf("Result: √%.2lf = %.4lf\n", num1, result);
            break;
        case 11:
            printf("\nEnter base and exponent: ");
            scanf("%lf %lf", &num1, &num2);
            result = pow(num1, num2);
            printf("Result: %.2lf^%.2lf = %.4lf\n", num1, num2, result);
            break;
        case 12:
            printf("\nEnter exponent: ");
            scanf("%lf", &num1);
            result = exp(num1);
            printf("Result: e^%.2lf = %.4lf\n", num1, result);
            break;
    }

pause:
    printf("\nPress Enter to return to the menu...");
    getchar(); // To consume leftover '\n'
    getchar(); // Wait for Enter key
}
