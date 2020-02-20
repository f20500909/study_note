#include<iostream>
#include<vector>

using namespace std;

void adjust(vector<int> &vec, int len, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int maxId = index;
    if (left < len && vec[left] > vec[maxId]) maxId = left;
    if (right < len && vec[right] > vec[maxId]) maxId = right;
    if (maxId != index) {
        swap(vec[maxId], vec[index]);
        adjust(vec, len, maxId);
    }
}


void heapSort(vector<int> &vec, int len) {
    //建堆
    for (int i = len >> 1 - 1; i >= 0; i--) adjust(vec, len, i);
    //缩小堆的尺寸,输出有序数组;
    for (int i = len - 1; i >= 1; i--) {
        swap(vec[0], vec[i]);
        adjust(vec, i, 0);
    }
}


void heapify(vector<int> &vec, int len, int index) {
    int left = (index << 1) + 1;
    int right = (index << 1) + 2;
    int maxId = index;
    while (left < len && vec[left] > vec[maxId]) maxId = left;
    while (right < len && vec[right] > vec[maxId]) maxId = right;
    if (maxId != index) {
        swap(vec[maxId], vec[index]);
        heapify(vec, len, maxId);
    }
}


void heapSort2(vector<int> &vec, int len) {
    for (int i = (len >> 1); i >= 0; i--) {
        heapify(vec, len, i);
    }
    for (int i = len - 1; i >= 1; i--) {
        swap(vec[0],vec[i]);
        heapify(vec,i,0);
    }
}


int maindfdsf() {
    vector<int> arr = {8, 1, 14, 3, 21, 5, 7, 10};
    heapSort2(arr, arr.size());
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }
    return 0;
}


