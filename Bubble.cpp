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

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
        }
    }
    
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}