#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

using namespace std;

void heapify(vector<int> &vec, int length, int index) {
    int left = (index << 1) + 1;
    int right = (index << 1) + 2;
    int maxId = index;
    if (left < length && vec[left] > vec[maxId]) maxId = left;
    if (right < length && vec[right] > vec[maxId]) maxId = right;
    if (maxId != index) {
        swap(vec[index], vec[maxId]);
        heapify(vec, length, maxId);
    }
}

void heapify2(vector<int>& vec,int len,int index){
    int left = (index<<1)+1;
    int right= (index<<1)+2;
    int maxId=index;
    if(left<len&&vec[left]>vec[maxId]) maxId =left;
}

void heapSort(vector<int> &vec, int length) {
    //从最后一个非叶子节点向上
    for (int i = length / 2 - 1; i >= 0; i--) {
        heapify(vec, length, i);
    }
    for (int i = length - 1; i >= 1; i--) {
        swap(vec[0], vec[i]);
        heapify(vec, i, 0);
    }
}

void heapSort2(vector<int> &vec, int len) {
    //建立初始堆
    for (int i = len / 2 - 1; i > 0; i--) {
        heapify(vec, len, i);
    }
    //依次排序
    for(int i=len-1;i>=1;i--){
        swap(vec[0],vec[i]);
        heapify(vec,i,0);
    }
}


int main() {
    vector<int> vec = {4, 2, 6, 7, 1, 3, 5, 8};
    for_each(vec.begin(), vec.end(), [](int i) { cout << i << " "; });
    cout << endl;
    heapSort(vec, vec.size());

    for_each(vec.begin(), vec.end(), [](int i) { cout << i << " "; });
    return 0;
}

