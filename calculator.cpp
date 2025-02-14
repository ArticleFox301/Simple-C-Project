#include <iostream>

using namespace std;

void calcultor(char op, double num1, double num2, double result){
    switch(op){
        case '+':
            result = num1 + num2;
            cout << "Result: " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "Result: " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;
        case '/':
            result = num1 / num2;
            cout << "Result: " << result << endl;
            break;
        default: 
            cout<< "Input Error!!!"<< endl;
            break;
    }
}

int main(){
    char op;

    double num1;
    double num2;
    double result;

    cout << "********** CALCULATOR **********\n";
    cout << "Enter operators (+ - * /): ";
    cin >> op;
    cout << "Enter number #1: ";
    cin >> num1;
    cout << "Enter number #2: ";
    cin >> num2;
    
    calcultor(op, num1, num2, result);

    cout << "********************************";
    return 0;
}