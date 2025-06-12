#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Convert degrees to radians
double toRadians(double degree) {
    return degree * M_PI / 180.0;
}

// Convert radians to degrees
double toDegrees(double radian) {
    return radian * 180.0 / M_PI;
}


int main() {
    double angle, value;

    printf("Enter angle in degrees: ");
    scanf("%lf", &angle);

    double rad = toRadians(angle);

    printf("\n--- Trigonometric Functions ---\n");
    printf("sin(%.2f) = %.4f\n", angle, sin(rad));
    printf("cos(%.2f) = %.4f\n", angle, cos(rad));
    printf("tan(%.2f) = %.4f\n", angle, tan(rad));

    if (cos(rad) != 0)
        printf("sec(%.2f) = %.4f\n", angle, 1 / cos(rad));
    else
        printf("sec(%.2f) = Undefined (cos = 0)\n", angle);

    if (sin(rad) != 0)
        printf("cosec(%.2f) = %.4f\n", angle, 1 / sin(rad));
    else
        printf("cosec(%.2f) = Undefined (sin = 0)\n", angle);

    if (tan(rad) != 0)
        printf("cot(%.2f) = %.4f\n", angle, 1 / tan(rad));
    else
        printf("cot(%.2f) = Undefined (tan = 0)\n", angle);

    printf("\n--- Inverse Trigonometric Functions ---\n");
    printf("Enter value for inverse functions (between -1 and 1 for sin⁻¹, cos⁻¹): ");
    scanf("%lf", &value);

    if (value >= -1 && value <= 1) {
        printf("sin⁻¹(%.2f) = %.4f degrees\n", value, toDegrees(asin(value)));
        printf("cos⁻¹(%.2f) = %.4f degrees\n", value, toDegrees(acos(value)));
    } else {
        printf("sin⁻¹ and cos⁻¹ are undefined for values outside [-1, 1]\n");
    }

    printf("tan⁻¹(%.2f) = %.4f degrees\n", value, toDegrees(atan(value)));

    if (fabs(value) >= 1) {
        printf("sec⁻¹(%.2f) = %.4f degrees\n", value, toDegrees(acos(1 / value)));
        printf("cosec⁻¹(%.2f) = %.4f degrees\n", value, toDegrees(asin(1 / value)));
    } else {
        printf("sec⁻¹ and cosec⁻¹ are undefined for values in (-1, 1)\n");
    }

    if (value != 0)
        printf("cot⁻¹(%.2f) = %.4f degrees\n", value, toDegrees(atan(1 / value)));
    else
        printf("cot⁻¹(0) = 90.0000 degrees\n");

    return 0;
}