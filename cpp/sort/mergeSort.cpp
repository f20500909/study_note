#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
#define MIN(x, y) ( (x)>(y)?(y):(x))
#define MAX(x, y) ( (x)>(y)?(x):(y))

//归并函数
void Merge(vector<int> &data, int l, int m, int r) {
    int len = r - l + 1; //单元长度 左减右 加1
    int *temp = new int[len]; //新建临时数组
    int i = 0;
    int left = l;
    int right = m + 1;
    while (left <= m && right <= r) temp[i++] = (data[left] >= data[right] ? data[right++] : data[left++]);
    while (left <= m) temp[i++] = data[left++];
    while (right <= r) temp[i++] = data[right++];
    for (int j = 0; j < len; j++) data[l + j] = temp[j];
    delete[] temp;
}

void Merge2(vector<int> &data, int l, int m, int r) {
    int len = r - l + 1;
    vector<int> temp(len, 0);
    int cur = 0;
    int left = l;
    int right = m + 1;
    while (left <= m && right <= r) {
        temp[cur++] = (data[left] >= data[right] ? data[right++] : data[left++]);
    }
    while (left <= m) temp[cur++] = data[left++];
    while (right <= r) temp[cur++] = data[right++];
    for (int i = 0; i < temp.size(); i++) data[l + i] = temp[i];
}


void MergeSort(vector<int> &data, int l, int r) {
    if (l == r) return; // 左右相等 就表示排序完成 所有有序元素是紧邻的
    int m = l + ((r - l) >> 1); //取到中间元素
    MergeSort(data, l, m);  //递归 左边 进行分割
    MergeSort(data, m + 1, r);//递归 右边 进行分割
    Merge2(data, l, m, r);// 尾递归 进行排序合并操作
}

void MergeSort2(vector<int> &data, int left, int right) {
    if (left >= right) return;
    unsigned gap = 1;
    while (gap < data.size()) {
        for (unsigned l = 0; l < data.size(); l += 2 * gap) {
            int mid = l + gap - 1;
            int r = MIN(l + 2 * gap - 1, data.size() - 1);
            Merge(data, l, mid, r);
        }
        gap = gap << 1;
    }
}

void mergeSort3(vector<int> &data, int left, int right) {
    if (left >= right) return;
    int gap = 1;
    int l;
    int r;
    int mid;
    while (gap < data.size()) {
        for (int l = 0; l < data.size(); l += 2 * gap) {
            mid = l + gap - 1;
            r = min(l + 2 * gap - 1, int(data.size() - 1));
            Merge(data, l, mid, r);
        }
        gap = gap << 1;
    }

}



int main() {
    vector<int> data = {3, 1, 2, 4, 5, 8, 7, 6};
    mergeSort3(data, 0, 7);
    for (int i = 0; i < 8; ++i)
        cout << data[i] << " ";
}

