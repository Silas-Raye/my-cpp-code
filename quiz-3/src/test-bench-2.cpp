#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Node {
    int value;
    Node* next;
};

void insert(Node** head, int value) {
    Node* newNode = new Node{value, nullptr};
    newNode->next = *head;
    *head = newNode;
}

// void insert(Node** head, int value) {
//     Node* newNode = new Node{value, nullptr};

//     if (*head == nullptr) {
//         *head = newNode;
//     } else {
//         Node* current = *head;
//         while (current->next != nullptr) {
//             current = current->next;
//         }
//         current->next = newNode;
//     }
// }

void print_linked_list(Node* head) {
    Node* current = head;
    do {
        cout << current->value << " ";
        current = current->next;
    } while (current != nullptr);
    cout << std::endl;
}

void print_quartiles(Node* head) {
    Node* speed4 = head->next->next->next;
    Node* speed3 = head->next->next;
    Node* speed2 = head->next;
    Node* speed1 = head;
    int count = 4;

    while (speed4->next != nullptr && speed4->next->next != nullptr && speed4->next->next->next != nullptr) {
        speed1 = speed1->next;
        speed2 = speed2->next->next;
        speed3 = speed3->next->next->next;
        speed4 = speed4->next->next->next->next;


        /*speed4 = speed4->next;
        if (count % 4 != 3) speed3 = speed3->next;
        if (count % 2 == 0) speed2 = speed2->next;
        if (count % 4 == 0) speed1 = speed1->next;*/
        count += 4;
    }
    if (speed4->next->next == nullptr) {
        count++;
    }
    else if (speed4->next->next->next == nullptr) {
        count += 2;
    }
    else if (speed4->next->next->next->next == nullptr) {
        count += 3;
    }
    /*float Q1;
    float Q2;
    float Q3;
    if (count % 2 == 0) {
        Q1 = (slow2->value + slow2->next->value) / 2.0;
        Q2 = (slow1->value + slow1->next->value) / 2.0;
        Q3 = (fast2->value + fast2->next->value) / 2.0;
    }
    else {
        Q1 = slow2->value;
        Q2 = slow1->value;
        Q3 = fast2->value;
    }*/

    float Q1;
    float Q3;
    cout << "count = " << count << endl;
    if (count % 4 == 0) {
        
    }
    else if (count % 4 == 1) {
        
    }
    else if (count % 4 == 2) {
        
    }
    else {
        Q1 = speed1->next->value;
        Q3 = speed3->next->next->next->value;
    }

    cout << "S1 = " << speed1->value << endl;
    cout << "S2 = " << speed2->value << endl;
    cout << "S3 = " << speed3->value << endl;
    cout << "IQR = " << Q3 - Q1 << endl;
}

int main() {
    Node* head = nullptr;
    for (int i = 4; i > 0; i--) insert(&head, i);
    
    // string str = "2 3 4 5 6 7 8 9 10";
    // istringstream iss(str);
    // int num;
    // while (iss >> num) {
    //     insert(&head, num);
    // }

    print_linked_list(head);

    print_quartiles(head);

    return 0;
}