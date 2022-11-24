#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int l, int h)
{
    int pivot, index;
    index = l;
    pivot = h;
    for (int i = l; i < h; i++)
    {
        if (a[i] < a[pivot])
        {
            swap(a[i], a[index]);
            index++;
        }
    }
    swap(a[index], a[pivot]);
    return index;
}

int r_partition(vector<int> &a, int l, int h)
{
    int r = rand();
    r = l + r % (h - l + 1);
    swap(a[r], a[h]);
    return partition(a, l, h);
}

void quicksort(vector<int> &a, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int p = partition(a, low, high);
    quicksort(a, low, p - 1);
    quicksort(a, p + 1, high);
}

void r_quicksort(vector<int> &a, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int rp = r_partition(a, low, high);
    r_quicksort(a, low, rp - 1);
    r_quicksort(a, rp + 1, high);
}

int main()
{

    vector<int> arr;
    int n;
    cout << "Enter number of elements:" << endl;
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << " : " << endl;
        cin >> temp;
        arr.push_back(temp);
    }
    cout << "Before sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    r_quicksort(arr, 0, arr.size() - 1);
    cout << endl;
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}