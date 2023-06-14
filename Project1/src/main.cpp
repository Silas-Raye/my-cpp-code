#include "BalancedBST.h"
using namespace std;

// Note: 
// 1. You will have to comment main() when unit testing your code because catch uses its own main().
// 2. You will submit this main.cpp file and any header files you have on Gradescope.

int main(){
	BalancedBST tree;

// === GET INPUT ===
	int numLines;
    cin >> numLines;
    cin.ignore(); // ignore the newline character after reading the number of lines
	string cmds[numLines];
    for (int i = 0; i < numLines; i++) {
        string line;
        getline(cin, line);
		cmds[i] = line;
	}
	for (int i = 0; i < numLines; i++) {
		string cmd = cmds[i];

// === PARSE COMMANDS ===
		if (cmd.substr(0, 6) == "insert") {
			int count = 0;
			for (int j = 7; j < cmd.length(); j++) {
				if (cmd[j] == '"') {
					count++;
				}
			}
			if (count != 2) {
				cout << "unsuccessful" << endl;
			}
			else {
				string name;
				string idStr;
				for (int j = 8; j < cmd.length(); j++) {
					if (cmd[j] == '"') {
						name = cmd.substr(8, j - 8);
						idStr = cmd.substr(j + 2);
					}
				}
				int id = stoi(idStr);
				tree.insert(name, id);
			}
		}

		else if (cmd.substr(0, 13) == "removeInorder") {
			try {
				int num = stoi(cmd.substr(14));
				tree.removeInorder(num);
			} catch (const exception& e) {
				cout << "unsuccessful" << endl;
    		}
		}

		else if (cmd.substr(0, 6) == "remove") {
			try {
				int ID = stoi(cmd.substr(7));
				tree.remove(ID);
			} catch (const exception& e) {
				cout << "unsuccessful" << endl;
    		}
		}

		else if (cmd.substr(0, 6) == "search") {
			string arg = cmd.substr(7);
			try {
				int ID = stoi(arg);
				tree.search(ID);
			} catch (const exception& e) {
				int count = 0;
				for (int j = 7; j < cmd.length(); j++) {
					if (cmd[j] == '"') {
						count++;
					}
				}
				if (count != 2) {
					cout << "unsuccessful" << endl;
				}
				else {
					string name = cmd.substr(8, cmd.length() - 9);
					tree.search(name);
				}
    		}
		}

		else if (cmd.substr(0, 12) == "printInorder") {
			tree.printInorder();
		}

		else if (cmd.substr(0, 13) == "printPreorder") {
			tree.printPreorder();
		}

		else if (cmd.substr(0, 14) == "printPostorder") {
			tree.printPostorder();
		}

		else if (cmd.substr(0, 15) == "printLevelCount") {
			tree.printLevelCount();
		}

		else {
			//cout << "unsuccessful" << endl;
			tree.printHeight(11111111);
		}
	}

	return 0;
}
