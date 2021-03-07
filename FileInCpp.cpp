#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    ofstream writeFile("file.txt");

    writeFile << "I love to code in C++.";

    writeFile.close();

    string line;

    ifstream readFile("file.txt");

    while (getline (readFile, line)) {
        cout << line;
    }
    cout << endl << endl;
    readFile.close();
}
