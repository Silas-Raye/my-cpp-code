/*
    Interquartile Range

    Given a sorted singly linked list without a tail (e.g, head -> 1 -> 2 -> 3 -> 4), 
    return the interquartile range of the data set using the slow and fast pointer 
    approach OR using a methodology that does not iterate over the linked list 
    twice. You must not iterate over the entire linked list more than once and you 
    cannot use arrays, vectors, lists or an STL implementation of List ADT in this problem.

    Sample Input:
        2 4 4 5 6 7 8
    
    Sample Output:
        3.00 
*/

#include <iostream>
#include <iomanip>

class Node {
    public:
        int value;
        Node* next = nullptr;
};

Node* insertEnd(Node* head, int key)
{
    Node* temp = new Node();
    temp->value = key;
    if(head == nullptr)
        head = temp;
    else
    {
        Node* curr = head;
        while(curr->next != nullptr)
            curr = curr->next;
        curr->next = temp;
    }
    return head;
}

float interQuartile(Node* head)
{
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
    return Q3 - Q1;
}