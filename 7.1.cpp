#include <iostream>  
#include <string>     
#include <vector>     

using namespace std;


struct Book {
    string title;  
    string author; 
    int price;      
};

void BookInfo(const Book& book) {
    cout << "Название: " << book.title << endl;
    cout << "Автор: " << book.author << endl;
    cout << "Цена: " << book.price << " руб." << endl;
    cout << "------------------------------" << endl;
}

int main() {
    vector<Book> books = {
        {"Три товарища", "Эрих Мария Ремарк", 450},
        {"1984", "Джордж Оруэлл", 600},
        {"Старик и море", "Эрнест Хемингуэй", 300},
        {"Унесённые ветром", "Маргарет Митчелл", 700},
        {"Портрет Дориана Грея", "Оскар Уайльд", 550}
    };

    int threshold_price;

    cout << "Введите пороговую цену: ";
    cin >> threshold_price;

    cout << "\nКниги с ценой выше " << threshold_price << " рублей:\n\n";

    for (const Book& book : books) {
        if (book.price > threshold_price) {
            BookInfo(book);
        }
    }

    return 0;
}
