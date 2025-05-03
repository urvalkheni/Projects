#include <iostream>
#include <string>
#include <fstream>
#include <limits> // for numeric_limits
using namespace std;

class Vehicle {
private:
    string brand;
    string model;
    int year;

public:
    Vehicle() : year(0) {} // Default constructor

    void getInput(const string& type) {
        cout << "Enter " << type << " Brand: ";
        getline(cin, brand);

        cout << "Enter " << type << " Model: ";
        getline(cin, model);

        while (true) {
            cout << "Enter " << type << " Year: ";
            string yearStr;
            getline(cin, yearStr);
            try {
                year = stoi(yearStr);
                if (year > 1885 && year <= 2100) break;
                else throw invalid_argument("Invalid range");
            } catch (...) {
                cout << "Invalid year. Please enter a valid number (1886–2100).\n";
            }
        }
    }

    void saveToFile(const string& filename) const {
        ofstream out(filename, ios::app);
        if (!out) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        out << "Brand: " << brand << endl;
        out << "Model: " << model << endl;
        out << "Year: " << year << endl;
        out << "-----" << endl;
        out.close();
    }

    static void displayFromFile(const string& filename, const string& type) {
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

    car.saveToFile("cars.txt");
    bike.saveToFile("bikes.txt");

    Vehicle::displayFromFile("cars.txt", "Car");
    Vehicle::displayFromFile("bikes.txt", "Bike");

    return 0;
}
