#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void DNFSort(int arr[], int low, int high)
{
    int mid = 0;
    int i = 0;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(&arr[mid], &arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(&arr[mid], &arr[high]);
            high--;
        }
    }
}
int main()
{
    int arr[10] = {1, 1, 2, 0, 0, 1, 2, 2, 1, 0};
    DNFSort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}
