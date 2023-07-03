#include <iostream>
using namespace std;
int findTotalOccurrence(int arr[], int n, int key, bool searchFirst)
{
    int low = 0, high = n - 1, result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            result = mid;
            if (searchFirst)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return result;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int key;
    cin >> key;
    int firstOccurrence = findTotalOccurrence(arr, n, key, true);
    int lastOccurrence = findTotalOccurrence(arr, n, key, false);
    if (firstOccurrence == -1 && lastOccurrence == -1)
        cout << "-1";
    else
        cout << lastOccurrence - firstOccurrence + 1;
    return 0;
}
