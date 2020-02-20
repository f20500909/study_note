
#include <iostream>
#include <vector>

using namespace std;


void print(const vector<int> &vec) {
    for (auto v:vec) {
        cout << v << " ";
    }
    cout << endl;
}


int partition1(vector<int> &vec, int left, int right) {
    int small = left - 1;
    int index = left;
    swap(vec[left], vec[right]);
    for (; index < right; index++) {
        if (vec[index] < vec[right]) {
            small++;
            if (small != index) swap(vec[small], vec[index]);
        }
    }
    small++;
    swap(vec[small], vec[right]);
    return small;
}

int PartSort(vector<int>& array, int left, int right) {
    int key = array[right];
    while (left < right) {
        while (left < right && array[left] <= key) {
            ++left;
        }
        while (left < right && array[right] >= key) {
            --right;
        }
        swap(array[left], array[right]);
    }
    swap(array[left], key);
    return left;
}


int partition(vector<int>& vec,int left,int right){
    int key=vec[right];
    while(left<right){
        while(left<right&&vec[left]<=key) left++;
        while(left<right&& vec[right]>=key) right--;
        swap(vec[left],vec[right]);
    }
    swap(vec[left],key);
    return left;
}



void quickSort(vector<int> &vec, int left, int right) {
    if (left > right) return;

    int index = PartSort(vec, left, right);

    if (index > left) quickSort(vec, left, index - 1);

    if (index < right) quickSort(vec, index + 1, right);

}





int main342342() {

    vector<int> data = {4, 7, 8, 3, 1, 1, 2, 6, 5};
    print(data);
//    bubleSort(data);
    quickSort(data, 0, data.size() - 1);
//    selectSort(data);


    print(data);


    return 0;
}