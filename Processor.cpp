#include "Processor.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <iostream>

std::vector<Student> Processor::readStudents(const std::string& filename) {
    std::ifstream in(filename);
    if (!in.is_open()) {
        throw std::runtime_error("Cannot open input file: " + filename);
    }

    std::vector<Student> students;
    std::string line;

    // Skip header
    std::getline(in, line);

    while (std::getline(in, line)) {
        std::istringstream ss(line);
        std::string fn, ln;
        std::vector<int> hw(5);
        int exam;

        ss >> fn >> ln;
        for (int i = 0; i < 5; i++)
            ss >> hw[i];
        ss >> exam;

        Student s(fn, ln, hw, exam);
        students.push_back(s);
    }

    return students;
}


void Processor::sortStudents(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) {
                  return a.getFinalScore() < b.getFinalScore();
              });
}


void Processor::splitStudents(
        const std::vector<Student>& students,
        std::vector<Student>& passed,
        std::vector<Student>& failed
    ) 
{
    for (const auto& s : students) {
        if (s.getFinalScore() >= 5.0)
            passed.push_back(s);
        else
            failed.push_back(s);
    }
}


void Processor::saveStudents(
        const std::string& filename,
        const std::vector<Student>& list
    )
{
    std::ofstream out(filename);

    if (!out.is_open()) {
        throw std::runtime_error("Cannot open output file: " + filename);
    }

    out << "FirstName LastName FinalScore\n";

    for (const auto& s : list) {
        out << s.getFirstName() << " "
            << s.getLastName() << " "
            << s.getFinalScore() << "\n";
    }

    out.close();
}
