#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int binarysearch(int arr[], int l, int h, int key)
{
    int mid = (l + h) / 2;
    while (h >= l)
    {
        if (key == arr[mid])
        {
            return mid;
        }
        if (arr[mid] < key)
        {
            return binarysearch(arr, mid + 1, h, key);
        }
        if (arr[mid] > key)
        {
            return binarysearch(arr, l, mid - 1, key);
        }
    }
    return -1;
}
int main()
{
    int arr[5] = {12, 22, 44, 89, 103};
    int key;
    cin >> key;
    int ans = binarysearch(arr, 0, 4, key);
    cout << ans;
}