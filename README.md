Student Grades Processing System

This project implements a full student grading system using C++, following the assignment requirements for v0.1, v0.2, and v0.25 releases.

📌 Version Overview
✅ v0.1 – Initial Working Version

Reads student records from a text file

Calculates final grades

Outputs sorted results

✅ v0.2 – Full Refactoring with Classes & Performance Measurement

This release includes major improvements required by the assignment:

✔ Refactored Structure

Code separated into classes:

Student

FileGenerator

Processor

Timer

Each class has its own .h and .cpp files

Clean, modular architecture

✔ File Generation

Automatically generates files with:

10,000 students

100,000 students

1,000,000 students

10,000,000 students

Using simple names like:

Name1 Surname1
Name2 Surname2
...

✔ Processing Features

For any input file:

Reads student records

Calculates final scores

Sorts students

Splits into:

passed (final ≥ 5.0)

failed (final < 5.0)

Outputs:

output/passed.txt
output/failed.txt

✔ Performance Measurement

The program measures:

File reading time

Sorting time

Splitting time

Writing time

(using a custom Timer class)

✔ Exception Handling

Handles errors such as:

Missing input file

Unable to create output file

Bad data format

Keeps the program stable.
