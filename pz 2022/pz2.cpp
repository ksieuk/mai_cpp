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


template <typename T>
class Array {
private:
    T *arr;
    int sizeOfArray;
public:
    Array() {
        sizeOfArray = 0;
        arr = new T[sizeOfArray];
    }

    Array(int sizeOfArray) {
        this->sizeOfArray = sizeOfArray;
        arr = new T[sizeOfArray];
        for (int i = 0; i < this->sizeOfArray; i++) {
            arr[i] = 0;
        }
    }

    Array(const Array &other) {
        sizeOfArray = other.sizeOfArray;
        arr = new T[sizeOfArray];
//        for (int i = 0; i < sizeOfArray; i++) {
//            arr[i] = other.arr[i];  // memcpy
//        }
        memcpy(arr, other.arr, sizeof *other.arr * other.sizeOfArray);
    }

    ~Array() {
        delete[] arr;
        sizeOfArray = 0;
        arr = nullptr;
        cout << "Array with head="<< &arr <<" successfully cleared" << endl;
    }

    Array<T> operator +(const Array &other) {
        T minSize = min(sizeOfArray, other.sizeOfArray);

        Array sumArray(minSize);
        for(int i = 0; i < minSize; i++){
            sumArray.arr[i] = arr[i] + other.arr[i];
        }
        return sumArray;
    }

    Array<T> operator -(const Array &other) {
        int minSize = min(sizeOfArray, other.sizeOfArray);

        Array sumArray(minSize);
        for(int i = 0; i < minSize; i++){
            sumArray.arr[i] = arr[i] - other.arr[i];
        }
        return sumArray;
    }

    Array<T> operator =(const Array &other) {
        this -> sizeOfArray = other.sizeOfArray;
        for (int i = 0; i < sizeOfArray; i++) {
            this -> arr[i] = other.arr[i];
        }
        return *this;
    }

    friend ostream& operator<<(ostream &os, const Array<T> &array_) {
        for (int i = 0; i < array_.sizeOfArray; i++) {
            os << array_.arr[i] << " ";
        }
        return os << endl;
    }

    inline bool isCorrectIndex(int index) const {
        if (0 <= index && index <= sizeOfArray) {
            return true;
        }
        return false;
    }

    inline static bool isCorrectValue(T value) {
        const type_info& valueType = typeid(value);
        const type_info& arrType = typeid(T);
        if (valueType == arrType && (-100 <= value && value <= 100)) {
            return true;
        }
//        if (-100 <= value && value <= 100) {
//            return true;
//        }
        return false;
    }

    void Set(int index, T value) {
        if (!isCorrectValue(value)) throw invalid_argument("Invalid argument: Value must be of the same type and between [-100, 100]");
        if (!isCorrectIndex(index)) throw out_of_range("Out of range: Array out of bounds");

        arr[index] = value;
    }

    int Get(int index) {
        if (!isCorrectIndex(index)) throw out_of_range("Out of range: Array out of bounds");

        return arr[index];
    }

    void printValues() {
        for (int i = 0; i != sizeOfArray; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    void pushBack(T value) {
        if (!isCorrectValue(value)) throw invalid_argument("Invalid argument: Value must be of the same type and between [-100, 100]");
        T *newArray = new T[sizeOfArray + 1];
        for (int i = 0; i < sizeOfArray; i++) {
            newArray[i] = arr[i];
        }
        newArray[sizeOfArray] = value;
        delete[] arr;
        arr = newArray;
        sizeOfArray++;
    }
};

int main() {
    Array<long int> a(5);
    Array<long int> b(5);
    for(int i = 0; i < 5; i++) {
        a.Set(i, i + 1);
        b.Set(i, (i + 1) * 2);
    }
    cout << "Array a: ";
    a.printValues();
    cout << "Array b: ";
    b.printValues();

    cout << "Array b: value with index=1 is " << b.Get(1) << endl;

    Array<long int> c = a + b;
    cout << "a + b: ";
    c.printValues();

    cout << "b - a: ";
    Array<long int> d = b - a;
    d.printValues();

    cout << "copy and push 99: ";
    Array<long int> g(d);
    g.pushBack(99);
    g.printValues();

    cout << endl;

    Array<int> vicious (5);
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
    Array<int> temp(vicious);

    cout << "Array a: ";
    vicious.printValues();
    cout << "Array b: ";
    temp.printValues();

    Array<int> sumError = vicious + temp;
    cout << "Array a + b: ";
    sumError.printValues();

    cout << endl;

    return 0;
}