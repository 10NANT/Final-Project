#ifndef SORT_H
#define SORT_H

#include "Student.h"
#include <vector>
#include <utility>

//REQUIREMENT: Sorting Algorithm #1
//Bubble Sort used to rank students by GPA (highest to lowest)
void bubbleSortByGPA(std::vector<Student>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        for (size_t j = 0; j + 1 < v.size(); j++) {
            if (v[j].gpa < v[j + 1].gpa) {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}

//REQUIREMENT: Sorting Algorithm #2
//Selection Sort used to order students by ID (lowest to highest)
void selectionSortByID(std::vector<Student>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < v.size(); j++) {
            if (v[j].id < v[minIndex].id) {
                minIndex = j;
            }
        }
        std::swap(v[i], v[minIndex]);
    }
}

#endif
