#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Vehicle {
public:
    string brand;
    string model;
    int year;

    void getInput(string type) {
        cout << "Enter " << type << " Brand: ";
        getline(cin, brand);

        cout << "Enter " << type << " Model: ";
        getline(cin, model);

        string yearStr;
        cout << "Enter " << type << " Year: ";
        getline(cin, yearStr);
        year = stoi(yearStr); // Convert string to int
    }

    void saveToFile(string filename) {
        ofstream out(filename, ios::app); // Append mode
        out << brand << endl;
        out << model << endl;
        out << year << endl;
        out << "-----" << endl; // Separator
        out.close();
    }

    void displayFromFile(string filename, string type) {
        ifstream in(filename);
        if (!in) {
            cout << type << " data not found.\n";
            return;
        }
        cout << "\n--- " << type << " Details ---\n";
        string line;
        while (getline(in, line)) {
            if (line == "-----") {
                cout << "------------------------\n";
                continue;
            }
            cout << line << endl;
        }
        in.close();
    }
};

int main() {
    Vehicle car, bike;

    cout << "Enter Car Details:\n";
    car.getInput("Car");

    cout << "\nEnter Bike Details:\n";
    bike.getInput("Bike");

    // Save
    car.saveToFile("cars.txt");
    bike.saveToFile("bikes.txt");

    // Display
    car.displayFromFile("cars.txt", "Car");
    bike.displayFromFile("bikes.txt", "Bike");

    return 0;
}
