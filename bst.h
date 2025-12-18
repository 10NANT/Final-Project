#ifndef BST_H
#define BST_H

#include "Student.h"
#include <iostream>
#include <iomanip>

//REQUIREMENT: Tree (Binary Search Tree)
struct TreeNode {
    Student data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Student s) : data(s), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    //REQUIREMENT: Recursion (Recursive tree search)
    TreeNode* search(TreeNode* node, int id) {
        if (node == nullptr || node->data.id == id)
            return node;

        if (id < node->data.id)
            return search(node->left, id);
        else
            return search(node->right, id);
    }

    TreeNode* insert(TreeNode* node, Student s) {
        if (node == nullptr)
            return new TreeNode(s);

        if (s.id < node->data.id)
            node->left = insert(node->left, s);
        else
            node->right = insert(node->right, s);

        return node;
    }

public:
    BST() : root(nullptr) {}

    void insert(Student s) {
        root = insert(root, s);
    }

    void searchById(int id) {
        TreeNode* result = search(root, id);

        if (result) {
            std::cout << "Found in Binary Search Tree: "
                << result->data.id << " "
                << result->data.name << " "
                << std::fixed << std::setprecision(1)
                << result->data.gpa << std::endl;
        }
        else {
            std::cout << "Student not found in Binary Search Tree.\n";
        }
    }
};

#endif
