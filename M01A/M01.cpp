//
// Created by Microzenas on 1/24/23.
//
#include <iostream>

using namespace std;

int main() {
    double number1, number2, result = 0;
    char op;

    cin >> op >> number1 >> number2;

    if (op == '+') {
        result = number1 + number2;
    }else if(op == '-'){
        result = number1 - number2;
    }else if(op == '*'){
        result = number1 * number2;
    }else if(op == '/'){
        if (number2 == 0) {
            cout << "The dividend cannot be 0." << endl;
            return 0;
        }
        result = number1 / number2;
    }else{
        cout << "Wrong operator." << endl;
    }
    cout << "= " << result << endl;
    return 0;
}
