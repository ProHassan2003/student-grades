#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

class Person {
private:
    string firstName;
    string lastName;
    vector<int> homework;
    int exam;
    double finalGrade;

public:
    // Constructor
    Person() : exam(0), finalGrade(0.0) {}

    // Copy constructor
    Person(const Person &other) {
        firstName = other.firstName;
        lastName = other.lastName;
        homework = other.homework;
        exam = other.exam;
        finalGrade = other.finalGrade;
    }

    // Assignment operator
    Person &operator=(const Person &other) {
        if (this != &other) {
            firstName = other.firstName;
            lastName = other.lastName;
            homework = other.homework;
            exam = other.exam;
            finalGrade = other.finalGrade;
        }
        return *this;
    }

    // Destructor
    ~Person() {}

    // Input method
    friend istream &operator>>(istream &in, Person &p) {
        cout << "Enter first name: ";
        in >> p.firstName;
        cout << "Enter last name: ";
        in >> p.lastName;

        cout << "Enter homework results (end with -1): ";
        int score;
        while (true) {
            in >> score;
            if (score == -1) break;
            p.homework.push_back(score);
        }

        cout << "Enter exam result: ";
        in >> p.exam;
        return in;
    }

    // Output method
    friend ostream &operator<<(ostream &out, const Person &p) {
        out << left << setw(12) << p.firstName
            << left << setw(12) << p.lastName
            << fixed << setprecision(2) << p.finalGrade;
        return out;
    }

    // Calculate final grade by average
    void calculateAverage() {
        if (homework.empty()) {
            finalGrade = exam;
            return;
        }
        double avg = accumulate(homework.begin(), homework.end(), 0.0) / homework.size();
        finalGrade = 0.4 * avg + 0.6 * exam;
    }

    // Calculate final grade by median
    void calculateMedian() {
        if (homework.empty()) {
            finalGrade = exam;
            return;
        }
        sort(homework.begin(), homework.end());
        double median;
        int n = homework.size();
        if (n % 2 == 0)
            median = (homework[n / 2 - 1] + homework[n / 2]) / 2.0;
        else
            median = homework[n / 2];
        finalGrade = 0.4 * median + 0.6 * exam;
    }
};
