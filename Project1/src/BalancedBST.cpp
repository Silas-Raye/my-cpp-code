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
    if (checkID(ID) && searchHelper(root, ID, true)) {
        return true;
    }
    cout << "unsuccessful" << endl;
    return false;
}

bool BalancedBST::searchHelper(Node* node, int ID, bool printing) {
    if (node == nullptr) {
        if (printing) cout << "unsuccessful" << endl;
        return false;
    }
    else if (ID == node->ID) {
        if (printing) cout << node->name << endl;
        return true;
    }
    else if (ID < node->ID) {
        return searchHelper(node->left, ID, printing);
    }
    else if (ID > node->ID) {
        return searchHelper(node->right, ID, printing);
    }
    return false;
}

bool BalancedBST::search(string name) {
    if (checkName(name) && searchHelper(root, name)) {
        return true;
    }
    cout << "unsuccessful" << endl;
    return false;
}

bool BalancedBST::searchHelper(Node* node, string name) {
    bool found = false;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        if (curr->name == name) {
            cout << curr->ID << endl;
            found = true;
        }
        if (curr->left) {
            s.push(curr->left);
        }
        if (curr->right) {
            s.push(curr->right);
        }
    }
    return found;
}

void BalancedBST::printInorder() {
    vector<string> inorderVec = printInorderHelper(root);
    if (inorderVec.size() > 0) {
        for (int i = 0; i < inorderVec.size() - 1; i++) {
            cout << inorderVec[i] << ", ";
        }
        cout << inorderVec[inorderVec.size() - 1];
    }
    cout << endl;
}

vector<string> BalancedBST::printInorderHelper(Node* node) {
    vector<string> inorderVec;
    // base case: if the node is null, return an empty vector
    if (node == nullptr) {
        return inorderVec;
    }
    // traverse the left subtree
    vector<string> leftSubtree = printInorderHelper(node->left);
    inorderVec.insert(inorderVec.end(), leftSubtree.begin(), leftSubtree.end());
    // add the current node's value to the vector
    inorderVec.push_back(node->name);
    // traverse the right subtree
    vector<string> rightSubtree = printInorderHelper(node->right);
    inorderVec.insert(inorderVec.end(), rightSubtree.begin(), rightSubtree.end());
    return inorderVec;
}

void BalancedBST::printPreorder() {
    vector<string> preorderVec = printPreorderHelper(root);
    if (preorderVec.size() > 0) {
        for (int i = 0; i < preorderVec.size() - 1; i++) {
            cout << preorderVec[i] << ", ";
        }
        cout << preorderVec[preorderVec.size() - 1];
    }
    cout << endl;
}

vector<string> BalancedBST::printPreorderHelper(Node* node) {
    vector<string> preorderVec;
    // base case: if the node is null, return an empty vector
    if (node == nullptr) {
        return preorderVec;
    }
    // add the current node's value to the vector
    preorderVec.push_back(node->name);
    // traverse the left subtree
    vector<string> leftSubtree = printPreorderHelper(node->left);
    preorderVec.insert(preorderVec.end(), leftSubtree.begin(), leftSubtree.end());
    // traverse the right subtree
    vector<string> rightSubtree = printPreorderHelper(node->right);
    preorderVec.insert(preorderVec.end(), rightSubtree.begin(), rightSubtree.end());
    return preorderVec;
}

void BalancedBST::printPostorder() {
    vector<string> postorderVec = printPostorderHelper(root);
    if (postorderVec.size() > 0) {
        for (int i = 0; i < postorderVec.size() - 1; i++) {
            cout << postorderVec[i] << ", ";
        }
        cout << postorderVec[postorderVec.size() - 1];
    }
    cout << endl;
}

vector<string> BalancedBST::printPostorderHelper(Node* node) {
    vector<string> postorderVec;
    // base case: if the node is null, return an empty vector
    if (node == nullptr) {
        return postorderVec;
    }
    // traverse the left subtree
    vector<string> leftSubtree = printPostorderHelper(node->left);
    postorderVec.insert(postorderVec.end(), leftSubtree.begin(), leftSubtree.end());
    // traverse the right subtree
    vector<string> rightSubtree = printPostorderHelper(node->right);
    postorderVec.insert(postorderVec.end(), rightSubtree.begin(), rightSubtree.end());
    // add the current node's value to the vector
    postorderVec.push_back(node->name);
    return postorderVec;
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
