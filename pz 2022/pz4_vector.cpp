#include <iostream>

#include <vector>
#include <set>

#include <cstdlib>

using namespace std;


/*Практическое задание №4. STL.
 *
 *Задание 2. vector
 * Написать программу для работы с контейнером vector.
 *   Программа получает на вход количество элементов для двух векторов, разделенные пробелом.
 *   Вектора заполняются случайными элементами от -100 до 100 в соответствии с заданным размером.
 *   Необходимо вывести содержимое векторов, найти средние арифметические элементов каждого из векторов
 *     и пересекающиеся элементы.
 *
 *Пример
 *Входные данные
 * 6 8
 *Выходные данные
 * 10 13 -5 -8 50 40
 * -5 60 30 -20 15 -7 10 18
 * 16,66666666666667
 * 12,625
 * 10 -5
 */


void set_vector(vector<int> &vector_, int vectorSize) {
    for (int i = 0; i < vectorSize; i++) {
        vector_.insert(vector_.end(), rand() % 201 - 100);
    }
}


void print_vector(const vector<int> &vector_, int vectorSize) {
    for (int i = 0; i < vectorSize; i++) {
        cout << vector_[i] << " ";
    }
    cout << endl;
}


double get_vector_average(vector<int> &vector_, int vectorSize) {
    double sum = 0.0;
    for (int i = 0; i < vectorSize; i++) {
        sum += vector_[i];
    }
    return sum / vectorSize;
}

set<int> get_vectors_intersection(vector<int> &vector1, int vectorSize1, vector<int> &vector2, int vectorSize2) {
    set<int> vectorIntersected = {};
    for (int i = 0; i < vectorSize1; i++) {
        for (int j = 0; j < vectorSize2; j++) {
            if (vector1[i] == vector2[j]) {
                vectorIntersected.insert(vector1[i]);
            }
        }
    }
    return vectorIntersected;
}

void print_set(set<int> &set_) {
    for (int elem : set_)
        cout << ' ' << elem;
    cout << endl;
}


void get_vector_characteristic() {
    vector<int> v1, v2;
    int v1Size, v2Size;

    cout << "Enter the number of values for the two vectors:";
    cin >> v1Size >> v2Size;
    v1.reserve(v1Size);
    v2.reserve(v2Size);

    set_vector(v1, v1Size);
    set_vector(v2, v2Size);

    cout << "Initial vectors:" << endl;
    print_vector(v1, v1Size);
    print_vector(v2, v2Size);

    cout << "Average of the vectors:" << endl;
    cout << get_vector_average(v1, v1Size) << endl;
    cout << get_vector_average(v2, v2Size) << endl;

    set<int> vectorIntersected = get_vectors_intersection(v1, v1Size, v2, v2Size);

    cout << "Intersecting elements:";
    print_set(vectorIntersected);
}


int main() {
    get_vector_characteristic();
    return 0;
}