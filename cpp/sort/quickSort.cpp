
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

using namespace std;

int Partition(vector<int>& data, int length, int start, int end) {
    if (length <= 0 || start < 0 || end >= length) {
        exit(-1);
    }
    int index = start;
    swap(data[index], data[end]);
    int small = index - 1;
    for (index = start; index < end; ++index) {
        if (data[index] < data[end]) {
            ++small;
            swap(data[index], data[small]);
        }
    }
    ++small;
    swap(data[small], data[end]);
    return small;
}

int partition(vector<int>& vec,int len,int left,int right){
    int small=left-1;
    swap(vec[left],vec[right]);
    for(int i=left;i<right;i++){
        if(vec[i]<vec[left]){
            small++;
            swap(vec[i],vec[small]);
        }
    }
    small++;
    swap(vec[right],vec[small]);
    return small;
}

void QuickSort(vector<int>& data, int length, int start, int end) {
    if (start == end)return;
    int index = Partition(data, length, start, end);
    if (index > start) {
        QuickSort(data, length, start, index - 1);
    }
    if (index < end) {
        QuickSort(data, length, index + 1, end);
    }
}







void QuickSort2(vector<int>& vec,int len,int left,int right){
    if(left>=right) return ;
    int index=partition(vec,len,left,right);
    if(index>left) QuickSort2(vec,len,left,index-1);
    if(index<right) QuickSort2(vec,len,index+1,right);
}


int main() {
    vector<int> vec = {4, 2, 6, 7, 1, 3, 5, 8};
    for_each(vec.begin(), vec.end(), [](int i) { cout << i << " "; });
    cout << endl;
    QuickSort2(vec, vec.size(), 0, vec.size() - 1);

    for_each(vec.begin(), vec.end(), [](int i) { cout << i << " "; });
    return 0;
}

