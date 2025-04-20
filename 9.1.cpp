#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
   string inputFile = "input.txt";  
   string outputFile = "output.txt"; 

    ifstream file(inputFile);
    if (!file) {
        cerr << "Ошибка открытия файла: " << inputFile << endl;
        return 1;
    }

    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    string reverse = string(content.rbegin(), content.rend());

    ofstream outFile(outputFile);
    if (!outFile) {
        cerr << "Ошибка создания файла: " << outputFile << endl;
        return 1;
    }

    outFile << reverse;
    outFile.close();

    cout << "Данные успешно скопированы в обратном порядке!" << endl;

    return 0;
}





