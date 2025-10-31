#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>
using namespace std;

class Person {
private:
    string firstName;
    string surname;
    vector<double> homework;
    double exam;
    double finalGrade;

public:
    // --- Rule of Three ---
    Person() : exam(0), finalGrade(0) {}
    Person(const Person& other) {
        firstName = other.firstName;
        surname = other.surname;
        homework = other.homework;
        exam = other.exam;
        finalGrade = other.finalGrade;
    }
    Person& operator=(const Person& other) {
        if (this != &other) {
            firstName = other.firstName;
            surname = other.surname;
            homework = other.homework;
            exam = other.exam;
            finalGrade = other.finalGrade;
        }
        return *this;
    }
    ~Person() {}

    friend istream& operator>>(istream& in, Person& p) {
        cout << "Enter first name: ";
        in >> p.firstName;
        cout << "Enter surname: ";
        in >> p.surname;

        cout << "Enter homework results (type -1 to finish): ";
        p.homework.clear();
        double score;
        while (in >> score && score != -1)
            p.homework.push_back(score);

        cout << "Enter exam result: ";
        in >> p.exam;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Person& p) {
        out << left << setw(10) << p.firstName
            << setw(10) << p.surname
            << setw(20) << fixed << setprecision(2)
            << p.finalGrade;
        return out;
    }

    void calculateFinal(bool useMedian) {
        double hwResult = 0.0;
        if (p.homework.empty()) hwResult = 0;
        else if (useMedian) {
            sort(homework.begin(), homework.end());
            int n = homework.size();
            if (n % 2 == 0)
                hwResult = (homework[n / 2 - 1] + homework[n / 2]) / 2.0;
            else
                hwResult = homework[n / 2];
        } else {
            hwResult = accumulate(homework.begin(), homework.end(), 0.0) / homework.size();
        }
        finalGrade = 0.4 * hwResult + 0.6 * exam;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Person> students(n);
    for (int i = 0; i < n; ++i) {
        cout << "\nStudent " << i + 1 << ":\n";
        cin >> students[i];
        students[i].calculateFinal(false); // false = average
    }

    cout << "\nName       Surname    Final_Point(Aver.)\n";
    cout << "-------------------------------------------\n";
    for (auto& s : students)
        cout << s << endl;

    return 0;
}
