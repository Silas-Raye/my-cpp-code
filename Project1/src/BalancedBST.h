#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <stack>
#include <queue>
using namespace std;

class BalancedBST {
public:
    BalancedBST();
    ~BalancedBST();
    
private:
    struct Node {
        int ID;
        int height = 1;
        string name;
        Node* left;
        Node* right;
    };

public:
    void insert(string name, int ID);
    // Update the height after each insertion
    // Balance the tree automatically if necessary
    Node* remove(int ID);
    // Update the height after each deletion
    // See Stepik 5.2
    bool search(int ID); // done
    bool search(string name);
    // Not printing IDs in the right order in the case of duplicate names
    void printInorder(); // done
    void printPreorder(); // done
    void printPostorder(); // done
    void printLevelCount(); // done
    void removeInorder(int n); // done
    void printHeight(int ID); // temp
    void printHeightHelper(Node* node, int ID); // temp

private:
    Node* root;

    void destructorHelper(Node* node);
    bool checkName(string name);
    bool checkID(int ID);
    void insertHelper(Node*& node, string name, int ID);
    BalancedBST::Node* removeHelper(Node*& node, int ID);
    bool searchHelper(Node* node, int ID, bool printing);
    bool searchHelper(Node* node, string name);
    vector<string> printInorderHelper(Node* node);
    vector<string> printPreorderHelper(Node* node);
    vector<string> printPostorderHelper(Node* node);
    int printLevelCountHelper(Node* node);
    void removeInorderHelper(Node* node, int n);
    BalancedBST::Node* rotateLeft(Node* node);
    BalancedBST::Node* rotateRight(Node* node);
    int height(Node* node);
    //void updateNodeHeight(Node* node);
};
