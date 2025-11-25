Student Grades Processing System – v1.0

This project processes large student datasets, calculates final results, and divides students into passed and failed categories using different containers (vector, list, deque) and two strategies.
The goal is to measure execution performance, optimize using STL algorithms, and compare results.

🚀 Features (v1.0)

Generate large data files (10k → 1M students)

Process using:

std::vector

std::list

std::deque

Two splitting strategies:

Strategy 1: Copy students into passed and failed

Strategy 2: Move failed students, keep only passed in original container

Performance measurement (read, sort, split, write)

Optimized using standard algorithms:

std::copy, std::remove_if, std::partition, std::find_if, etc.

📌 Releases Summary
v0.1 – Initial Version

Basic student reading

Simple grade calculations

No performance test

No splitting strategies

v0.2 – File Generation + Processing

Added automatic file generator (10k → 10M)

Processing with vector only

Split into passed/failed

Basic timing

v0.25 – Multiple Containers

Three versions:

vector

list

deque

Strategy 1 and Strategy 2 implemented

Manual performance comparison

v1.0 – Final Optimized Version (THIS RELEASE)

One universal project

Container selection menu

Strategy selection menu

Algorithm optimization using <algorithm>

Full performance measurement

Makefile + CMake support

Final documentation
Performance Table (Your Measured Results)
| **Container** | **Strategy** | **Read (ms)** | **Sort (ms)** | **Split (ms)** | **Write (ms)** | **Total Time (s)** |
| ------------- | ------------ | ------------- | ------------- | -------------- | -------------- | ------------------ |
| **vector**    | 1 (copy)     | 21.2883       | 15.5426       | 0              | 15.5812        | **164.238**        |
| **vector**    | 2 (move)     | 27.0133       | 14.0596       | 4.9848         | 16.7062        | **25.425**         |
| **list**      | 1 (copy)     | 31.1273       | 0             | 15.5807        | 15.6202        | **21.373**         |
| **list**      | 2 (move)     | 24.1334       | 5.9852        | 0              | 15.6217        | **16.655**         |
| **deque**     | 1 (copy)     | 31.1207       | 19.7868       | 2.9937         | 13.9638        | **6.395**          |
| **deque**     | 2 (move)     | 21.7068       | 15.5813       | 0              | 15.6197        | **18.904**         |

Conclusion:
Based on the performance results:

Strategy 2 (remove + shrink) is faster for vector and list containers.

Strategy 1 is unexpectedly fast for deque, giving the best total time.

List sorting takes 0 ms because it uses efficient merge sort.

Vector + Strategy 2 is the most stable and efficient overall.

Deque + Strategy 1 achieved the best performance in your measurements.

Build Instructions
Using Make (Unix / Linux / WSL):
make
./student-grades

Using CMake (Windows/Linux/MacOS):
mkdir build
cd build
cmake ..
cmake --build .

Using Code::Blocks

Open student-grades-v1.0.cbp

Build & Run

 Usage Guide

Run program

Choose:

1 – Generate data files
2 – Process data file


Enter file path:

data/students_10000.txt


Choose container:

1 – vector
2 – list
3 – deque


Choose strategy:

1 – copy into passed+failed
2 – move failed, keep passed


Output files created in:

bin/Debug/output/passed.txt
bin/Debug/output/failed.txt

