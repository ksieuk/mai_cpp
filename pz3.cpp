#include <iostream>
using namespace std;

int get_number(char letter)
{
    if (isdigit(letter))
    {
        return int(letter) - 48;
    }
    return int(letter) - 55;
}

char get_letter(int number)
{
    if (number > 9)
    {
        return char(number + 55);
    }
    return char(number + 48);
}

int main()
{
    char letter;
    int number_input = 0, cc_input, cc_output = 0;

    cin >> cc_input;
    cin >> letter;
    cin >> letter;
    while (letter != ';')
    {
        number_input = number_input * cc_input + get_number(letter);
        cin >> letter;
    }

    cin >> cc_output;
    int number_power = 1;

    while ((cc_output * number_power) <= number_input)
    {

        number_power *= cc_output;
    }

    while (number_power != 0)
    {
        cout << get_letter(number_input / number_power);
        number_input %= number_power;
        number_power /= cc_output;
    }
}
