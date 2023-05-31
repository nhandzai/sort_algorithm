#include <iostream>
using namespace std;

int binarySearch(int *a, int l, int r, int k)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == k)
            return mid;
        else if (a[mid] < k)
            l = ++mid ;
        else
            r = --mid;
    }
    return -1;
}
int main()
{
    int a[10] = {2, 3, 4, 10, 40};
    cout << binarySearch(a, 0, 4, 40);
    return 0;
}