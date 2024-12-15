#include "container.h"

Container::Container() : head(nullptr), tail(nullptr), count(0) {cout << "Вызван конструктор без параметров для класса Container\n";}

Container::Container(Node* h, Node* t, const int c) : head(h), tail(t), count(c) {
    cout << "Вызван конструктор с параметрами для класса Container\n";
}

Container::Container(const Container& other) : head(other.head), tail(other.tail), count(other.count) {
    cout << "Вызван конструктор копирования для класса Container\n";
}

Container::~Container() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
    }
    tail = nullptr;
    count = 0;
    cout << "Вызван деструктор для класса Container" << endl;
}


Node* Container::get_head() {
    return this->head;
}

Node* Container::get_tail() {
    return this->tail;
}

void Container::add_price(Price* Pr, int index) {
    if (index < 0 || index > count) {
        throw out_of_range("Index out of range");
    }
    
    Node* node_to_add = new Node;
    node_to_add->data = Pr;
    node_to_add->next = nullptr;

    if (index == 0) {
        node_to_add->next = head;
        head = node_to_add;
        if (count == 0) {
            tail = node_to_add;
        }
    } else {
        Node* prev = head;
        for (int i = 0; i < index - 1; ++i) {
            prev = prev->next;
        }
        node_to_add->next = prev->next;
        prev->next = node_to_add;
        
        if (node_to_add->next == nullptr) {
            tail = node_to_add;
        }
    }
    
    ++count;
}

Container& Container::delete_price(int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }

    Node* temp = head;

    if (index == 0) {
        head = head->next;
        delete temp->data;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
    } else {
        Node* prev = nullptr;
        for (int i = 0; i < index; ++i) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        if (temp == tail) {
            tail = prev;
        }
        delete temp->data;
        delete temp;
    }

    --count;
    return *this;
}

void Container::display_prices() {
    Node* temp = head;
    if (count == 0) {
        cout << "Цен нет" << endl;
        return;
    }
    int index = 1;
    while (temp != 0) {
        cout << index << " - Информация о цене:\n";
        temp->data->display_price();
        temp = temp->next;
        index++;
    }
}

void Container::sort_prices_by_shop() {
    if (count < 2) return;

    for (Node* i = head; i != nullptr; i = i->next) {
        for (Node* j = head; j->next != nullptr; j = j->next) {
            if (j->data->get_shop() > j->next->data->get_shop()) {
                Price* temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}

void Container::search_price(const string shop) {

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data->get_shop() == shop) {
            temp->data->display_price();
            return;
        }
        temp = temp->next;
    }
    cout << "Цена с магазином " << shop << " не найдена." << endl;
}

Container& Container::edit_price(int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }

    Node* temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }

    temp->data->edit_price();
    return *this;
}

Container& Container::operator[](int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }

    Node* temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }

    return *this;
}