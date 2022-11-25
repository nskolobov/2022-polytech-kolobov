#include <iostream>
#include <cassert>


int gcd(int a, int b) {
    if (a < 0)
    {
        a *= -1;
    }
    if (b < 0)
    {
        b *= -1;
    }
    while (b > 0) {
        a %= b;
        int tmp = a;
        a = b;
        b = tmp;
    }
    return a;
}


int main()
{
    assert(gcd(0, 5) == 5); // test №1
    assert(gcd(9, 0) == 9); // test №2
    assert(gcd(48, 64) == 16); // test №3
    assert(gcd(-64, 48) == 16); // test №4
    assert(gcd(30, 18) == 6); // test №5
    assert(gcd(-30, -18) == 6); // test №6
    assert(gcd(270, 192) == 6); // test №7
    assert(gcd(342, 158) == 2); // test №8
    assert(gcd(0, 0) == 0); // test №9



    std::cout << "All tests passed!\n";

}
