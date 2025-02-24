#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void encryptFile(const string &inputFilePath, const string &outputFilePath, int key){
    ifstream inputFile(inputFilePath, ios::binary);
    ofstream outputFile(outputFilePath, ios::binary);

    char ch;
    while(inputFile.get(ch)){
        outputFile.put(ch + key);
    }
    inputFile.close();
    outputFile.close();
}

void decryptFile(const string &inputFilePath, const string &outputFilePath, int key){
    ifstream inputFile(inputFilePath, ios::binary);
    ofstream outputFile(outputFilePath, ios::binary);

    char ch;
    while(inputFile.get(ch)){
        outputFile.put(key - ch);
    }
    inputFile.close();
    outputFile.close();
}

int main(){
    string inputFilePath, outputFilePath;
    int choice, key;

    cout << "1. Encrypt File\n";
    cout << "2. Decrypt File\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter key (integer): ";
    cin >> key;

    cout << "Enter input file path: ";
    cin >> inputFilePath;
    cout << "Enter output file path: ";
    cin >> outputFilePath;

    if (choice == 1){
        encryptFile(inputFilePath, outputFilePath, key);
    } else if (choice == 2){
        decryptFile(inputFilePath, outputFilePath, key);
    }else{
        cout << "Invalid choice." << endl;
    }

    return 0;
}