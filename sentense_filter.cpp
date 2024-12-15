#include "sentense_filter.h"

SentenceFilter::SentenceFilter() : source(""), isTextSource(false) {
    cout << "Вызван конструктор без параметров для класса SentenceFilter\n";
}

SentenceFilter::SentenceFilter(const string& filename)
    : source(filename), isTextSource(false) {
    cout << "Вызван конструктор с параметрами для класса SentenceFilter\n";
}

SentenceFilter::SentenceFilter(const string& text, bool isText)
    : source(text), isTextSource(isText) {
    cout << "Вызван конструктор с параметрами для класса SentenceFilter\n";
}

SentenceFilter::SentenceFilter(const SentenceFilter& other)
    : source(other.source), isTextSource(other.isTextSource) {
    cout << "Вызван конструктор копирования для класса SentenceFilter\n";
}

SentenceFilter::~SentenceFilter() {
    cout << "Вызван деструктор для класса SentenceFilter\n";
}

void SentenceFilter::result() const {
    string text;

    if (isTextSource) {
        text = source;
    } else {
        ifstream file(source);
        if (!file.is_open()) {
            cerr << "Не удалось открыть файл: " << source << endl;
            return;
        }
        ostringstream buffer;
        buffer << file.rdbuf();
        text = buffer.str();
        file.close();
    }

    cout << "Считанный текст:\n" << text << "\n\n";

    vector<string> sentences;
    split_into_sent(text, sentences);

    vector<string> startsWithOneLetter;
    vector<string> others;

    for (const auto& sentence : sentences) {
        if (starts_with_one_letter_word(sentence)) {
            startsWithOneLetter.push_back(sentence);
        } else {
            others.push_back(sentence);
        }
    }

    cout << "Предложения, начинающиеся с однобуквенных слов:\n";
    for (const auto& sentence : startsWithOneLetter) {
        cout << sentence << endl;
    }

    cout << "\nОстальные предложения:\n";
    for (const auto& sentence : others) {
        cout << sentence << endl;
    }
}

void SentenceFilter::split_into_sent(const string& text, vector<string>& sentences) const {
    ostringstream sentenceStream;
    for (char ch : text) {
        sentenceStream << ch;
        if (ch == '.' || ch == '!' || ch == '?') {
            sentences.push_back(sentenceStream.str());
            sentenceStream.str("");
            sentenceStream.clear();
        }
    }
    if (!sentenceStream.str().empty()) {
        sentences.push_back(sentenceStream.str());
    }
}

bool SentenceFilter::starts_with_one_letter_word(const string& sentence) const {
    istringstream ss(sentence);
    string word;
    if (ss >> word) {
        return word.length() == 1 && isalpha(word[0]);
    }
    return false;
}