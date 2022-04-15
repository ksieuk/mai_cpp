#include <iostream>
#include <cstdlib>

using namespace std;

struct node_t {
    int data;
    node_t *next;
};


void push(node_t **head, int node_data) {
    auto *newNode = new node_t;
    newNode->data = node_data;
    newNode->next = (*head);
    (*head) = newNode;
};


void append(node_t **head, int node_data) {

    auto *newNode = new node_t;
    node_t *last = *head;

    newNode->data = node_data;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    while (last->next != nullptr)
        last = last->next;

    last->next = newNode;
}

void go_through(node_t *p) {
    if (p == nullptr) {
        cout << "NULL" << endl;
        return;
    }

    while (p != nullptr) {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

void get_element(node_t *p, int index) {
    while (index--) {
        if (p == nullptr) {
            cout << "NULL" << endl;
            return;
        }
        p = p->next;
    }
    cout << p->data << endl;
}

void append_random(node_t **head) {
    append(head, rand() % 100);
}

int main() {
    node_t *head = nullptr;

    go_through(head);
    append(&head, 1);
    append(&head, 2);
    push(&head, 3);
    push(&head, 4);
    append(&head, 5);
    append(&head, 6);
    append_random(&head);
    go_through(head);
    get_element(head, 4);
    get_element(head, 0);
    get_element(head, 1000);

    return 0;

}