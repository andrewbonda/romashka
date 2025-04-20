#include <iostream>   // Для ввода-вывода
#include <string>     // Для работы со строками
#include <vector>     // Для использования вектора

using namespace std;

// Определяем структуру PRICE
struct PRICE {
    string TOVAR;  // Название товара
    string MAG;    // Название магазина
    double STOIM;  // Стоимость товара в руб.
};

int main() {
    const int SIZE = 8;             // Количество элементов в массиве
    PRICE SPISOK[SIZE];             // Массив из 8 элементов типа PRICE

    // Ввод данных с клавиатуры
    cout << "Введите данные о 8 товарах:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "\nТовар #" << i + 1 << ":\n";

        cout << "Название товара: ";
        getline(cin, SPISOK[i].TOVAR);  // Ввод названия товара

        cout << "Название магазина: ";
        getline(cin, SPISOK[i].MAG);    // Ввод названия магазина

        cout << "Стоимость товара (в рублях): ";
        cin >> SPISOK[i].STOIM;         // Ввод стоимости

        cin.ignore();  // Очищаем буфер после ввода числа
    }

    // Запрос названия товара для поиска
    string search_name;
    cout << "\nВведите название товара для поиска: ";
    getline(cin, search_name);

    // Поиск товара в массиве
    bool found = false;
    for (int i = 0; i < SIZE; i++) {
        if (SPISOK[i].TOVAR == search_name) {
            // Если товар найден — выводим информацию
            cout << "\nТовар найден:\n";
            cout << "Название товара: " << SPISOK[i].TOVAR << endl;
            cout << "Магазин: " << SPISOK[i].MAG << endl;
            cout << "Стоимость: " << SPISOK[i].STOIM << " руб." << endl;
            cout << "------------------------------\n";
            found = true;
        }
    }

    // Если товар не найден — выводим сообщение
    if (!found) {
        cout << "\nТовар с названием \"" << search_name << "\" не найден.\n";
    }

    return 0;
}
