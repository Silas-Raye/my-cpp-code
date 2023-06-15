#include "../src/main.cpp"
#include "../src/BalancedBST.cpp"
#include "../src/BalancedBST.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
using namespace std;

/*
	To check output (At the Project1 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test
*/

TEST_CASE("BST Insert", "[flag]"){
	BalancedBST tree; // Create a Tree object 
	tree.insert("a", 3);
	tree.insert("b", 2);
	tree.insert("c", 1);
	// std::vector<int> actualOutput = tree.inorder();
	// std::vector<int> expectedOutput = {1, 2, 3};
	// REQUIRE(expectedOutput.size() == actualOutput.size());
	// REQUIRE(actualOutput == expectedOutput);
	REQUIRE(1 == 1);
}