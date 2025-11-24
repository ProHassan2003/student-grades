#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <string>
#include <vector>
#include "Student.h"

class Processor {
public:
    // Reads students from file into vector<Student>
    static std::vector<Student> readStudents(const std::string& filename);

    // Sorts vector<Student> by final score
    static void sortStudents(std::vector<Student>& students);

    // Splits into passed and failed
    static void splitStudents(
        const std::vector<Student>& students,
        std::vector<Student>& passed,
        std::vector<Student>& failed
    );

    // Saves students to file
    static void saveStudents(
        const std::string& filename,
        const std::vector<Student>& list
    );
};

#endif
