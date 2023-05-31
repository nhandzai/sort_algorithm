#include <iostream>
#include <ctime>
using namespace std;
int binarySearch(int *a, int l, int r, int k)
{
    int mid = 0;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        if (a[mid] == k)
            return mid;
        else if (a[mid] < k)
            l = ++mid;
        else
            r = --mid;
    }
    if (k < a[mid])
        return mid;
    else
        return mid + 1;
}
int main()
{
    srand(time(NULL));
    int n = 10;

    int a[n]{};
    for (int i = 0; i < n; i++)
        a[i] = rand() % (20 - 0 + 1) + 0;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    for (int i = 1; i < n; i++)
    {
        int x = binarySearch(a, 0, i - 1, a[i]);
        int temp = a[i];
        for (int j = i; j > x; j--)
            a[j] = a[j - 1];
        a[x] = temp;
    }
    
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}