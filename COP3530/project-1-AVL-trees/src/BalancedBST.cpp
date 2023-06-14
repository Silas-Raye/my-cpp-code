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

BalancedBST::Node* BalancedBST::insert(string name, int ID) {
    if (checkName(name) && checkID(ID) && !searchHelper(root, ID, false)) {
        insertHelper(root, name, ID);
        cout << "successful" << endl;
    }
    else {
        cout << "unsuccessful" << endl;
    }
    return root;
}

BalancedBST::Node* BalancedBST::insertHelper(Node*& node, string name, int ID) {
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
    node->height = 1 + max(height(node->left),height(node->right));
    int balance = getBalance(node);

    if (balance > 1) { // tree is right heavy
        if (getBalance(node->right) < 0) { // tree's right subtree is left heavy
            node->right = rotateRight(node->right);
            node = rotateLeft(node);
        }
        else {
            node = rotateLeft(node);
        }
    }
    if (balance < -1) { // tree is left heavy
        if (getBalance(node->left) > 0) { // tree's left subtree is right heavy
            node->left = rotateLeft(node->left);
            node = rotateRight(node);
        }
        else {
            node = rotateRight(node);
        }
    }
    return node;
}

BalancedBST::Node* BalancedBST::remove(int ID) {
    if (checkID(ID) && searchHelper(root, ID, false)) {
        root = removeHelper(root, ID);
        cout << "successful" << endl;
        return root;
    }
    cout << "unsuccessful" << endl;
    return nullptr;
}

BalancedBST::Node* BalancedBST::removeHelper(Node*& node, int ID) {
    if (node == nullptr) {
        return node;
    }
    else if (ID < node->ID) {
        node->left = removeHelper(node->left, ID);
    }
    else if (ID > node->ID) {
        node->right = removeHelper(node->right, ID);
    }
    else if (node->ID == ID) {
        // case 1: node has no children
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
            return nullptr;
        }
        // case 2: node has one child
        else if (node->left == nullptr || node->right == nullptr) {
            if (node->left != nullptr) {
                Node* temp = node->left;
                delete node;
                node = nullptr;
                temp->height = 1 + max(height(temp->left),height(temp->right));
                return temp;
            }
            else {
                Node* temp = node->right;
                delete node;
                node = nullptr;
                return temp;
            }
        }
        // case 3: node has two children
        else {
            // inorder successor is the right subtree's left most node
            Node* inorderSuccessor = node->right;
            while (inorderSuccessor->left != nullptr) {
                inorderSuccessor = inorderSuccessor->left;
            }
            // replace node with the inorder successor and delete the inorder successor
            int tempID = inorderSuccessor->ID;
            node->name = inorderSuccessor->name;
            removeHelper(root, inorderSuccessor->ID);
            node->ID = tempID;
        }
    }
    node->height = 1 + max(height(node->left),height(node->right));
    return node;
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
    if (node == nullptr) {
        return false;
    }
    bool found = false;
    vector<Node*> preorderVec = printPreorderHelper(root);
    for (int i = 0; i < preorderVec.size(); i++) {
        if (name == preorderVec[i]->name) {
            cout << preorderVec[i]->ID << endl;
            found = true;
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
    vector<Node*> preorderVec = printPreorderHelper(root);
    if (preorderVec.size() > 0) {
        for (int i = 0; i < preorderVec.size() - 1; i++) {
            cout << preorderVec[i]->name << ", ";
        }
        cout << preorderVec[preorderVec.size() - 1]->name;
    }
    cout << endl;
}

vector<BalancedBST::Node*> BalancedBST::printPreorderHelper(Node* node) {
    vector<Node*> preorderVec;
    // base case: if the node is null, return an empty vector
    if (node == nullptr) {
        return preorderVec;
    }
    // add the current node's value to the vector
    preorderVec.push_back(node);
    // traverse the left subtree
    vector<Node*> leftSubtree = printPreorderHelper(node->left);
    preorderVec.insert(preorderVec.end(), leftSubtree.begin(), leftSubtree.end());
    // traverse the right subtree
    vector<Node*> rightSubtree = printPreorderHelper(node->right);
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
    cout << printLevelCountHelper(root) << endl;
}

int BalancedBST::printLevelCountHelper(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    int LeftHeight = printLevelCountHelper(node->left);
    int RightHeight = printLevelCountHelper(node->right);
    return max(LeftHeight, RightHeight) + 1;
}

void BalancedBST::removeInorder(int n) {
    removeInorderHelper(root, n);
}

void BalancedBST::removeInorderHelper(Node* node, int n) {
    vector<string> inorderVec = printInorderHelper(node);
    if (n <= inorderVec.size()) {
        string name = inorderVec[n];
        stack<Node*> s;
        s.push(root);
        Node* curr = nullptr;
        while (!s.empty()) {
            curr = s.top();
            s.pop();
            if (curr->name == name) {
                break;
            }
            if (curr->left) {
                s.push(curr->left);
            }
            if (curr->right) {
                s.push(curr->right);
            }
        }
        root = removeHelper(root, curr->ID);
        cout << "successful" << endl;
    }
    else {
        cout << "unsuccessful" << endl;
    }
}

BalancedBST::Node* BalancedBST::rotateLeft(Node* node) {
    Node* grandchild = node->right->left;
    Node* newParent = node->right;
    newParent->left = node;
    node->right = grandchild;
    return newParent;
}

BalancedBST::Node* BalancedBST::rotateRight(Node* node) {
    Node* grandchild = node->left->right;
    Node* newParent = node->left;
    newParent->right = node;
    node->left = grandchild;
    return newParent;
}

int BalancedBST::height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int BalancedBST::getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->right) - height(node->left);
}