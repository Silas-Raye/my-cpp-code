#include "BalancedBST.h"
using namespace std;

BalancedBST::BalancedBST() {
    root = nullptr;
}

BalancedBST::~BalancedBST() {
    destructorHelper(root);
}

void BalancedBST::destructorHelper(Node* node) {
    if (node != nullptr) {
        destructorHelper(node->left);
        destructorHelper(node->right);
        delete node;
    }
}

bool BalancedBST::checkName(string name) {
    regex pattern("^[a-zA-Z ]*$");
    return regex_match(name, pattern);
}

bool BalancedBST::checkID(int ID) {
    if (ID < 0 || to_string(ID).length() != 8) return false;
    return true;
}

void BalancedBST::insert(string name, int ID) { // WIP
    if (checkName(name) && checkID(ID) && !searchHelper(root, ID, false)) {
        insertHelper(root, name, ID);
        cout << "successful" << endl;
    }
    else {
        cout << "unsuccessful" << endl;
    }
}

void BalancedBST::insertHelper(Node*& node, string name, int ID) { // WIP
    if (node == nullptr) {
        node = new Node;
        node->ID = ID;
        node->name = name;
        node->left = nullptr;
        node->right = nullptr;
    }
    else if (ID < node->ID) {
        insertHelper(node->left, name, ID);
    }
    else {
        insertHelper(node->right, name, ID);
    }
    //TODO: Balance the tree automatically if necessary
}

void BalancedBST::remove(int ID) {
    removeHelper(root, ID);
}

void BalancedBST::removeHelper(Node*& node, int ID) {
    // TODO: Implement removeHelper function
}

bool BalancedBST::search(int ID) {
    bool found = false;
    if (checkID(ID)) {
        found = searchHelper(root, ID, true);
    }
    else {
        cout << "unsuccessful" << endl;
    }
    return found;
}

bool BalancedBST::searchHelper(Node* node, int ID, bool printing) {
    bool found = false;
    if (node == nullptr) {
        if (printing) cout << "unsuccessful" << endl;
        found = false;
    }
    else if (ID == node->ID) {
        if (printing) cout << node->name << endl;
        found = true;
    }
    else if (ID < node->ID) {
        found = searchHelper(node->left, ID, printing);
    }
    else if (ID > node->ID) {
        found = searchHelper(node->right, ID, printing);
    }
    return found;
}

bool BalancedBST::search(string name) {
    return searchHelper(root, name);
}

bool BalancedBST::searchHelper(Node* node, string name) {
    return false;
}

void BalancedBST::printInorder() {
    vector<string> inOrderVec = printInorderHelper(root);
    if (inOrderVec.size() > 0) {
        for (int i = 0; i < inOrderVec.size() - 1; i++) {
            cout << inOrderVec[i] << ", ";
        }
        cout << inOrderVec[inOrderVec.size() - 1];
    }
    cout << endl;
}

vector<string> BalancedBST::printInorderHelper(Node* node) {
    vector<string> inOrderVec;
    // base case: if the node is null, return an empty vector
    if (node == nullptr) {
        return inOrderVec;
    }
    // traverse the left subtree
    vector<string> leftSubtree = printInorderHelper(node->left);
    inOrderVec.insert(inOrderVec.end(), leftSubtree.begin(), leftSubtree.end());
    // add the current node's value to the vector
    inOrderVec.push_back(node->name);
    // traverse the right subtree
    vector<string> rightSubtree = printInorderHelper(node->right);
    inOrderVec.insert(inOrderVec.end(), rightSubtree.begin(), rightSubtree.end());
    return inOrderVec;
}

void BalancedBST::printPreorder() {
    printPreorderHelper(root);
}

void BalancedBST::printPreorderHelper(Node* node) {
}

void BalancedBST::printPostorder() {
    printPostorderHelper(root);
}

void BalancedBST::printPostorderHelper(Node* node) {
}

void BalancedBST::printLevelCount() {
}

void BalancedBST::printLevelCountHelper(Node* node) {
}

void BalancedBST::removeInorder(int n) {
}

void BalancedBST::removeInorderHelper(Node* node, int n) {
}

BalancedBST::Node* BalancedBST::getInorderSucessor(BalancedBST::Node* node) { // untested
    // right subtree's left most node
    if (node->right != nullptr) {
        node = node->right;
        while (node->left != nullptr) {
            node = node->left;
        }
    }
    return node;
}

BalancedBST::Node* BalancedBST::getInorderPredecessor(BalancedBST::Node* node) { // untested
    // left subtree's right most node
    if (node->left != nullptr) {
        node = node->left;
        while (node->right != nullptr) {
            node = node->right;
        }
    }
    return node;
}