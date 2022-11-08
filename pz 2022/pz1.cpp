#include <iostream>
using namespace std;

/*Практическое задание №1
 *Задание 1.
 * Создать класс для работы с динамическим массивом типа int, хранить в свойствах указатель на данные и размер массива,
 *   реализовать функцию вывода всех значений массива, конструктор, получающий на вход размер массива, и деструктор.
 * Реализовать сеттер, проверяющий входящее значение на принадлежность к промежутку от -100 до 100 включительно и
 *   проверяющий выход за границы массива, и геттер, проверяющий выход за границы массива.
 *
 *Задание 2.
 * Реализовать конструктор копирования.
 *
 *Задание 3.
 * Реализовать операцию добавления значения в конец массива с расширением его размера.
 *   Проверять добавляемое значение на принадлежность к промежутку -100 100.
 *
 *Задание 4.
 * Реализовать операцию сложения и вычитания для массивов(сложение и вычитание всех элементов).
 */


class Array {
private:
    int *arr;
    int sizeOfArray;
public:
    Array() {
        sizeOfArray = 0;
        arr = new int[sizeOfArray];
    }

    Array(int sizeOfArray) {
        this->sizeOfArray = sizeOfArray;
        arr = new int[sizeOfArray];
        for (int i = 0; i < this->sizeOfArray; i++) {
            arr[i] = 0;
        }
    }

    Array(const Array &other) {
        sizeOfArray = other.sizeOfArray;
        arr = new int[sizeOfArray];
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

    Array operator +(const Array &other) {
        int minSize = min(sizeOfArray, other.sizeOfArray);

        Array sumArray(minSize);
        for(int i = 0; i < minSize; i++){
            sumArray.arr[i] = arr[i] + other.arr[i];
        }
        return sumArray;
    }

    Array operator -(const Array &other) {
        int minSize = min(sizeOfArray, other.sizeOfArray);

        Array sumArray(minSize);
        for(int i = 0; i < minSize; i++){
            sumArray.arr[i] = arr[i] - other.arr[i];
        }
        return sumArray;
    }

    inline bool isCorrectIndex(int index) const {
        if (0 <= index && index <= sizeOfArray) {
            return true;
        }
        return false;
    }

    inline static bool isCorrectValue(int value) {
        if (-100 <= value && value <= 100) {
            return true;
        }
        return false;
    }

    void Set(int index, int value) {
        if (!isCorrectValue(value)) throw invalid_argument("Invalid argument: Value must be between [-100, 100]");
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

    void pushBack(int value) {
        if (!isCorrectValue(value)) throw invalid_argument("Invalid argument: Value must be between [-100, 100]");
        int *newArray = new int[sizeOfArray + 1];
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
    Array a(5);
    Array b(5);
    for(int i = 0; i < 5; i++) {
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