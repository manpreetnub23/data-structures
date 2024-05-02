#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the size of ARRAY \n";
    cin >> n;
    int *arr = new int[n];
    cout << "enter the element sof array \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int least = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[least])
                least = j;
        }
        if (least != i)
        {
            int temp = arr[i];
            arr[i] = arr[least];
            arr[least] = temp;
        }
        cout << "intermediate step : ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "done.\n";
    }
}