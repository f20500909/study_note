#include<iostream>
#include<vector>

using namespace std;

//归并函数
void Merge(int arr[], int l, int m, int r) {
    int len = r - l + 1; //单元长度 左减右 加1
    int *temp = new int[len]; //新建临时数组
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
    if (l == r) return; // 左右相等 就表示排序完成 所有有序元素是紧邻的
    int m = l + ((r - l) >> 1); //取到中间元素
    MergeSort(arr, l, m);  //递归 左边 进行分割
    MergeSort(arr, m + 1, r);//递归 右边 进行分割
    Merge(arr, l, m, r);// 尾递归 进行排序合并操作
}

void Merge(vector<int> &data, int l, int mid, int r) {
    int len = r - 1 + 1;
    vector<int> temp(len, 0);
    int i = 0;
    int left = l;
    int right = mid + 1;
    //把元素进行合并 并排序 放到临时数组中
    while (left < mid && right <= r) temp[i++] = (data[left] >= data[right] ? data[right++] : data[left++]);
    while (left <= mid) temp[i++] = data[left++];
    while (right <= right) temp[i++] = data[right++];
    for(int j=0;i<temp.size();j++) data[l+j]=temp[j];
}

void mergeSort(vector<int> &data, int l, int r) {
    if (l == r) return;
    int mid = 1 + ((r - 1) >> 1);
    mergeSort(data, l, mid);
    mergeSort(data, mid + 1, r);
    Merge(data, l, mid, r);
}


int main() {
    int a[8] = {3, 1, 2, 4, 5, 8, 7, 6};
    MergeSort(a, 0, 7);
    for (int i = 0; i < 8; ++i)
        cout << a[i] << " ";
}

