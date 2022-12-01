#include <iostream>
#include <cassert>



void insert(int*& arr, int& n, int p, int x) {
    int* tmp_arr = new int[n + 1];
    for (int i = 0; i < p; ++i) {
        tmp_arr[i] = arr[i];
    }
    tmp_arr[p] = x;
    for (int i = p + 1; i < n + 1; ++i) {
        tmp_arr[i] = arr[i - 1];
    }
    ++n;
    delete[] arr;
    arr = tmp_arr;
}

void test_insert()
{
    std::cout << "Test insert" << std::endl;
    {
        int n = 3;
        int* arr = new int[n] {1, 5, 8};
        int x = 4;
        int p = 1;
        insert(arr, n, p, x);
        assert(arr[0] == 1);
        assert(arr[1] == 4);
        assert(arr[2] == 5);
        assert(arr[3] == 8);
        delete[] arr;
    }
    {
        int n = 4;
        int* arr = new int[n] {1, 3, 5, 6};
        int x = 0;
        int p = 0;
        insert(arr, n, p, x);
        assert(arr[p] == x);
        assert(arr[0] == 0);
        assert(arr[1] == 1);
        assert(arr[2] == 3);
        assert(arr[3] == 5);
        assert(arr[4] == 6);
        delete[] arr;
    }
    std::cout << "Tests passed" << std::endl;
}

int search_position(int* arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] >= x) {
            return i;
        }
    }
    return n;
}

void test_search_position()
{
    std::cout << "Test search position" << std::endl;
    {
        int n = 4;
        int* arr = new int[n] {1, 3, 5, 6};
        int x = 5;
        int p = search_position(arr, n, x);
        assert(p == 2);
        delete[] arr;
    }
    {
        int n = 5;
        int* arr = new int[n] {1, 2, 3, 5, 6};
        int x = 0;
        int p = search_position(arr, n, x);
        assert(p == 0);
        delete[] arr;
    }
    {
        int n = 5;
        int* arr = new int[n] {1, 2, 3, 5, 6};
        int x = 7;
        int p = search_position(arr, n, x);
        assert(p == 5);
        delete[] arr;
    }

    std::cout << "Tests passed" << std::endl;
}

void insert_sorted(int*& arr, int& n, int x)
{
    int p = search_position(arr, n, x);
    insert(arr, n, p, x);
}

void test_insert_sorted()
{
    std::cout << "Test insert sorted" << std::endl;
    {
        int n = 4;
        int* arr = new int[n] {1, 3, 5, 6};
        int x = 5;
        insert_sorted(arr, n, x);
        assert(arr[2] == x);
    }
    {
        int n = 4;
        int* arr = new int[n] {1, 3, 5, 6};
        int x = 0;
        insert_sorted(arr, n, x);
        assert(arr[0] == x);
    }
    {
        int n = 4;
        int* arr = new int[n] {1, 3, 5, 6};
        int x = 7;
        insert_sorted(arr, n, x);
        assert(arr[4] == x);
    }
    std::cout << "Tests passed" << std::endl;

}

int main()
{
    test_insert();
    test_search_position();
    test_insert_sorted();
    return 0;
}
