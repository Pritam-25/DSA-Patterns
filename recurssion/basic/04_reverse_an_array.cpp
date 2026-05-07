#include<iostream>
#include<vector>
using namespace std;

void reverse(int l, int r, vector<int>& arr) {
    if (l >= r)return;

    swap(arr[l], arr[r]);
    reverse(l + 1, r - 1, arr);
}

void reverseSingleVariable(int i, vector<int>& arr) {
    int n = arr.size();
    if (i >= n / 2)return;

    swap(arr[i], arr[n - i - 1]);
    reverseSingleVariable(i + 1, arr);
}

int main() {
    vector<int> arr = { 1, 2, 3,4,5 };
    int n = arr.size();
    reverse(0, n - 1, arr);

    cout << "reverse using two pointers: " << endl;
    for (auto it : arr) {
        cout << it << " ";
    }

    vector<int> newArr = { 1, 2, 3,4,5, 6, 7, 8 };
    reverseSingleVariable(0, newArr);

    cout << endl << "reverse using single variable: " << endl;
    for (auto it : newArr) {
        cout << it << " ";
    }
    return 0;
}