#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
using namespace std;

struct Subject {
    string name;
    int maxMarks;
    int obtainedMarks;
    float credit;
    string grade;
    int gradePoint;

    void assignMarksFromGrade() {
        map<string, pair<int, float>> gradeMap = {
            {"O",  {10, 96.0}},
            {"A+", {9, 91.0}},
            {"A",  {8, 81.0}},
            {"B+", {7, 71.0}},
            {"B",  {6, 61.0}},
            {"C",  {5, 51.0}},
            {"P",  {4, 41.0}},
            {"F",  {0, 0.0}}
        };

        if (gradeMap.find(grade) != gradeMap.end()) {
            gradePoint = gradeMap[grade].first;
            float percent = gradeMap[grade].second;
            obtainedMarks = static_cast<int>((percent / 100.0f) * maxMarks);
        } else {
            cout << "Invalid grade entered for " << name << ". Assuming F.\n";
            grade = "F";
            gradePoint = 0;
            obtainedMarks = 0;
        }
    }
};

float calculateSGPA(vector<Subject>& subjects) {
    float totalCreditPoints = 0, totalCredits = 0;
    for (auto& sub : subjects) {
        totalCreditPoints += sub.gradePoint * sub.credit;
        totalCredits += sub.credit;
    }
    return (totalCredits == 0) ? 0 : totalCreditPoints / totalCredits;
}

void printResult(vector<Subject>& subjects, string semName) {
    cout << "\n--- Result for " << semName << " ---\n";
    cout << left << setw(40) << "Subject" << setw(10) << "Marks" << setw(8) << "Grade" << setw(5) << "GP" << "\n";
    for (auto& sub : subjects) {
        cout << left << setw(40) << sub.name
             << setw(10) << sub.obtainedMarks << setw(8) << sub.grade << setw(5) << sub.gradePoint << "\n";
    }
    float sgpa = calculateSGPA(subjects);
    cout << fixed << setprecision(2);
    cout << "SGPA: " << sgpa << "\n";

    // Feedback
    for (auto& sub : subjects) {
        if (sub.grade == "F") {
            cout << "⚠️  You need to reappear in: " << sub.name << " (Failed)\n";
        } else if (sub.gradePoint <= 6) {
            cout << "🔧 Work harder in: " << sub.name << " (Grade " << sub.grade << ")\n";
        }
    }
    cout << "-----------------------------\n";
}

int main() {
    // Semester 1 Subjects
    vector<Subject> sem1 = {
        {"Engineering Mathematics-I", 100, 0, 4},
        {"Computer Concepts And Programming", 150, 0, 5},
        {"Basics of Electronics & Electrical Engineering", 150, 0, 4},
        {"ICT Workshop", 50, 0, 2},
        {"Engineering Physics - I", 50, 0, 2},
        {"Foundation Course on Math & Physics", 50, 0, 0},
        {"Communicative English", 50, 0, 2},
    };

    // Semester 2 Subjects
    vector<Subject> sem2 = {
        {"Engineering Mathematics-II", 100, 0, 4},
        {"Programming with C++", 150, 0, 5},
        {"Elements of Engineering", 150, 0, 4},
        {"Environmental Sciences", 50, 0, 2},
        {"Engineering Physics - II", 50, 0, 2},
        {"Digital Electronics", 150, 0, 3},
        {"Liberal Arts Elective", 50, 0, 2},
    };

    // Input grades for Sem 1
    cout << "Enter your GRADES for Semester 1 (O, A+, A, B+, B, C, P, F):\n";
    for (auto& sub : sem1) {
        cout << sub.name << ": ";
        cin >> sub.grade;
        sub.assignMarksFromGrade();
    }

    // Input grades for Sem 2
    cout << "\nEnter your GRADES for Semester 2 (O, A+, A, B+, B, C, P, F):\n";
    for (auto& sub : sem2) {
        cout << sub.name << ": ";
        cin >> sub.grade;
        sub.assignMarksFromGrade();
    }

    // Display result
    printResult(sem1, "Semester 1");
    printResult(sem2, "Semester 2");

    // Calculate CGPA
    vector<Subject> fullYear = sem1;
    fullYear.insert(fullYear.end(), sem2.begin(), sem2.end());
    float cgpa = calculateSGPA(fullYear);
    cout << fixed << setprecision(2);
    cout << "🎓 Final CGPA for Year 1: " << cgpa << "\n";

    // Class Award
    if (cgpa >= 7.0) cout << "🏅 Award: First Class with Distinction\n";
    else if (cgpa >= 6.0) cout << "🥈 Award: First Class\n";
    else if (cgpa >= 5.0) cout << "🥉 Award: Second Class\n";
    else cout << "⚠️  You need to improve your performance!\n";

    return 0;
}
