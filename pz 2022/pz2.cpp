#include <iostream>
using namespace std;

/*Практическое задание №2.
 *
 *Задание 1.
 * Реализовать исключение в классе предыдущего задания: std:bad_alloc ошибка выделения памяти
 *   (если используются функции Си), std:out_of_range ошибка при обращении по индексу,
 *   std:invalid_argument при попытке передать значение вне промежутка -100..100.
 *
 *Задание 2.
 * Реализовать шаблонный класс для массива элементов задаваемого типа. Реализовать отдельный сеттер
 *   с проверкой данных для массивов, хранящих целочисленные значения.
 *
 *Задание 3.
 * Реализовать операцию “=”. Реализовать операцию вывода “<<”. (см. дружественные функции)
 *
 *Задание 4.
 * Реализовать операцию нахождения расстояния между массивами через расстояние между векторами.
 *   Только для массива с элементами int, для остальных типов данных возвращать ошибку std::bad_typeid
 */


class Array {
private:
    int *head;
    int sizeOfArray;
public:
    Array() {
        sizeOfArray = 0;
        head = new int[sizeOfArray];
    }

    explicit Array(int sizeOfArray) {
        this->sizeOfArray = sizeOfArray;
        head = new int[sizeOfArray];
        for (int i = 0; i < this->sizeOfArray; i++) {
            head[i] = 0;
        }
    }

    Array(const Array &other) {
        sizeOfArray = other.sizeOfArray;
        head = new int[sizeOfArray];
        for (int i = 0; i < sizeOfArray; i++) {
            head[i] = other.head[i];
        }
    }

    ~Array() {
        delete[] head;
        sizeOfArray = 0;
        head = nullptr;
        cout << "Array with head="<< &head <<" successfully cleared" << endl;
    }

    Array operator +(const Array &other) {
        int minSize = min(sizeOfArray, other.sizeOfArray);

        Array sumArray(minSize);
        for(int i = 0; i < minSize; i++){
            sumArray.head[i] = head[i] + other.head[i];
        }
        return sumArray;
    }

    Array operator -(const Array &other) {
        int minSize = min(sizeOfArray, other.sizeOfArray);

        Array sumArray(minSize);
        for(int i = 0; i < minSize; i++){
            sumArray.head[i] = head[i] - other.head[i];
        }
        return sumArray;
    }

    bool isCorrectIndex(int index) const {
        if (0 <= index && index <= sizeOfArray) {
            return true;
        } else {
            return false;
        }
    }

    static bool isCorrectValue(int value) {
        if (-100 <= value && value <= 100) {
            return true;
        } else {
            return false;
        }
    }

    void Set(int index, int value) {
        if (!isCorrectValue(value)) throw invalid_argument("Invalid argument: Value must be between [-100, 100]");
        if (!isCorrectIndex(index)) throw out_of_range("Out of range: Array out of bounds");
        head[index] = value;
    }

    int Get(int index) {
        if (isCorrectIndex(index)) {
            return head[index];
        } else {
            throw out_of_range("Out of range: Array out of bounds");
        }
    }

    void printValues() {
        for (int i = 0; i != sizeOfArray; i++) {
            cout << head[i] << " ";
        }
        cout << "\n";
    }

    void pushBack(int value) {
        if (!isCorrectValue(value)) throw invalid_argument("Invalid argument: Value must be between [-100, 100]");
        int *newArray = new int[sizeOfArray + 1];
        for (int i = 0; i < sizeOfArray; i++) {
            newArray[i] = head[i];
        }
        newArray[sizeOfArray] = value;
        delete[] head;
        head = newArray;
        sizeOfArray++;
    }
};

int main() {
    Array a(5);
    Array b(5);
    for(int i = 0; i < 5; i++){
        a.Set(i, i + 1);
        b.Set(i, (i + 1) * 2);
    }
    cout << "Array a: ";
    a.printValues();
    cout << "Array b: ";
    b.printValues();

    cout << "Array b: value with index=1 is " << b.Get(1) << endl;

    Array c = a + b;
    cout << "a + b: ";
    c.printValues();

    cout << "b - a: ";
    Array d = b - a;
    d.printValues();

    cout << "copy and push 99: ";
    Array g(d);
    g.pushBack(99);
    g.printValues();

    cout << endl;

    Array vicious (5);
    try {
        for (int i = 0; i < 5; i++) {
            vicious.Set(i, i + 99);
        }
    } catch (std::invalid_argument& e) {
        cout << e.what() << endl;
    }
    cout << "Array a: ";
    vicious.printValues();

    for (int i = 0; i < 5; i++) {
        vicious.Set(i, i + 50);
    }
    Array temp(vicious);

    cout << "Array a: ";
    vicious.printValues();
    cout << "Array b: ";
    temp.printValues();

    Array sumError = vicious + temp;
    cout << "Array a + b: ";
    sumError.printValues();

    cout << endl;

    return 0;
}