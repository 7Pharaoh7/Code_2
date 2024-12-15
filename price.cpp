#include "price.h"

Price::Price() : name(""), shop(""), cost(0) {cout << "Вызван конструктор без параметров для класса Price\n";}

Price::Price(const string& n, const string& s, const float& c) : name(n), shop(s), cost(c) {
    cout << "Вызван конструктор с параметрами для класса Price\n";
}

Price::Price(const Price& other) : name(other.name), shop(other.shop), cost(other.cost) {
    cout << "Вызван конструктор копирования для класса Price\n";
}

Price::~Price() {cout << "Вызван деструктор для класса Price\n";}

string Price::get_name() {
    return this->name;
}

void Price::set_name(const string& n) {
    this->name = n;
}

string Price::get_shop() {
    return this->shop;
}

void Price::set_shop(const string& s) {
    this->shop = s;
}

float Price::get_cost() {
    return this->cost;
}

void Price::set_cost(const float& c) {
    this->cost = c;
}

void Price::display_price() {
    cout << "Название товара: " << this->get_name() << endl;
    cout << "Название магазина " << this->get_shop() << endl;
    cout << "Стоимость товара: " << this->get_cost() << endl; 
    cout << endl;
}

void Price::edit_price() {
    int choice;
    cout << "Выберите, что хотите изменить:\n";
    cout << "1. Название товара\n";
    cout << "2. Название магазина\n";
    cout << "3. Стоимость товара\n";
    cout << "Введите ваш выбор: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            string new_name;
            cout << "Введите новое название товара: ";
            getline(cin, new_name);
            set_name(new_name);
            break;
        }
        case 2: {
            string new_shop;
            cout << "Введите новое название магазина: ";
            getline(cin, new_shop);
            set_shop(new_shop);
            break;
        }
        case 3: {
            float new_cost;
            cout << "Введите новую стоимость: ";
            cin >> new_cost;
            set_cost(new_cost);
            break;
        }
        default:
            cout << "Неверный выбор!" << endl;
    }
}
