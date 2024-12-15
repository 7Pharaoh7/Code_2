#include <iostream>
#include <limits>
#include <string>

using namespace std;

template <typename T>
T check_input() {
    T value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод! Пожалуйста, введите значение: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}