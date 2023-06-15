// #include "BalancedBST.h"
// #include <iostream>
// #include <random>
// #include <set>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main() {
//     BalancedBST tree;

//     mt19937 engine(random_device{}());
//     uniform_int_distribution<int> distribution(10000000, 99999999);
//     set<int> unique_numbers;

//     while (unique_numbers.size() < 200) {
//         unique_numbers.insert(distribution(engine));
//     }

//     vector<int> random_numbers(unique_numbers.begin(), unique_numbers.end());
//     sort(random_numbers.begin(), random_numbers.end());
    
//     // Print the random numbers
//     for (const auto& number : random_numbers) {
//         tree.insert("name", number);
//     }

//     tree.printPostorder();

//     // vector<BalancedBST::Node*> inorderVec = tree.printInorderHelper(tree.root);

//     // random_numbers.push_back(69);

//     // for (const auto& number : random_numbers) {
//     //     if (tree.search(number) == false) {
//     //         cout << "Error: " << number << " not found" << endl;
//     //     }
//     // }

//     return 0;
// }
