#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "price.h"

using namespace std;

struct Node
{
    Node* next;
    Price* data;
};

class Container
{
private:
    Node* head;
    Node* tail;
    int count;

public:
    Container();
    Container(Node* h, Node* t, const int c);
    Container(const Container& other);
    ~Container();

    Node* get_head();
    Node* get_tail();

    void add_price(Price* Tr, int index);
    Container& delete_price(int index);
    Container& edit_price(int index);
    void display_prices();
    void sort_prices_by_shop();
    void search_price(const string shop);

    Container& operator[](int index);
};

