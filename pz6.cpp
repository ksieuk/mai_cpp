#include <iostream>
#include <cstdlib>
using namespace std;


void BubbleSort(int *arr, int size){
    int temp;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void CocktailSort(int arr[], int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped)
    {
        swapped = false;

        for (int i = start; i < end; ++i)
        {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i)
        {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        ++start;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    uint16_t size = 0;
    int elem;

    cout << "Size array: ";
    cin >> size;
    int A[size];

    for (int k = 0; k < size; k++)
    {
        elem = rand();
        A[k] = elem; // запись значений по убыванию
        cout << A[k]  << " | ";
    }

    CocktailSort(A, size); // сортировка

    cout << "\nArray sorted:\n";
    for (int k = 0; k < size; k++)
    {
        cout << A[k] << " | ";
    }
    cout << endl;
    return 0;
}