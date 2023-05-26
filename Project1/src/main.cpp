#include <iostream>
#include <string>
using namespace std;

/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

int main(){
	int numLines;
    cin >> numLines;
    cin.ignore(); // Ignore the newline character after reading the number of lines

	string cmds[numLines];
    for (int i = 0; i < numLines; i++) {
        string line;
        getline(cin, line);
		cmds[i] = line;
	}

	for (int i = 0; i < numLines; i++) {
		string cmd = cmds[i];
		if (cmd.substr(0, 6) == "insert") {}
		if (cmd.substr(0, 6) == "remove") {}
		if (cmd.substr(0, 6) == "search") {
			string arg = cmd.substr(7);
			try {
				int number = stoi(arg);
				cout << "search f(x) on " << number << endl;
			} catch (const exception& e) {
				cout << "search f(x) on " << arg << endl;
    		}
		}
		if (cmd.substr(0, 12) == "printInorder") {}
		if (cmd.substr(0, 13) == "printPreorder") {}
		if (cmd.substr(0, 14) == "printPostorder") {}
		if (cmd.substr(0, 15) == "printLevelCount") {}
		if (cmd.substr(0, 13) == "removeInorder") {}
	}

	return 0;
}

