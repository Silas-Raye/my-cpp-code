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
    Node* insert(string name, string ID); // done
    Node* remove(int ID); // done
    bool search(int ID); // done
    bool search(string name); // done
    void printInorder(); // done
    void printPreorder(); // done
    void printPostorder(); // done
    void printLevelCount(); // done
    void removeInorder(int n); // done

private:
    Node* root;

    void destructorHelper(Node* node);
    bool checkName(string name);
    bool checkID(string ID);
    Node* insertHelper(Node*& node, string name, int ID);
    Node* removeHelper(Node*& node, int ID);
    bool searchHelper(Node* node, int ID, bool printing);
    bool searchHelper(Node* node, string name);
    vector<Node*> printInorderHelper(Node* node);
    vector<Node*> printPreorderHelper(Node* node);
    vector<Node*> printPostorderHelper(Node* node);
    int printLevelCountHelper(Node* node);
    void removeInorderHelper(Node* node, int n);
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    int height(Node* node);
    int getBalance(Node* node);
};
