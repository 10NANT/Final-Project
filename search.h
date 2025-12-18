#ifndef SEARCH_H
#define SEARCH_H

#include "Student.h"
#include <vector>

//REQUIREMENT: Searching Algorithm #1
//Linear Search used to search by NAME (unsorted text data)
int linearSearchByName(const std::vector<Student>& v,
    const std::string& name,
    int& comparisons) {
    comparisons = 0;
    for (size_t i = 0; i < v.size(); i++) {
        comparisons++;
        if (v[i].name == name)
            return static_cast<int>(i);
    }
    return -1;
}

// REQUIREMENT: Searching Algorithm #2
//Binary Search used to search by ID (sorted numeric data)
int binarySearchByID(const std::vector<Student>& v,
    int id,
    int& comparisons) {
    int left = 0;
    int right = static_cast<int>(v.size()) - 1;
    comparisons = 0;

    while (left <= right) {
        comparisons++;
        int mid = (left + right) / 2;

        if (v[mid].id == id)
            return mid;
        else if (v[mid].id < id)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

#endif

