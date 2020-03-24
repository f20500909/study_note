#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

void print(const vector<int> &vec) {
    for (auto v:vec) {
        cout << v << " ";
    }
    cout << endl;
}

void selectSort(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        int minIndex = i;
        for (int j = i; j < vec.size(); j++) {
            // 如果索引值比当前值大  就更新索引值 让索引成为当前id  从而是最小值的索引
            if (vec[j] < vec[minIndex]) minIndex = j;
        }
        swap(vec[minIndex], vec[i]);
    }
}

void selectSort2(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        int index = i; //最小值得索引
        for (int j = i; j < vec.size(); j++) {
            if (vec[j] < vec[index]) index = j;
        }
        swap(vec[i], vec[index]);

    }

}


int main() {

    vector<int> data = {4, 7, 8, 3, 1, 1, 2, 6, 5};
    print(data);
    selectSort(data);
    print(data);

    return 0;
}