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
            if (vec[j] < vec[minIndex]) minIndex = j;
        }
        swap(vec[minIndex], vec[i]);
    }
}


int main() {

    vector<int> data = {4, 7, 8, 3, 1, 1, 2, 6, 5};
    print(data);
    selectSort(data);
    print(data);


    return 0;
}