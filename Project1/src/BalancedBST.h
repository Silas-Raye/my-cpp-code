#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

class BalancedBST {
public:
    BalancedBST();
    ~BalancedBST();

    void insert(string name, int ID);
    // - Balance the tree automatically if necessary
    void remove(int ID);
    // - Check that the input ID is valid.
    // - Find and remove the account with the specified ID from the tree.
    // - If deletion is successful, print “successful”.
    // - If the ID does not exist within the tree, print “unsuccessful”.
    // - Three cases: no children, one child, two children.
    // - You must prioritize replacing a removed node with its inorder successor for the case where the deleted node has two children.
    bool search(int ID); // done
    bool search(string name);
    // - Check that the input name is valid.
    // - Search for the student with the specified name, NAME in the tree.
    // - If the student name was found, print the associated ID.
    // - If the tree has more than one object with the same NAME, print each ID on a new line with no other spaces and in the same relative order as a pre-order traversal.
    // - If the name does not exist within the tree, print “unsuccessful”.
    void printInorder(); // done
    void printPreorder();
    // - Print out a comma separated preorder traversal of the names in the tree.
    void printPostorder();
    // - Print out a comma separated postorder traversal of the names in the tree.
    void printLevelCount();
    // - Prints the number of levels that exist in the tree.
    // - Prints 0 if the head of the tree is null. i.e. the tree's head is at depth 1.
    void removeInorder(int n);
    // - Remove the Nth GatorID from the inorder traversal of the tree (N = 0 for the first item, etc).
    // - If removal is successful, print “successful”.
    // - If the Nth GatorID does not exist within the tree, print “unsuccessful”.

private:
    struct Node {
        int ID;
        string name;
        Node* left;
        Node* right;
    };

    Node* root;

    void destructorHelper(Node* node);
    bool checkName(string name);
    bool checkID(int ID);
    void insertHelper(Node*& node, string name, int ID);
    void removeHelper(Node*& node, int ID);
    bool searchHelper(Node* node, int ID, bool printing);
    bool searchHelper(Node* node, string name);
    vector<string> printInorderHelper(Node* node);
    void printPreorderHelper(Node* node);
    void printPostorderHelper(Node* node);
    void printLevelCountHelper(Node* node);
    void removeInorderHelper(Node* node, int n);
    Node* getInorderSucessor(Node* node);
    Node* getInorderPredecessor(Node* node);
};
