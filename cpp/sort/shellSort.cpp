#include<iostream>
#include<vector>

using namespace std;
const int INCRGAP = 2;

void shellSort1(int a[], int len) {
    int gap, i, j;
    //间隔每次减半
    for (gap = len / 2; gap > 0; gap /= 2) {
        //遍历所有
        for (i = gap; i < len; i++) {
            for (j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap) {
                swap(a[j], a[j + gap]);
            }
        }

    }
}

void shellSort2(int *a, int len) {
    int i;
    int j;
    for (int gap = len / 2; gap > 0; gap = gap >> 1) {
        for (i = gap; i < len; i++) {
            for (j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap) {
                swap(a[j], a[j + gap]);
            }
        }
    }
}

void shellSort2(vector<int> &data) {
    int i;
    int j;
    for (int gap = data.size() / 2; gap > 0; gap = gap >> 1) {
        for (i = gap; i < data.size(); i++) {
            for (j = i - gap; j >= 0 && data[j] > data[j + gap]; j -= gap) {
                swap(data[j], data[j + gap]);
            }
        }
    }
}


int main() {
    int array[13] = {2, 1, 4, 3, 3, 4, 11, 6, 5, 7, 8, 10, 15};
//    shellSort1(array, 13);
//    shellSort2(array, 13);
//    shellSort3(array, 13);
    for (auto it: array) {
        cout << it << " ";
    }
    return 0;
}

