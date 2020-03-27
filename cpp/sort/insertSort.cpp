#include<iostream>
#include<vector>

using namespace std;

void insertSort(vector<int> &data) {
    //从第二个元素开始遍历 因为第一个元素插入不了
    for (int i = 1; i < data.size(); i++) {
        //从i-1个开始向前遍历  如果前一个数比后一个数大 就互换
        for (int j = i - 1; j >= 0 && data[j + 1] < data[j]; j--) {
            swap(data[j], data[j + 1]);
        }
    }
}

void insertSort3(vector<int> &data) {
    for (int i = 1; i < data.size(); i++) {
        for (int j = i -1; j>=0 < data.size(); j++){


        }

    }


}


int main() {

    int a[10] = {3, 1, 1, 3, 2, 4, 5, 8, 7, 6};
    insertSort2(a, 10);
    for (int i = 0; i < 10; ++i)
        cout << a[i] << " ";
}

