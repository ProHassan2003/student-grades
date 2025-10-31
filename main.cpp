#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

// ================= Person Class =================
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

        cout << "Enter homework results (type -1 to finish): ";
        int score;
        p.homework.clear();
        while (in >> score && score != -1)
            p.homework.push_back(score);

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

    // Calculate average final grade
    void calculateAverage() {
        if (homework.empty()) {
            finalGrade = exam;
            return;
        }
        double avg = accumulate(homework.begin(), homework.end(), 0.0) / homework.size();
        finalGrade = 0.4 * avg + 0.6 * exam;
    }

    // Calculate median final grade
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

    // Generate random homework and exam scores
    void generateRandom(int numHW) {
        homework.clear();
        for (int i = 0; i < numHW; ++i)
            homework.push_back(rand() % 11); // 0-10
        exam = rand() % 11; // 0-10
    }
};

// ================= main() Function =================
int main() {
    srand(static_cast<unsigned>(time(0))); // Initialize random seed

    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Person> students(n);

    // Ask if user wants random data
    char randomChoice;
    cout << "Do you want to generate random homework/exam scores? (y/n): ";
    cin >> randomChoice;

    // Input or generate data
    for (int i = 0; i < n; ++i) {
        cout << "\nStudent " << i + 1 << ":\n";
        if (randomChoice == 'y' || randomChoice == 'Y') {
            int numHW;
            cout << "Enter number of homework assignments for random generation: ";
            cin >> numHW;
            students[i].generateRandom(numHW);
            cout << "Random data generated for this student.\n";
        } else {
            cin >> students[i]; // manual input
        }
    }

    // Choose calculation method
    int method;
    cout << "\nChoose final grade calculation method:\n";
    cout << "1 - Average\n";
    cout << "2 - Median\n";
    cout << "Your choice: ";
    cin >> method;

    // Calculate final grades
    for (auto &s : students) {
        if (method == 2)
            s.calculateMedian();
        else
            s.calculateAverage();
    }

    // Display results
    cout << "\nName        Surname     Final Grade\n";
    cout << "-----------------------------------\n";
    for (auto &s : students)
        cout << s << endl;

    return 0;
}
