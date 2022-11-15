#include <iostream>
#include <map>

using namespace std;


/*Практическое задание №4. STL.
 *
 *Задание 1. map
 * Написать программу для работы с контейнером map.
 *   Программа получает на вход строку которая состоит из слов, разделенных пробелом.
 *   Необходимо подсчитать количество раз, которое встречается каждое из строк во входной строке.
*/


void print_repeated_words_number() {
    string line;
    getline(cin, line);
    line = line + ' ';

    map<string, int> myMap;

    string word;
    for (char &letter: line) {
        if (letter == ' ') {
            myMap[word]++;
            word = "";
            continue;
        }
        word += letter;
    }

    for (const auto &elem: myMap) {
        std::cout << elem.first << " " << elem.second << "\n";
    }
}


int main() {
    print_repeated_words_number();
    return 0;
}