#include <iostream>
#include <fstream>
using namespace std;
bool complex(int num) {
    if (num <= 1) return false; 
    for (int i = 2; i * i <= num; ++i) { 
        if (num % i == 0) return true; 
    }
    return false; 
}

int complex_numbers(ifstream& file) {
    int number;
    if (!(file >> number)) { 
        return 0;
    }

    int currentSum = complex(number) ? number : 0;

    return currentSum + complex_numbers(file);
}

int main() {
    string filename = "numbers.txt"; 
    ifstream file(filename);

    if (!file) { 
        cerr << "Ошибка открытия файла: " << filename << endl;
        return 1;
    }

    int result = complex_numbers(file);

    cout << "Сумма составных чисел в файле: " << result << endl;

    file.close();
    return 0;
}