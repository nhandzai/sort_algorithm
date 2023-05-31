#include <iostream>
#include <ctime>
using namespace std;
void Merge(int *a, int lenA, int *b, int lenB, int *x)
{
    int i, j, count;
    i = j = count = 0;

    while (i < lenA && j < lenB)
    {
        if (a[i] < b[j])
            x[count++] = a[i++];
        else
            x[count++] = b[j++];
    }
    while (i < lenA)
        x[count++] = a[i++];
    while (j < lenB)
        x[count++] = b[j++];
}
void MergeSort(int *a, int n)
{
    if (n <= 1)
        return;

    int mid = n / 2;
    int leftA[mid];
    int rightA[n - mid];

    for (int i = 0; i < mid; i++)
        leftA[i] = a[i];

    int count = 0;
    for (int i = mid; i < n; i++)
        rightA[count++] = a[i];

    MergeSort(leftA, mid);
    MergeSort(rightA, n - mid);
    Merge(leftA, mid, rightA, n - mid, a);
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

    MergeSort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}