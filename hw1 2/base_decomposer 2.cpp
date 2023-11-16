#include <iostream>
#include <string>
using namespace std;

int main() {
    int user_value;
    cin >> user_value;

    if (user_value == 0) {
        cout << "0";
        return 0;
    }

    string components = "";
    string user_digits = to_string(abs(user_value));

    for (char digit : user_digits) {
        if (digit != '0') {
            components += digit;
            components += string(user_digits.length() - (digit - '0'), '0');
        }
        if (digit != user_digits.back()) {
            components += " + ";
        }
    }

    if (user_value < 0) {
        cout << "-(" << components << ")";
    } else {
        cout << components;
    }

    return 0;
}