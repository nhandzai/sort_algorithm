#include <iostream>
#include <ctime>
using namespace std;

int sort(int *a, int start, int end)
{
    int j, i;
    i = j = start;
    while (j < end)
    {
        if (a[j] < a[end])
        {
            swap(a[i], a[j]);
            i++;
        }
        ++j;
    }
    swap(a[i], a[end]);
    return i;
}
void QuickSort(int *a, int start, int end)
{
    if (start >= end)
        return;
    int pivot = sort(a, start, end);
    QuickSort(a, start, pivot - 1);
    QuickSort(a, pivot + 1, end);
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

    QuickSort(a, 0, 10 - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}