#include <iostream>
using namespace std;


void swap(int *x, int *y);


class MaxHeap
{
    int *p;
    int capacity;
    int size;
public:
    explicit MaxHeap(int capacity);
    void MaxHeapify(int i);
    static int parent(int i) { return (i-1)/2; }
    static int left(int i) { return (2*i + 1); }
    static int right(int i) { return (2*i + 2); }
    int extractMax();
    void insertKey(int k);
    int FindElement(int value);
};

MaxHeap::MaxHeap(int cap)
{
    size = 0;
    capacity = cap;
    p = new int[cap];
}

void MaxHeap::insertKey(int k)
{
    if (size == capacity)
    {
        cout << "[OVERFLOW ERROR]" << endl;
        return;
    }

    size++;
    int i = size - 1;
    p[i] = k;

    while (i != 0 && p[parent(i)] < p[i])
    {
        swap(&p[i], &p[parent(i)]);
        i = parent(i);
    }
}

int MaxHeap::extractMax()
{
    if (size <= 0)
        return 0;
    if (size == 1)
    {
        size--;
        return p[0];
    }

    int root = p[0];
    p[0] = p[size-1];
    size--;
    MaxHeapify(0);

    return root;
}

int MaxHeap::FindElement(int value) {
    for (int i = 0; i < size; i++) {
        if (p[i] == value) {
            return 1;
        }
    }
    return 0;
}

void MaxHeap::MaxHeapify(int i)
{
    int left_parent = left(i);
    int right_parent = right(i);
    int smallest = i;
    if (left_parent < size && p[left_parent] < p[i])
        smallest = left_parent;
    if (right_parent < size && p[right_parent] < p[smallest])
        smallest = right_parent;
    if (smallest != i)
    {
        swap(&p[i], &p[smallest]);
        MaxHeapify(smallest);
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


int main() {
    int command_number, number, n;
    string input;
    while (cin.peek() != '\n') {
        cin >> input;
    }
    n = stoi(input);
    input = "";
    MaxHeap h(n);

    while (n--) {
        cin >> command_number;
        while (cin.peek() != '\n') {
            cin >> input;
        }
        number = stoi(input);
        string res;
        switch (command_number) {
            case 0:
                h.insertKey(number);
                break;
            case 1:
                cout << h.extractMax() << endl;
                break;
            case 2:
                res = h.FindElement(number) ? "YES" : "NO";
                cout << res << endl;
                break;
            default:
                cout << "Unknown command" << endl;
                break;
        }
    }
    return 1;
}