#include <iostream>
using namespace std;
int findRotationCount(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        if (arr[low] <= arr[high])
            return low;
        int mid = low + (high - low) / 2;
        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;
        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
            return mid;
        else if (arr[mid] <= arr[high])
            high = mid - 1;
        else if (arr[mid] >= arr[low])
            low = mid + 1;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << findRotationCount(arr, n);
    return 0;
}
