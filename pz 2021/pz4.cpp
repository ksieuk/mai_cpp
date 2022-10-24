#include <iostream>
#include <stack>

using namespace std;


bool is_correct_sequence(string &line) {
    stack<char> steck;
    for (char n: line) {
        switch (n) {
            case '{':
                steck.push('}');
                break;
            case '(':
                steck.push(')');
                break;
            case '[':
                steck.push(']');
                break;
            case ']':
            case '}':
            case ')':
                if (steck.empty() or steck.top() != n) {
                    return false;
                }
                steck.pop();
        default:
            break;
        }
    }
    return steck.empty();
}

int main() {
    string str;
    cin >> str;
    cout << (is_correct_sequence(str) ? "Correct" : "Incorrect");
}
