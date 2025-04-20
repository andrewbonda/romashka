#include <iostream>
#include <cmath>
using namespace std;

bool Prime(int num) {
    if (num <= 1) return false; 
    for (int i = 2; i <= sqrt(num); ++i) { 
        if (num % i == 0) return false; 
    }
    return true;
}

bool Recursive(int current, int limit) {
    if (current > limit) return false; 

    if (Prime(current) & Prime(current + 2)) {
        cout << "Найдены близнецы: " << current << " и " << current + 2 << endl;
        return true; 
    }

    return Recursive(current + 1, limit);
}

int main() {
    int n;
    cout << "Введите натуральное число n: ";
    cin >> n;

    if (n <= 0) {
        cout << "n должно быть натуральным числом!" << endl;
        return 1;
    }

    int limit = 2 * n; 

    if (!Recursive(n, limit)) {
        cout << "Среди чисел от " << n << " до " << limit << " близнецов нет." << endl;
    }

    return 0;
}