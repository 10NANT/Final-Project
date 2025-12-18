#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <iomanip>

#include "Student.h"
#include "LinkedList.h"
#include "BST.h"
#include "Sort.h"
#include "Search.h"

void displayStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No students available.\n";
        return;
    }

    for (const auto& s : students) {
        std::cout << s.id << " "
            << s.name << " "
            << std::fixed << std::setprecision(1)
            << s.gpa << std::endl;
    }
}

int main() {

    //REQUIREMENT: Vector
    std::vector<Student> students;

    //REQUIREMENT: Linked List
    LinkedList recentAdds;

    //REQUIREMENT: Stack
    std::stack<Student> undoStack;

    //REQUIREMENT: STL Container
    std::map<int, Student> studentMap;

    int choice;

    do {
        std::cout << "\n1. Add Student\n";
        std::cout << "2. Display Students\n";
        std::cout << "3. Sort Students by GPA (Bubble Sort)\n";
        std::cout << "4. Sort Students by ID (Selection Sort)\n";
        std::cout << "5. Search Student by Name (Linear Search)\n";
        std::cout << "6. Search Student by ID (Binary Search)\n";
        std::cout << "7. Search Student by ID (Binary Search Tree)\n";
        std::cout << "8. Delete Student (Undo Supported)\n";
        std::cout << "9. Undo Delete\n";
        std::cout << "0. Exit\n";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << std::endl;

            Student s;
            std::cout << "ID: ";
            std::cin >> s.id;
            std::cout << "Name: ";
            std::cin >> s.name;
            std::cout << "GPA: ";
            std::cin >> s.gpa;

            students.push_back(s);
            recentAdds.insert(s);
            studentMap[s.id] = s;

            std::cout << "\nStudent added.\n";
            displayStudents(students);
        }

        else if (choice == 2) {
            std::cout << std::endl;
            displayStudents(students);
        }

        else if (choice == 3) {
            std::cout << std::endl;

            std::cout << "Students before GPA sort:\n";
            displayStudents(students);

            //REQUIREMENT: Sorting Algorithm #1
            bubbleSortByGPA(students);

            std::cout << "\nStudents after GPA sort (highest to lowest):\n";
            displayStudents(students);
        }

        else if (choice == 4) {
            std::cout << std::endl;

            std::cout << "Students before ID sort:\n";
            displayStudents(students);

            //REQUIREMENT: Sorting Algorithm #2
            selectionSortByID(students);

            std::cout << "\nStudents after ID sort (lowest to highest):\n";
            displayStudents(students);
        }

        else if (choice == 5) {
            std::cout << std::endl;

            std::string name;
            int comparisons;

            std::cout << "Enter name: ";
            std::cin >> name;

            //REQUIREMENT: Searching Algorithm #1
            int index = linearSearchByName(students, name, comparisons);

            if (index != -1) {
                std::cout << "Found using Linear Search: "
                    << students[index].name << "\n";
            }
            else {
                std::cout << "Student not found.\n";
            }

            std::cout << "Comparisons made: " << comparisons << "\n";
        }

        else if (choice == 6) {
            std::cout << std::endl;

            int id, comparisons;
            std::cout << "Enter ID: ";
            std::cin >> id;

            // Binary search requires sorted data
            selectionSortByID(students);

            //REQUIREMENT: Searching Algorithm #2
            int index = binarySearchByID(students, id, comparisons);

            if (index != -1) {
                std::cout << "Found using Binary Search: "
                    << students[index].name << "\n";
            }
            else {
                std::cout << "Student not found.\n";
            }

            std::cout << "Comparisons made: " << comparisons << "\n";
        }

        else if (choice == 7) {
            std::cout << std::endl;

            int id;
            std::cout << "Enter ID: ";
            std::cin >> id;

            //REQUIREMENT: Tree + Recursion
            BST tree;
            for (const auto& s : students) {
                tree.insert(s);
            }

            tree.searchById(id);
        }

        else if (choice == 8) {
            std::cout << std::endl;

            if (!students.empty()) {
                Student removed = students.back();
                undoStack.push(removed);
                studentMap.erase(removed.id);
                students.pop_back();

                std::cout << "Deleted student: "
                    << removed.id << " "
                    << removed.name << "\n";

                displayStudents(students);
            }
            else {
                std::cout << "No students to delete.\n";
            }
        }

        else if (choice == 9) {
            std::cout << std::endl;

            if (!undoStack.empty()) {
                Student restored = undoStack.top();
                undoStack.pop();
                students.push_back(restored);
                studentMap[restored.id] = restored;

                std::cout << "Restored student: "
                    << restored.id << " "
                    << restored.name << "\n";

                displayStudents(students);
            }
            else {
                std::cout << "Nothing to undo.\n";
            }
        }

    } while (choice != 0);

    return 0;
}
