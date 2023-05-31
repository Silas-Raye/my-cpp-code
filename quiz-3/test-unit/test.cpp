#include "../src/interquartile_range.h"
#include <vector>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/*
	To check output (At the interquartile_range directory):
		g++ -std=c++14 -Werror -Wuninitialized -o test test-unit/test.cpp && ./test
*/

TEST_CASE("Function: IQR 4 items", "[given]") {
	Node* head = nullptr;
	for(int i = 1; i <= 4; i++)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 2.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 5 items", "[given]") {
	Node* head = nullptr;
	for(int i = 1; i <= 5; i++)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 3.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 6 items", "[given]") {
	Node* head = nullptr;
	for(int i = 1; i <= 6; i++)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 3.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 7 items", "[given]") {
	Node* head = nullptr;
	for(int i = 1; i <= 7; i++)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 4.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 8 items", "[given]") {
	Node* head = nullptr;
	for(int i = 1; i <= 8; i++)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 4.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 9 items", "[given]") {
	Node* head = nullptr;
	for(int i = 1; i <= 9; i++)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 5.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 10 items", "[given]") {
	Node* head = nullptr;
	for(int i = 1; i <= 10; i++)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 5.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 11 items", "[given]") {
	Node* head = nullptr;
	for(int i = 1; i <= 11; i++)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 6.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 12 items", "[given]") {
	Node* head = nullptr;
	for(int i = 1; i <= 12; i++)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 6.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 13 items", "[given]") {
	Node* head = nullptr;
	for(int i = 1; i <= 13; i++)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 7.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 14 items", "[given]") {
	Node* head = nullptr;
	for(int i = 1; i <= 14; i++)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 7.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 15 items", "[given]") {
	Node* head = nullptr;
	for(int i = 1; i <= 15; i++)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 8.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 16 items", "[given]") {
	Node* head = nullptr;
	for(int i = 1; i <= 16; i++)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 8.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 17 items", "[given]") {
	Node* head = nullptr;
	for(int i = 1; i <= 17; i++)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 9.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// =====

TEST_CASE("Function: IQR 1", "[given]") {
	std::vector<int> v = {2, 4, 4, 5, 6, 7, 8};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 3.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 2", "[given]") {
	std::vector<int> v = {1, 2, 3, 4};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 2.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 3", "[output_hidden]") {
	std::vector<int> v = {1, 8, 15, 43, 82, 101, 110, 2456, 55345, 137556};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 2441.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 4", "[output_hidden]") {
	std::vector<int> v = {2, 4, 4, 5, 6, 7, 8, 9, 10};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 4.50);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 5", "[output_hidden]") {
	std::vector<int> v = {1, 8, 15, 43, 82, 101, 110, 2456, 55345, 137556, 137576};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 55330.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
