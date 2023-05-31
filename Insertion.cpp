#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    int n = 10;

    int a[n]{};
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % (20 - 0 + 1) + 0;
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    for (int i = 1; i < n - 1; i++)
    {
        int x = a[i];
        int pos = i - 1;
        while (pos >= 0 && x < a[pos])
        {
            swap(a[pos + 1], a[pos]);
            pos--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}