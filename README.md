📘 Student Grades Processing System (C++)

This repository contains a complete implementation of a student grade processing system in C++, following the assignment requirements for:

v0.1 – Basic functionality

v0.2 – Full refactoring, file generation, sorting, splitting, timing

v0.25 – Performance comparison using vector, list, and deque

🔖 Release Versions
✅ v0.1 – Basic Implementation

Reads student data from file

Stores students in vector<Student>

Calculates final grade using:

final = 0.3 * homework_avg + 0.7 * exam


Outputs sorted students

No classes, no separate files yet

✅ v0.2 – Refactoring & Performance Measurement

This version upgrades the project significantly:

✔ Code Refactoring

The project is separated into classes, each with its own .h and .cpp:

Student (data + grade calculation)

FileGenerator (generates large test files)

Processor (reading, sorting, splitting, saving)

Timer (measures execution times)

✔ Large Data File Generator

Automatically generates:

10,000 students
100,000 students
1,000,000 students
10,000,000 students


Names use simple pattern:

Name1 Surname1
Name2 Surname2
...

✔ Data Processing

For any input file, the program:

Reads student records

Sorts by final score

Splits into:

passed → final ≥ 5.0

failed → final < 5.0

Saves into:

output/passed.txt
output/failed.txt

✔ Execution Time Measurement

The following times are recorded:

Read time

Sort time

Split time

Write time

✔ Exception Handling

Missing file

Broken data

Output file errors

🟦 v0.25 – Vector, List & Deque Performance Comparison

This version includes three fully working implementations, each in its own folder:

student-grades-v0.25-vector
student-grades-v0.25-list
student-grades-v0.25-deque

✔ Implementations

Each version uses the same logic but different STL containers:

std::vector<Student>

std::list<Student>

std::deque<Student>

✔ Tasks Perform in Each Version

Read data

Sort data

Split passed/failed

Write output

Measure time for each step

✔ Output

All versions generate:

output/passed.txt
output/failed.txt

✔ Intended Use

Created for performance comparison between container types.

📂 Project Structure
src/
│   Student.cpp / .h
│   Processor.cpp / .h
│   FileGenerator.cpp / .h
│   Timer.cpp / .h
│   main.cpp

data/            (auto-generated files)
output/          (auto-generated)

v0.25-vector/    (vector implementation)
v0.25-list/      (list implementation)
v0.25-deque/     (deque implementation)

▶ How to Run
1. Generate Data

Run program → choose:

1


This creates 10k–10M student files in /data.

2. Process Data

Run program → choose:

2


Enter:

data/students_10000.txt


Program prints:

Read time

Sort time

Split time

Write time

Output file locations

🏁 Final Notes

This project completes all requirements for:

v0.1

v0.2

v0.25

with modular structure, performance measurement, exception handling, and STL container comparison.

✍️ Author

Hassan Jehangir
