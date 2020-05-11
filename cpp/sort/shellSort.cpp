#include<iostream>
#include<vector>

using namespace std;
const int INCRGAP = 2;

void shellSort1(vector<int> &data) {
    int len = data.size();
    int gap, i, j;
    //间隔每次减半
    for (gap = len / 2; gap > 0; gap /= 2) {
        //遍历所有
        for (i = gap; i < len; i++) {
            for (j = i - gap; j >= 0 && data[j] > data[j + gap]; j -= gap) {
                swap(data[j], data[j + gap]);
            }
        }
    }
}

void shellSort2(vector<int> &data) {
    int len = data.size();
    int gap;
    for (gap = len >> 1; gap > 0; gap >>= 1) {
        for (int i = gap; i < len; i++) {
            for (int j = i - gap; j >= 0; j -= gap) {
                //冒牌大的向上浮
                if (data[j] > data[j + gap])swap(data[j], data[j + gap]);
            }
        }
    }
}


int main() {
    vector<int> array = {2, 1, 4, 3, 3, 4, 11, 6, 5, 7, 8, 10, 15};
//    shellSort1(array, 13);
//    shellSort2(array, 13);
    shellSort2(array);
    for (auto it: array) {
        cout << it << " ";
    }
    return 0;
}

