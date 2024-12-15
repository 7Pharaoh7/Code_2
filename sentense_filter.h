#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class SentenceFilter {
private:
    string source;
    bool isTextSource;

    void split_into_sent(const string& text, vector<string>& sentences) const;
    bool starts_with_one_letter_word(const string& sentence) const;

public:
    SentenceFilter();
    SentenceFilter(const string& filename);
    SentenceFilter(const string& text, bool isText);
    SentenceFilter(const SentenceFilter& other);
    ~SentenceFilter();
    void result() const;
};