#include <iostream>
using namespace std;
int binary_search(int a[], int l, int r, int key)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (key == a[m])
            return m;
        else if (key < a[m])
            r = m -1;
        else
            l = m + 1;
    }
    return -1;
}

int main()
{
    int n, key;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter array elements: ";
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter search ker: ";
    cin >> key;
    int res = binary_search(a, 0, n - 1, key);
    if (res != -1)
        cout << key << " Found at index " << res << endl;
    else 
        cout << key << " not found" << endl;
    return 0;
}