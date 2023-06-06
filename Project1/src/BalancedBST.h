#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <stack>
using namespace std;

class BalancedBST {
public:
    BalancedBST();
    ~BalancedBST();

private:
    // - Add a height element to the node struct and update the height after each insertion/deletion.
    struct Node {
        int ID;
        string name;
        Node* left;
        Node* right;
    };

public:
    void insert(string name, int ID);
    // - Balance the tree automatically if necessary
    Node* remove(int ID);
    // - case 3: node has two children is broken
    bool search(int ID); // done
    bool search(string name); // done
    void printInorder(); // done
    void printPreorder(); // done
    void printPostorder(); // done
    void printLevelCount();
    // - Prints the number of levels that exist in the tree.
    // - Prints 0 if the head of the tree is null. i.e. the tree's head is at depth 1.
    void removeInorder(int n); // done

private:
    Node* root;

    void destructorHelper(Node* node);
    bool checkName(string name);
    bool checkID(int ID);
    void insertHelper(Node*& node, string name, int ID);
    BalancedBST::Node* removeHelper(Node*& node, int ID);
    bool searchHelper(Node* node, int ID, bool printing);
    bool searchHelper(Node* node, string name, bool printing);
    vector<string> printInorderHelper(Node* node);
    vector<string> printPreorderHelper(Node* node);
    vector<string> printPostorderHelper(Node* node);
    void printLevelCountHelper(Node* node);
    void removeInorderHelper(Node* node, int n);
};
