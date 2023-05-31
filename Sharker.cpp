#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    int n = 10;

    int a[10]{};
    for (int i = 0; i < n; i++)
        a[i] = rand() % (20 - 0 + 1) + 0;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    int top = 0;
    int bot = n - 1;
    int k;
    while (bot > top)
    {
        for (int i = bot; i > top; i--)
        {
            if (a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
            }
           
        }
        top++;

        for (int i = top; i < bot; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
            }
            
        }
        bot--;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}