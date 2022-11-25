#include "calculator.h"

double calculator(double number_left, double number_right, char operation) {
    char plus = '+';
    char minus = '-';
    char multiply = '*';
    char divide = '/';
    char pow = '^';
    double result = 0;
    if (operation == plus)
    {
        result = number_left + number_right;
    }
    else if (operation == minus)
    {
        result = number_left - number_right;
    }
    else if (operation == multiply)
    {
        result = number_left * number_right;
    }
    else if (operation == divide)
    {
            result = number_left / number_right;
    }
    else if (operation == pow)
    {
        result = 1;
        for (int n = 1; n <= number_right; n++)
        {
            result *= number_left;
        }
    }
    return result;
}
