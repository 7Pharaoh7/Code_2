#include "container.h"
#include "price.h"
#include "check.cpp"
#include "sentense_filter.h"

void display_menu() {
    cout << "\n===== Меню управления поездами =====" << endl;
    cout << "1. Добавить цену" << endl;
    cout << "2. Удалить цену" << endl;
    cout << "3. Редактировать цену" << endl;
    cout << "4. Показать все цены" << endl;
    cout << "5. Сортировать поезда по названию магазина" << endl;
    cout << "6. Найти поезд по названию магазина" << endl;
    cout << "0. Выйти" << endl;
    cout << "Введите ваш выбор: ";
}

int Prices_program() {
    Container Prices;
    int choice;

    while (true) {
        display_menu();
        choice = check_input<int>();

        switch (choice) {
            case 1: {
                string name, shop;
                float cost;
                cout << "Введите название: ";
                getline(cin, name);
                cout << "Введите название магазина: ";
                getline(cin, shop);
                cout << "Введите цену в рублях: ";
                cost = check_input<float>();
                cout << "Введите индекс, куда вставить объект: ";
                int index = check_input<int>();

                Price* new_Price = new Price(name, shop, cost);
                try {
                    Prices.add_price(new_Price, index - 1);
                    cout << "Объект добавлен." << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                    delete new_Price;
                }
                break;
            }
            case 2: {
                int index;
                cout << "Введите индекс удаляемого объекта: ";
                index = check_input<int>();
                try {
                    Prices.delete_price(index - 1);
                    cout << "Поезд удален." << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 3: {
                int index;
                cout << "Введите индекс редактируемого объекта: ";
                index = check_input<int>();
                try {
                    Prices.edit_price(index - 1);
                    cout << "Объект отредактирован." << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 4: {
                Prices.display_prices();
                break;
            }
            case 5: {
                Prices.sort_prices_by_shop();
                cout << "Цены отсортированы по названиям магазина." << endl;
                Prices.display_prices();
                break;
            }
            case 6: {
                cout << "Введите название магазина для поиска: ";
                string temp;
                getline(cin, temp);
                Prices.search_price(temp);
                break;
            }
            case 0: {
                cout << "Выход из программы." << endl;
                return 0;
            }
            default: {
                cout << "Неверный выбор! Попробуйте снова." << endl;
                break;
            }
        }
    }

    return 0;
}

int words_program() {
    try {
        int choice;
        cout << "Выберите источник (1 - строка, 2 - файл): ";
        if (!(cin >> choice)) {
            throw invalid_argument("Ошибка: некорректный ввод выбора источника.");
        }

        if (choice == 1) {
            cin.ignore();
            string text;
            cout << "Введите текст: ";
            getline(cin, text);

            if (text.length() > 8192) {
                throw overflow_error("Ошибка: превышена максимальная длина текста.");
            }

            SentenceFilter filter(text, true);
            filter.result();
        } else if (choice == 2) {
            string filename;
            cout << "Введите имя файла: ";
            cin >> filename;
            ifstream file(filename);
            if (!file) {
                throw runtime_error("Ошибка: файл не найден или не может быть открыт.");
            }
            file.close();
            SentenceFilter filter(filename, false);
            filter.result();
        } else {
            throw out_of_range("Ошибка: выбран несуществующий источник.");
        }
    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        return 1;
    }
    catch (const overflow_error& e) {
        cerr << e.what() << endl;
        return 2;
    }
    catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return 3;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
        return 4;
    }
    catch (...) {
        cerr << "Произошла неизвестная ошибка." << endl;
        return -1;
    }
    return 0;
}




int main() {
    int choice;
    while (true) {
        cout << "Выберите тип задания:" << endl;
        cout << "1 - Стандартные потоки" << endl;
        cout << "2 - Файловые и строковые потоки" << endl;
        cout << "3 - Выход" << endl;
        choice = check_input<int>();

        switch (choice) {
            case 1:
                Prices_program();
                break;
            case 2:
                words_program();
                break;
            case 3:
                cout << "Завершение работы." << endl;
                return 0;
            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
                break;
        }
    }
}





