#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {12, 55, 10, 80, 4};
    int j, key;
    for (int i = 1; i < 5; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}