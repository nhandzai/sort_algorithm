#include <iostream>
#include <ctime>
using namespace std;

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

    int h = n / 2;
    while (h > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (i + h == n)
                break;
            int pos = i;
            while (pos >= 0 && a[pos] > a[pos + h])
            {
                swap(a[pos], a[pos + h]);
                pos = pos - h;
            }
        }
        h = h / 2;
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}