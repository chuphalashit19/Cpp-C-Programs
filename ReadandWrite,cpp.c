#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    ofstream writeFile("file.txt");

    MyWriteFile << "I love to code in C++.";

    MyWriteFile.close();

    string line;

    ifstream readFile("file.txt");

    while (getline (MyReadFile, line)) {
        cout << line;
    }

    MyReadFile.close();
}
