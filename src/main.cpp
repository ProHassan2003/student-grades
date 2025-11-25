#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include "FileGenerator.h"
#include "Processor.h"
#include "Timer.h"

using namespace std;

int main() {
    try {
        cout << "===== STUDENT PROCESSING SYSTEM (v1.0) =====\n";
        cout << "1. Generate data files\n";
        cout << "2. Process existing data file (measure performance)\n";
        cout << "Choose option: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "\nGenerating files...\n";

            FileGenerator::generateStudentFile("data/students_10000.txt", 10000);
            FileGenerator::generateStudentFile("data/students_100000.txt", 100000);
            FileGenerator::generateStudentFile("data/students_1000000.txt", 1000000);
            FileGenerator::generateStudentFile("data/students_10000000.txt", 10000000);

            cout << "\nGeneration completed!\n";
            return 0;
        }

        else if (choice == 2) {
            cout << "\nEnter file to process (example: data/students_10000.txt): ";
            string filename;
            cin >> filename;

            cout << "\nChoose container type:\n";
            cout << "1. vector\n";
            cout << "2. list\n";
            cout << "3. deque\n";
            cout << "Your choice: ";
            int contChoice;
            cin >> contChoice;

            cout << "\nChoose strategy:\n";
            cout << "1. Strategy 1 (copy into passed + failed)\n";
            cout << "2. Strategy 2 (move failed, keep only passed)\n";
            cout << "Your choice: ";
            int stratChoice;
            cin >> stratChoice;

            Timer timer;

            if (contChoice == 1) {
                cout << "\n--- Using std::vector<Student> ---\n";

                // READ
                timer.start();
                vector<Student> students = Processor::readStudentsVector(filename);
                timer.stop();
                double readTime = timer.getMilliseconds();
                cout << "Read time: " << readTime << " ms\n";

                // SORT
                timer.start();
                Processor::sortStudents(students);
                timer.stop();
                double sortTime = timer.getMilliseconds();
                cout << "Sort time: " << sortTime << " ms\n";

                vector<Student> passed, failed;

                if (stratChoice == 1) {
                    cout << "\n--- Strategy 1: copy to passed + failed ---\n";
                    timer.start();
                    Processor::splitStrategy1(students, passed, failed);
                    timer.stop();
                } else {
                    cout << "\n--- Strategy 2: move failed, keep passed ---\n";
                    timer.start();
                    Processor::splitStrategy2(students, failed);
                    passed = students; // base now contains only passed
                    timer.stop();
                }
                double splitTime = timer.getMilliseconds();
                cout << "Split time: " << splitTime << " ms\n";

                // SAVE
                string passedFile = "output/passed.txt";
                string failedFile = "output/failed.txt";

                timer.start();
                Processor::saveStudents(passedFile, passed);
                Processor::saveStudents(failedFile, failed);
                timer.stop();
                double writeTime = timer.getMilliseconds();
                cout << "Write time: " << writeTime << " ms\n";

                cout << "\nProcessing completed successfully!\n";
                cout << "Passed file: " << passedFile << endl;
                cout << "Failed file: " << failedFile << endl;
            }
            else if (contChoice == 2) {
                cout << "\n--- Using std::list<Student> ---\n";

                // READ
                timer.start();
                list<Student> students = Processor::readStudentsList(filename);
                timer.stop();
                double readTime = timer.getMilliseconds();
                cout << "Read time: " << readTime << " ms\n";

                // SORT
                timer.start();
                Processor::sortStudents(students);
                timer.stop();
                double sortTime = timer.getMilliseconds();
                cout << "Sort time: " << sortTime << " ms\n";

                list<Student> passed, failed;

                if (stratChoice == 1) {
                    cout << "\n--- Strategy 1: copy to passed + failed ---\n";
                    timer.start();
                    Processor::splitStrategy1(students, passed, failed);
                    timer.stop();
                } else {
                    cout << "\n--- Strategy 2: move failed, keep passed ---\n";
                    timer.start();
                    Processor::splitStrategy2(students, failed);
                    timer.stop();
                    passed = students;
                }
                double splitTime = timer.getMilliseconds();
                cout << "Split time: " << splitTime << " ms\n";

                string passedFile = "output/passed.txt";
                string failedFile = "output/failed.txt";

                timer.start();
                Processor::saveStudents(passedFile, passed);
                Processor::saveStudents(failedFile, failed);
                timer.stop();
                double writeTime = timer.getMilliseconds();
                cout << "Write time: " << writeTime << " ms\n";

                cout << "\nProcessing completed successfully!\n";
                cout << "Passed file: " << passedFile << endl;
                cout << "Failed file: " << failedFile << endl;
            }
            else if (contChoice == 3) {
                cout << "\n--- Using std::deque<Student> ---\n";

                // READ
                timer.start();
                deque<Student> students = Processor::readStudentsDeque(filename);
                timer.stop();
                double readTime = timer.getMilliseconds();
                cout << "Read time: " << readTime << " ms\n";

                // SORT
                timer.start();
                Processor::sortStudents(students);
                timer.stop();
                double sortTime = timer.getMilliseconds();
                cout << "Sort time: " << sortTime << " ms\n";

                deque<Student> passed, failed;

                if (stratChoice == 1) {
                    cout << "\n--- Strategy 1: copy to passed + failed ---\n";
                    timer.start();
                    Processor::splitStrategy1(students, passed, failed);
                    timer.stop();
                } else {
                    cout << "\n--- Strategy 2: move failed, keep passed ---\n";
                    timer.start();
                    Processor::splitStrategy2(students, failed);
                    timer.stop();
                    passed = students;
                }
                double splitTime = timer.getMilliseconds();
                cout << "Split time: " << splitTime << " ms\n";

                string passedFile = "output/passed.txt";
                string failedFile = "output/failed.txt";

                timer.start();
                Processor::saveStudents(passedFile, passed);
                Processor::saveStudents(failedFile, failed);
                timer.stop();
                double writeTime = timer.getMilliseconds();
                cout << "Write time: " << writeTime << " ms\n";

                cout << "\nProcessing completed successfully!\n";
                cout << "Passed file: " << passedFile << endl;
                cout << "Failed file: " << failedFile << endl;
            }
            else {
                cout << "Invalid container choice!\n";
            }
        }
        else {
            cout << "Invalid option!\n";
        }
    }
    catch (exception &e) {
        cout << "\nERROR: " << e.what() << endl;
    }

    return 0;
}
