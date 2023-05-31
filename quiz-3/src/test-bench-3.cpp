#include <iostream>
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

    while (speed4 != nullptr && speed4->next != nullptr && speed4->next->next != nullptr && speed4->next->next->next != nullptr) {
        speed1 = speed1->next;
        speed2 = speed2->next->next;
        speed3 = speed3->next->next->next;
        speed4 = speed4->next->next->next->next;
        count += 4;
    }
    if (speed4 == nullptr) {
        count--;
    }
    else if (speed4->next == nullptr);
    else if (speed4->next->next == nullptr) {
        count++;
    }
    else if (speed4->next->next->next == nullptr) {
        count += 2;
    }
    else if (speed4->next->next->next == nullptr) {
        count += 3;
    }

    float Q1;
    float Q3;
    if (count % 4 == 0) {
        Q1 = (speed1->value + speed1->next->value) / 2.0;
        Q3 = (speed3->value + speed3->next->value) / 2.0;
    }
    else if (count % 4 == 1) {
        Q1 = (speed1->value + speed1->next->value) / 2.0;
        Q3 = (speed3->next->value + speed3->next->next->value) / 2.0;
    }
    else if (count % 4 == 2) {
        Q1 = speed1->next->value;
        Q3 = speed3->next->next->value;
    }
    else {
        Q1 = speed1->value;
        Q3 = speed3->value;
    }

    cout << "count = " << count << endl;
    cout << "S1 = " << speed1->value << endl;
    cout << "S2 = " << speed2->value << endl;
    cout << "S3 = " << speed3->value << endl;
}

int main() {
    Node* head = nullptr;
    for (int i = 11; i > 0; i--) insert(&head, i);

    print_linked_list(head);

    print_quartiles(head);

    return 0;
}