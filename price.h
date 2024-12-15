#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Price {
    private:
        string name;
        string shop;
        float cost;
    public:
        Price();
        Price(const string& n, const string& s, const float& c);
        Price(const Price& other);
        ~Price();

        string get_name();
        void set_name(const string& n);

        string get_shop();
        void set_shop(const string& s);

        float get_cost();
        void set_cost(const float& c);

        void display_price();
        void edit_price();
};