// #include <iostream>
// using namespace std;

// struct Node {
//     int value;
//     Node* next;
// };

// void insert(Node** head, int value) {
//     Node* newNode = new Node{value, nullptr};
//     newNode->next = *head;
//     *head = newNode;
// }

// void print_linked_list(Node* head) {
//     Node* current = head;
//     do {
//         cout << current->value << " ";
//         current = current->next;
//     } while (current != nullptr);
//     cout << std::endl;
// }

// void print_quartiles(Node* head) {
//     Node* ptr1 = head;
//     Node* ptr2 = head;
//     Node* ptr3 = head;
//     Node* ptr4 = head;

//     while (true) {
//         // Move ptr1 by 4 elements
//         for (int i = 0; i < 4 && ptr1 != nullptr; i++) {
//             ptr1 = ptr1->next;
//             if (ptr1 == nullptr) break;
//         }
//         if (ptr1 == nullptr) break;

//         // Move ptr2 by 3 elements
//         for (int i = 0; i < 3 && ptr2 != nullptr; i++) {
//             ptr2 = ptr2->next;
//         }

//         // Move ptr3 by 2 elements
//         for (int i = 0; i < 2 && ptr3 != nullptr; i++) {
//             ptr3 = ptr3->next;
//         }

//         // Move ptr4 by 1 element
//         ptr4 = ptr4->next;
//     }
//     //cout << ptr1->value << endl;
//     cout << ptr2->value << endl;
//     cout << ptr3->value << endl;
//     cout << ptr4->value << endl;
// }

// int main() {
//     Node* head = nullptr;
//     insert(&head, 8);
//     insert(&head, 7);
//     insert(&head, 6);
//     insert(&head, 5);
//     insert(&head, 4);
//     insert(&head, 3);
//     insert(&head, 2);
//     //insert(&head, 1);

//     print_linked_list(head);

//     print_quartiles(head);

//     return 0;
// }



// // void print_quartiles(Node* head) {
// //     Node* current = head;
// //     Node* half_current = head;
// //     Node* quarter_current = head;

// //     int count = 1;
// //     while (current->next != nullptr) {
// //         current = current->next;
// //         if (count % 2 == 0) half_current = half_current->next;
// //         if (count % 4 == 0) quarter_current = quarter_current->next; // still needs even / odd check
// //         count++;
// //     }

// //     float median;
// //     float Q1;
// //     if (count % 2 == 0) {
// //         median = (half_current->value + half_current->next->value) / 2.0;
// //         Q1 = (quarter_current->value + quarter_current->next->value) / 2.0;
// //     }
// //     else {
// //         median = half_current->value;
// //         Q1 = quarter_current->value;
// //     }

// //     cout << median << endl;
// //     cout << Q1 << endl;
// // }

// // void print_quartiles(Node* head) {
// //     Node* hammy = head; // the squirrel from over the hedge
// //     Node* haire = head;
// //     Node* verne = head; // the turtle from over the hedge
// //     Node* snail = head;

// //     int count = 1;
// //     int num_nodes = 1;
// //     while (hammy->next != nullptr) {
// //         if (count % 4 == 0) {
// //             hammy = hammy->next;
// //             num_nodes++;
// //         }
// //         if (count % 5 == 0) haire = haire->next;
// //         if (count % 8 == 0) verne = verne->next;
// //         if (count % 17 == 0) snail = snail->next;
// //         count++;
// //     }

// //     float Q1;
// //     float Q2;
// //     float Q3;
// //     float Q4;
// //     if (num_nodes % 2 == 0) {
// //         Q3 = haire->value;
// //         Q2 = (verne->value + verne->next->value) / 2.0;
// //         Q1 = snail->value;
// //     }
// //     else {
// //         Q3 = (haire->value + haire->next->value) / 2.0;
// //         Q2 = verne->value;
// //         Q1 = (snail->value + snail->next->value) / 2.0;
// //     }

// //     float ans = Q3 - Q1;
// //     cout << "num nodes " << num_nodes << endl;
// //     cout << "q2 " << Q2 << endl;
// //     cout << "q1 " << Q1 << endl;
// //     cout << "q3 " << Q3 << endl;
// //     cout << "iqr " << ans << endl;

// // }

// // void print_quartiles(Node* head) {
// //     Node* fast = head;
// //     Node* slow = head;
// //     Node* prev = nullptr;
// //     Node* next = nullptr;
// //     int count = 1;

// //     while (fast->next != nullptr) {
// //         fast = fast->next;
// //         if (count % 2 == 0) {
// //             prev = slow;
// //             slow = slow->next;
// //         }
// //         count++;
// //     }

// //     float median;
// //     if (count % 2 == 0) {
// //         median = (slow->value + slow->next->value) / 2.0;
// //         prev = prev->next;
// //         next = slow->next;
// //     }
// //     else {
// //         median = slow->value;
// //         next = slow->next;
// //     }

// //     float Q1 = (head->value + prev->value) / 2.0;
// //     float Q3 = (fast->value + next->value) / 2.0;
// //     float ans = Q3 - Q1;

// //     cout << "count " << count << endl;
// //     cout << "fast " << fast->value << endl;
// //     cout << "slow " << slow->value << endl;
// //     cout << "median " << median << endl;
// //     cout << "prev " << prev->value << endl;
// //     cout << "next " << next->value << endl;

// // }

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void iterateLinkedList(Node* start) {
    Node* ptr1 = start;
    Node* ptr2 = start;
    Node* ptr3 = start;
    Node* ptr4 = start;

    while (ptr1 != nullptr && ptr2 != nullptr && ptr3 != nullptr && ptr4 != nullptr) {
        // Move ptr4 by 1 element
        std::cout << ptr4->data << " ";
        ptr4 = ptr4->next;

        // Move ptr3 by 2 elements
        for (int i = 0; i < 2 && ptr3 != nullptr; i++) {
            std::cout << ptr3->data << " ";
            ptr3 = ptr3->next;
        }

        // Move ptr2 by 3 elements
        for (int i = 0; i < 3 && ptr2 != nullptr; i++) {
            std::cout << ptr2->data << " ";
            ptr2 = ptr2->next;
        }
        
        // Move ptr1 by 4 elements
        for (int i = 0; i < 4 && ptr1 != nullptr; i++) {
            std::cout << ptr1->data << " ";
            ptr1 = ptr1->next;
        }

        

        

        
    }

    cout << endl << endl << endl << ptr2->data << endl << ptr3->data << endl << ptr4->data << endl;
}

int main() {
    // Create a sample linked list
    Node* head = new Node{1, nullptr};
    Node* node1 = new Node{2, nullptr};
    Node* node2 = new Node{3, nullptr};
    Node* node3 = new Node{4, nullptr};
    Node* node4 = new Node{5, nullptr};
    Node* node5 = new Node{6, nullptr};
    Node* node6 = new Node{7, nullptr};
    Node* node7 = new Node{8, nullptr};
    Node* node8 = new Node{9, nullptr};
    Node* node9 = new Node{10, nullptr};

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;

    iterateLinkedList(head);

    // Clean up the memory
    delete head;
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete node7;
    delete node8;
    delete node9;

    return 0;
}
