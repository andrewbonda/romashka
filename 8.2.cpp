#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct Point {
    double x, y;
};

// Функция для вычисления угла
double Angle(const Point& p) {
    return atan2(p.y, p.x);
}

// Функция для вычисления расстояния до начала координат
double Distance(const Point& p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

// Метод пузырька для сортировки точек
void bubbleSort(vector<Point>& points) {
    int n = points.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            double angle1 = Angle(points[j]);
            double angle2 = Angle(points[j + 1]);
            if (angle1 > angle2 || (angle1 == angle2 & Distance(points[j]) > Distance(points[j + 1]))) {
                swap(points[j], points[j + 1]);
            }
        }
    }
}

int main() {
    int numPoints;

    // Запрашиваем количество точек
    cout << "Введите количество точек: ";
    cin >> numPoints;

    if (numPoints <= 0) {
        cerr << "Количество точек должно быть положительным числом!" << endl;
        return 1;
    }

    vector<Point> points(numPoints);

    // Запрашиваем координаты каждой точки
    cout << "Введите координаты точек (x y):" << endl;
    for (int i = 0; i < numPoints; ++i) {
        cout << "Точка " << i + 1 << ": ";
        cin >> points[i].x >> points[i].y;
    }

    // Сортируем точки методом пузырька
    bubbleSort(points);

    // Выводим отсортированные точки
    cout << "\nОтсортированные точки:\n";
    for (const auto& p : points) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}