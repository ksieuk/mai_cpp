#include <iostream>

#include <map>

#include <vector>
#include <cstdlib>


using namespace std;

/*Практическое задание №4.
 *
 *Задание 1. map
 * Написать программу для работы с контейнером map.
 *   Программа получает на вход строку которая состоит из слов, разделенных пробелом.
 *   Необходимо подсчитать количество раз, которое встречается каждое из строк во входной строке.
 *
 *Задание 2. vector
 * Написать программу для работы с контейнером vector.
 *   Программа получает на вход количество элементов для двух векторов, разделенные пробелом.
 *   Вектора заполняются случайными элементами от -100 до 100 в соответствии с заданным размером.
 *   Необходимо вывести содержимое векторов, найти средние арифметические элементов каждого из векторов
 *   и пересекающиеся элементы.
 *Пример
 * Входные данные
 * 6 8
 * Выходные данные
 * 10 13 -5 -8 50 40
 * -5 60 30 -20 15 -7 10 18
 * 16,66666666666667
 * 12,625
 * 10 -5
 *Задание 3. stack
 * Построить матрицу достижимости для графа. На вход подаётся N - количество вершин графа.
 *   После этого на вход подаются связи для каждой вершины. 0 означает отсутствие связей.
 *   С помощью алгоритма обхода в ширину или в глубину от каждой вершины построить матрицу достижимости для графа.
*/


void print_repeated_words_number() {
    string line;
    getline(cin, line);
    line = line + ' ';

    map<string, int> myMap;

    string word;
    for (char& letter: line) {
        if (letter == ' ') {
            myMap[word]++;
            word = "";
            continue;
        }
        word += letter;
    }

    for (const auto& elem : myMap)
    {
        std::cout << elem.first << " " << elem.second << "\n";
    }
}


void get_vector_characteristic() {
    vector <int> v1,v2;
    int a, b;
    cout << "Enter the number of values for the two vectors: ";
    cin >> a >> b;
    v1.reserve(a);
    v2.reserve(b);
//    srand(time(NULL));
    for (int j = 0; j < a; ++j) {
        v1.insert(v1.end(), rand()%200 -100);
    }
    for (int j = 0; j < b; ++j) {
        v2.insert(v2.end(), rand()%200 -100);
    }

    for (int i = 0; i < a; i++) {
        cout << v1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < b; i++) {
        cout << v2[i] << " ";
    }
    cout << endl;
}


int main() {
//    print_repeated_words_number();
    get_vector_characteristic();
    return 0;
}