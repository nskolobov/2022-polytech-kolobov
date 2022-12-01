#include <iostream>
#include <cassert>

using namespace std;

int binary_search(int arr[], int l, int r, int x)
{
    while(r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[mid] > x)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

void test_binary_search()
{
    std::cout << "Test binary search" << std::endl;
    {
        const int n = 5;
        int arr[n] = {1, 2, 3, 4, 5};
        int x = 5;
        int result = binary_search(arr, 0, n - 1, x);
        assert(result == 4);
    }
    {
        const int n = 5;
        int arr[n] = {1, 2, 3, 4, 5};
        int x = 10;
        int result = binary_search(arr, 0, n - 1, x);
        assert(result == -1);
    }
    {
        const int n = 5;
        int arr[n] = {1, 1, 3, 4, 5};
        int x = 1;
        int result = binary_search(arr, 0, n - 1, x);
        assert(result == 0);
    }
    std::cout << "Tests passed" << std::endl;
}



int main()
{
    test_binary_search();
    return 0;
}
