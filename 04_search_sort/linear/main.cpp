#include <iostream>
#include <cassert>

using namespace std;

int linear_search(int arr[], int n, int x, int result[])
{
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == x)
        {
            result[count] = i;
            ++count;
        }
    }
    return count;
}

void test_linear_search()
{
    std::cout << "Test linear search" << std::endl;
    {
        const int n = 5;
        int arr[n] = {1, 2, 3, 4, 5};
        int x = 10;
        int result[n];
        int count = linear_search(arr, n, x, result);
        assert(count == 0);
    }
    {
        const int n = 5;
        int arr[n] = {1, 2, 3, 4, 5};
        int x = 1;
        int result[n];
        int count = linear_search(arr, n, x, result);
        assert(count == 1);
        assert(result[0] == 0);
    }
    {
        const int n = 5;
        int arr[n] = {1, 1, 1, 1, 1};
        int x = 1;
        int result[n];
        int count = linear_search(arr, n, x, result);
        assert(count == 5);
        assert(result[0] == 0);
        assert(result[1] == 1);
        assert(result[2] == 2);
        assert(result[3] == 3);
        assert(result[4] == 4);
    }
    {
        const int n = 5;
        int arr[n] = {1, 2, 3, 4, 1};
        int x = 1;
        int result[n];
        int count = linear_search(arr, n, x, result);
        assert(count == 2);
        assert(result[0] == 0);
        assert(result[1] == 4);
    }
    std::cout << "Tests passed" << std::endl;

}


int main()
{
    test_linear_search();
    return 0;
}
