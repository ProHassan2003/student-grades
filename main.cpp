#include <iostream>
#include <string>
#include "FileGenerator.h"
#include "Processor.h"
#include "Timer.h"

using namespace std;

int main() {
    try {
        cout << "===== STUDENT PROCESSING SYSTEM (v0.2) =====\n";
        cout << "1. Generate data files\n";
        cout << "2. Process existing data file\n";
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
            cout << "\nEnter file to process (example: ../data/students_10000.txt): ";
            string filename;
            cin >> filename;

            Timer timer;

            // READ STUDENTS
            timer.start();
            vector<Student> students = Processor::readStudents(filename);
            timer.stop();
            double readTime = timer.getMilliseconds();
            cout << "Read time: " << readTime << " ms\n";

            // SORT STUDENTS
            timer.start();
            Processor::sortStudents(students);
            timer.stop();
            double sortTime = timer.getMilliseconds();
            cout << "Sort time: " << sortTime << " ms\n";

            // SPLIT STUDENTS
            vector<Student> passed, failed;

            timer.start();
            Processor::splitStudents(students, passed, failed);
            timer.stop();
            double splitTime = timer.getMilliseconds();
            cout << "Split time: " << splitTime << " ms\n";

            // SAVE TO FILES
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

        } else {
            cout << "Invalid option!\n";
        }
    }
    catch (exception &e) {
        cout << "\nERROR: " << e.what() << endl;
    }

    return 0;
}
