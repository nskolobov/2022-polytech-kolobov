#include <cassert>

int *insert(int arr[], int n, int x, int p);
int search_position(int arr[], int n, int x);

int main() {
  // NOTE: aN - array
  for (auto i = 0; i < 11; ++i)
    assert(r0[i] == expected_r0[i]);

  // `search_position` example
  int a1[4] = {1, 3, 5, 6};
  assert(search_position(a1, 4, 5) == 2);

  int a2[4] = {1, 3, 5, 6};
  assert(search_position(a2, 4, 7) == 4);

  return 0;
}
arr[p] = x;
  return arr;
}

int search_position(int arr[], int n, int x) {
  for (auto i = 0; i < n - 1; ++i) {
    if (arr[i] >= x)
      return i;
  }
  return n;
}
