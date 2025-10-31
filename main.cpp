#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <cstdlib> // rand, srand
#include <ctime>   // time
#include <fstream> // file input
using namespace std;

// ================= Person Class =================
class Person {
public:
    string firstName;
    string lastName;
    vector<int> homework;
    int exam;
    double finalAverage;
    double finalMedian;

    // Constructor
    Person() : exam(0), finalAverage(0), finalMedian(0) {}

    // Copy constructor
    Person(const Person &other) {
        firstName = other.firstName;
        lastName = other.lastName;
        homework = other.homework;
        exam = other.exam;
        finalAverage = other.finalAverage;
        finalMedian = other.finalMedian;
    }

    // Assignment operator
    Person &operator=(const Person &other) {
        if (this != &other) {
            firstName = other.firstName;
            lastName = other.lastName;
            homework = other.homework;
            exam = other.exam;
            finalAverage = other.finalAverage;
            finalMedian = other.finalMedian;
        }
        return *this;
    }

    // Destructor
    ~Person() {}

    // Input from user
    void input() {
        cout << "Enter first name: ";
        cin >> firstName;
        cout << "Enter last name: ";
        cin >> lastName;

        cout << "Enter homework results (type -1 to finish): ";
        int score;
        homework.clear();
        while (cin >> score && score != -1)
            homework.push_back(score);

        cout << "Enter exam result: ";
        cin >> exam;
    }

    // Generate random data
    void generateRandom(int numHW) {
        homework.clear();
        for (int i = 0; i < numHW; ++i)
            homework.push_back(rand() % 11); // 0-10
        exam = rand() % 11;
    }

    // Read from file
    void readFromFile(istream &in, int numHW) {
        in >> firstName >> lastName;
        homework.clear();
        int score;
        for (int i = 0; i < numHW; ++i) {
            in >> score;
            homework.push_back(score);
        }
        in >> exam;
    }

    // Calculate average grade
    void calculateAverage() {
        if (homework.empty()) {
            finalAverage = exam;
            return;
        }
        double avg = accumulate(homework.begin(), homework.end(), 0.0) / homework.size();
        finalAverage = 0.4 * avg + 0.6 * exam;
    }

    // Calculate median grade
    void calculateMedian() {
        if (homework.empty()) {
            finalMedian = exam;
            return;
        }
        sort(homework.begin(), homework.end());
        double median;
        int n = homework.size();
        if (n % 2 == 0)
            median = (homework[n / 2 - 1] + homework[n / 2]) / 2.0;
        else
            median = homework[n / 2];
        finalMedian = 0.4 * median + 0.6 * exam;
    }
};

// ================= main() Function =================
int main() {
    srand(static_cast<unsigned>(time(0))); // random seed

    // Ask user: read from file or manual/random
    char choice;
    cout << "Do you want to read student data from Students.txt? (y/n): ";
    cin >> choice;

    vector<Person> students;
    int numHW = 5; // default number of homework assignments

    if (choice == 'y' || choice == 'Y') {
        ifstream fin("Students.txt");
        if (!fin) {
            cout << "Error opening Students.txt\n";
            return 1;
        }

        // Read first line (header) to skip
        string header;
        getline(fin, header);

        // Read student data
        while (fin.peek() != EOF) {
            Person temp;
            temp.readFromFile(fin, numHW);
            students.push_back(temp);
        }
        fin.close();
        cout << "\nData loaded from Students.txt.\n";
    } else {
        int n;
        cout << "Enter number of students: ";
        cin >> n;

        students.resize(n);

        char randomChoice;
        cout << "Do you want to generate random homework/exam scores? (y/n): ";
        cin >> randomChoice;

        for (int i = 0; i < n; ++i) {
            cout << "\nStudent " << i + 1 << ":\n";
            if (randomChoice == 'y' || randomChoice == 'Y') {
                cout << "Enter number of homework assignments: ";
                cin >> numHW;
                students[i].generateRandom(numHW);
                cout << "Random data generated.\n";
            } else {
                students[i].input();
            }
        }
    }

    // Calculate grades
    for (auto &s : students) {
        s.calculateAverage();
        s.calculateMedian();
    }

    // Sort by first name (or surname)
    sort(students.begin(), students.end(), [](const Person &a, const Person &b) {
        return a.firstName < b.firstName;
    });

    // Display results
    cout << "\nName        Surname     Final(Avg.)  Final(Med.)\n";
    cout << "-----------------------------------------------\n";
    for (auto &s : students) {
        cout << left << setw(12) << s.firstName
             << left << setw(12) << s.lastName
             << fixed << setprecision(2) << setw(12) << s.finalAverage
             << fixed << setprecision(2) << s.finalMedian << endl;
    }

    return 0;
}
