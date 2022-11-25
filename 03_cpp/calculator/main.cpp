#include <iostream>

#include "calculator.h"

int main()
{
    double number_left, number_right;
    char operation;
    while(true) {
        std::cout << "Enter number_left:";
        std::cin >> number_left;
        std::cout << "Enter deistvie:";
        std::cin >> operation;
        std::cout << "Enter number_right:";
        std::cin >> number_right;
        double result = calculator(number_left, number_right, operation);
        std::cout << "Result is: " << result << '\n';
        std::cout << "if you want to continue, press 1, if you want to finish press 0:";
        bool check_finish;
        std::cin >> check_finish;
        if (!check_finish)
        {
            return 0;
        }
    }
}
