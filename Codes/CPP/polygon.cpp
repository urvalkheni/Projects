#include <iostream>
#include <iomanip>
using namespace std;

void printPolygonName(int sides) {
    switch (sides) {
        case 3:  cout << "Polygon Name: Triangle\n"; break;
        case 4:  cout << "Polygon Name: Quadrilateral\n"; break;
        case 5:  cout << "Polygon Name: Pentagon\n"; break;
        case 6:  cout << "Polygon Name: Hexagon\n"; break;
        case 7:  cout << "Polygon Name: Heptagon\n"; break;
        case 8:  cout << "Polygon Name: Octagon\n"; break;
        case 9:  cout << "Polygon Name: Nonagon\n"; break;
        case 10: cout << "Polygon Name: Decagon\n"; break;
        case 11: cout << "Polygon Name: Hendecagon\n"; break;
        case 12: cout << "Polygon Name: Dodecagon\n"; break;
        default: cout << "Polygon Name: Unknown (not in database)\n";
    }
}

int main() {
    int sides;
    const int MIN_SIDES = 3;
    const int MAX_SIDES = 12;

    cout << "Enter the number of sides of the polygon (" << MIN_SIDES << " to " << MAX_SIDES << "): ";
    cin >> sides;

    if (sides < MIN_SIDES || sides > MAX_SIDES) {
        cout << "Error: Please enter sides between " << MIN_SIDES << " and " << MAX_SIDES << ".\n";
        return 1;
    }

    int totalAngle = (sides - 2) * 180;
    double oneAngle = static_cast<double>(totalAngle) / sides;

    cout << "\n--- Polygon Details ---\n";
    printPolygonName(sides);
    cout << "Total Interior Angle: " << totalAngle << " degrees\n";
    cout << fixed << setprecision(2);
    cout << "One Interior Angle (if regular): " << oneAngle << " degrees\n";

    return 0;
}
