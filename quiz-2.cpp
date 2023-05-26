#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Since we don't know the number of rows and columns, we will use a 2D vector instead of a 2D array
vector<string> FlattenVector(vector<vector<string>> v) {
    const int n = v.size(); // Number of rows
    const int m = v[0].size(); // Number of columns
    vector<string> result;
    vector<string> uniqueResult;

    // Part 1: Iterate through the entire matrix and append each string to the result vector
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result.push_back(v[i][j]);
        }
    }

    // Part 2: Remove any duplicates
    for (const string& str : result) {
        bool found = false;

        // Check if the element already exists in the uniqueResult vector
        for (const string& uniqueStr : uniqueResult) {
            if (str == uniqueStr) {
                found = true;
                break;
            }
        }

        // If the element is not found, add it to the uniqueResult vector
        if (!found) {
            uniqueResult.push_back(str);
        }
    }

    return uniqueResult;
}
/* ===== Worst case time complexity: O(n * m) =====
Explanation: Part 1 has a nested loop. The outer loop iterates over the rows of the input vector, and 
the inner loop iterates over the columns. As a result, the total number of iterations is equal to O(n * m).
Part 2 uses a nested loop structure again. The outer loop iterates over each element in 'result', and 
the inner loop checks if that element already exists in the 'uniqueResult' vector. The number of 
iterations in the inner loop depends on the size of the 'uniqueResult' vector. In the worst case scenario,
where there are no duplicate elements in 'result', the 'uniqueResult' vector will have a size equal to 
'result', which is given by n * m. Therefore, the complexity of the part 2 is also O(n * m). And thus, the
overall time complexity of the function is O(n * m + n * m) = O(n * m).

   ===== Worst case space complexity: O(n * m) =====
The 'result' vector stores all the elements from the input vector 'v', so its size will be equal to the 
total number of elements in 'v', which is n * m. Therefore, the space complexity of the 'result' vector is 
O(n * m). The 'uniqueResult' vector stores the unique elements from 'result'. In the worst-case scenario, 
where there are no duplicate elements, 'uniqueResult' will also have a size of n * m. Therefore, the space 
complexity of the 'uniqueResult' vector is also O(n * m). In addition to these vectors, there are also 
constant space variables: 'n', 'm', and the iterators used in the loops. Overall, the dominant factor in 
terms of space complexity is the storage of the 'result' and 'uniqueResult' vectors. And thus, the overall 
time complexity of the function is O(n * m + n * m) = O(n * m).
*/

int main() {
    // Create a vector of vectors containing famous book names
    vector<vector<string>> books = {
        {"1984", "Animal Farm", "Brave New World"},
        {"To Kill a Mockingbird", "The Great Gatsby", "1984"},
        {"Pride and Prejudice", "Jane Eyre", "The Dispossessed"},
        {"The Dispossessed", "The Dispossessed", "The Dispossessed"}
    };

    // Flatten the vector of vectors
    vector<string> flattenedBooks = FlattenVector(books);

    // Print the flattened vector
    cout << "Flattened Books:" << endl;
    for (const string& book : flattenedBooks) {
        cout << book << endl;
    }

    return 0;
}