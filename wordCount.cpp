#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int countWordsInText(const string& text) {
    istringstream iss(text);
    int count = 0;
    
    string word;
    while (iss >> word) {
        count++;
    }
    
    return count;
}

int main() {
    string filename;
    
    cout << "Enter the name of the text file: ";
    cin >> filename;
    
    ifstream inputFile(filename);
    
    if (!inputFile) {
        cout << "Error opening file: " << filename << endl;
        return 1;
    }
    
    stringstream buffer;
    buffer << inputFile.rdbuf();
    string fileContent = buffer.str();
    
    int wordCount = countWordsInText(fileContent);
    
    cout << "Total number of words in the file: " << wordCount << endl;
    
    inputFile.close();
    
    return 0;
}
