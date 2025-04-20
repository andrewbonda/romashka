#include <iostream>
using namespace std;

const int max_M = 100;
const int max_N = 100;

// Функция f(a): возвращает индекс наименьшего элемента строки a
int f(double a[], int N) {
    int minIndex = 0;
    for (int i = 1; i < N; i++) {
        if (a[i] < a[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Обмен строк
void swapRows(double matrix[max_M][max_N], int row1, int row2, int N) {
    for (int j = 0; j < N; j++) {
        double temp = matrix[row1][j];
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = temp;
    }
}

int main() {
    int M, N;
    cout << "Введите количество строк (M): ";
    cin >> M;
    cout << "Введите количество столбцов (N): ";
    cin >> N;

    double matrix[max_M][max_N];

    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    // Гномья сортировка строк по f(a)
    int i = 1;
    while (i < M) {
        if (i == 0) {
            i++;
        }
        if (f(matrix[i - 1], N) <= f(matrix[i], N)) {
            i++;
        } else {
            swapRows(matrix, i - 1, i, N);
            i--;
        }
    }

    cout << "Матрица после сортировки" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
