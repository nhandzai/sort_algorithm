#include <iostream>
#include <ctime>
using namespace std;
int getMax(int *a, int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}
void CountingSort(int *a, int n, int exp)
{
    int count[10]{};
    int *temp = new int[n];

    for (int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        temp[count[a[i] / exp % 10] - 1] = a[i];
        count[a[i] / exp % 10]--;
    }

    for (int i = 0; i < n; i++) 
        a[i] = temp[i];
    delete[] temp;
}

void radixsort(int *a, int n)
{
    int m = getMax(a, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        CountingSort(a, n, exp);
}
int main()
{
    srand(time(NULL));
    int n = 10;

    int a[n]{};
    for (int i = 0; i < n; i++)
        a[i] = rand() % (500 - 0 + 1) + 0;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    radixsort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}