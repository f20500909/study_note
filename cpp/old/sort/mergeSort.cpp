#include<iostream>

using namespace std;


void Merge(int arr[], int l, int m, int r) {
    int len = r - l + 1;
    int *temp = new int[len];
    int i = 0;
    int left = l;
    int right = m + 1;
    while (left <= m && right <= r) temp[i++] = (arr[left] >= arr[right] ? arr[right++] : arr[left++]);
    while (left <= m) temp[i++] = arr[left++];
    while (right <= r) temp[i++] = arr[right++];
    for (int j = 0; j < len; j++) arr[l + j] = temp[j];
    delete[] temp;
}


void MergeSort(int arr[], int l, int r) {
    if (l == r) return;
    int m = l + ((r - l) >> 1);
    MergeSort(arr, l, m);
    MergeSort(arr, m + 1, r);
    Merge(arr, l, m, r);
}

int main4353() {
    int a[8] = {3, 1, 2, 4, 5, 8, 7, 6};
    MergeSort(a, 0, 7);
    for (int i = 0; i < 8; ++i)
        cout << a[i] << " ";
}

