#include <stdio.h>
#include <math.h>

// Function Prototypes
void printSquare(int size);
void printRectangle(int rows, int cols);
void printRightTriangle(int size);
void printInvertedTriangle(int size);
void printEquilateralTriangle(int size);
void printPyramid(int size);
void printDiamond(int size);
void printCircle(int radius);
void printHexagon(int size);
void printPentagon(int size);

int main() {
    int choice, size, rows, cols;

    while (1) {
        printf("\n--- Shape Printer Menu ---\n");
        printf("1. Square\n");
        printf("2. Rectangle\n");
        printf("3. Right-Angled Triangle\n");
        printf("4. Inverted Triangle\n");
        printf("5. Equilateral Triangle\n");
        printf("6. Pyramid\n");
        printf("7. Diamond\n");
        printf("8. Circle (ASCII Approximation)\n");
        printf("9. Hexagon (ASCII)\n");
        printf("10. Pentagon (ASCII)\n");
        printf("11. Exit\n");
        printf("Enter your choice (1-11): ");
        scanf("%d", &choice);

        if (choice == 11) {
            printf("Exiting the program.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter size: ");
                scanf("%d", &size);
                printSquare(size);
                break;
            case 2:
                printf("Enter rows and columns: ");
                scanf("%d %d", &rows, &cols);
                printRectangle(rows, cols);
                break;
            case 3:
                printf("Enter size: ");
                scanf("%d", &size);
                printRightTriangle(size);
                break;
            case 4:
                printf("Enter size: ");
                scanf("%d", &size);
                printInvertedTriangle(size);
                break;
            case 5:
                printf("Enter size: ");
                scanf("%d", &size);
                printEquilateralTriangle(size);
                break;
            case 6:
                printf("Enter size: ");
                scanf("%d", &size);
                printPyramid(size);
                break;
            case 7:
                printf("Enter size: ");
                scanf("%d", &size);
                printDiamond(size);
                break;
            case 8:
                printf("Enter radius: ");
                scanf("%d", &size);
                printCircle(size);
                break;
            case 9:
                printf("Enter size: ");
                scanf("%d", &size);
                printHexagon(size);
                break;
            case 10:
                printf("Enter size: ");
                scanf("%d", &size);
                printPentagon(size);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Shape Functions
void printSquare(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) printf("* ");
        printf("\n");
    }
}

void printRectangle(int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) printf("* ");
        printf("\n");
    }
}

void printRightTriangle(int size) {
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= i; j++) printf("* ");
        printf("\n");
    }
}

void printInvertedTriangle(int size) {
    for (int i = size; i >= 1; i--) {
        for (int j = 1; j <= i; j++) printf("* ");
        printf("\n");
    }
}

void printEquilateralTriangle(int size) {
    for (int i = 1; i <= size; i++) {
        for (int j = i; j < size; j++) printf(" ");
        for (int k = 1; k <= (2 * i - 1); k++) printf("*");
        printf("\n");
    }
}

void printPyramid(int size) {
    for (int i = 1; i <= size; i++) {
        for (int j = i; j < size; j++) printf("  ");
        for (int k = 1; k <= (2 * i - 1); k++) printf("* ");
        printf("\n");
    }
}

void printDiamond(int size) {
    for (int i = 1; i <= size; i++) {
        for (int j = i; j < size; j++) printf("  ");
        for (int k = 1; k <= (2 * i - 1); k++) printf("* ");
        printf("\n");
    }
    for (int i = size - 1; i >= 1; i--) {
        for (int j = size; j > i; j--) printf("  ");
        for (int k = 1; k <= (2 * i - 1); k++) printf("* ");
        printf("\n");
    }
}

void printCircle(int r) {
    float dist;
    for (int i = 0; i <= 2 * r; i++) {
        for (int j = 0; j <= 2 * r; j++) {
            dist = sqrt((i - r) * (i - r) + (j - r) * (j - r));
            if (dist > r - 0.5 && dist < r + 0.5)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void printHexagon(int size) {
    for (int i = 1; i <= size; i++) {
        for (int j = i; j < size; j++) printf(" ");
        for (int k = 1; k <= size; k++) printf("* ");
        printf("\n");
    }
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j < i; j++) printf(" ");
        for (int k = 1; k <= size; k++) printf("* ");
        printf("\n");
    }
}

void printPentagon(int size) {
    int i, j;
    for (i = 1; i <= size; i++) {
        for (j = i; j < size; j++) printf(" ");
        for (j = 1; j <= (2 * i - 1); j++) printf("*");
        printf("\n");
    }
    for (i = 1; i <= size - 1; i++) {
        for (j = 1; j <= (2 * size - 1); j++) printf("*");
        printf("\n");
    }
}