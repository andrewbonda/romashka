#include <iostream>
#include <fstream>
#include <limits> 
using namespace std;

void MinMax(const string& S, int& minVal, int& maxVal) {
   ifstream file(S); 

    if (!file) { 
        cerr << "Ошибка открытия файла: " << S << endl;
        minVal = 0; 
        maxVal = 0;
        return;
    }

    bool First_value = true; 
    int number;

    while (file >> number) {
        if (First_value) {
            minVal = number;
            maxVal = number;
            First_value = false; 
        } else {
            if (number < minVal) { 
                minVal = number;
            }
            if (number > maxVal) { 
                maxVal = number;
            }
        }
    }

    file.close(); 
}

int main() {
    string S = "s.txt"; 
    int minValue, maxValue;

    MinMax(S, minValue, maxValue);

   
    if (minValue == 0 && maxValue == 0) { 
        cout << "Файл пуст или не существует." << endl;
    } else {
        cout << "Минимальное значение: " << minValue << endl;
        cout << "Максимальное значение: " << maxValue << endl;
    }

    return 0;
}