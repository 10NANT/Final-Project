#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Student.h"
#include <iostream>

//REQUIREMENT: Linked List
struct ListNode {
    Student data;
    ListNode* next;
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(Student s) {
        ListNode* newNode = new ListNode{ s, head };
        head = newNode;
    }

    void display() {
        ListNode* current = head;
        while (current) {
            std::cout << current->data.id << " "
                << current->data.name << " "
                << current->data.gpa << std::endl;
            current = current->next;
        }
    }
};

#endif
