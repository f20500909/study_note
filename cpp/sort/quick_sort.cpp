
#include <iostream>
#include <vector>

using namespace std;


void print(const vector<int> &vec) {
    for (auto v:vec) {
        cout << v << " ";
    }
    cout << endl;
}





// 第一种方法 双指针头尾推进，复合条件就交换
int partition1(vector<int>& vec,int left,int right){
    int key=vec[right];
    while(left<right){
        while(left<right&&vec[left]<=key) left++;
        while(left<right&& vec[right]>=key) right--;
        swap(vec[left],vec[right]);
    }
    swap(vec[left],key);
    return left;
}


int partitiona3(vector<int>& vec,int left,int right){
    int val = vec[right];
    while(left<right){
        while(left<right&&vec[left]<=val)left++;
        while(left<right&&vec[right]>=val)right--;
        swap(vec[left],vec[right]);
    }
    swap(vec[left],val);
    return left;
}



// 第二种方法 双指针从头开始，快慢推进，遍历完所有数据
int partition2(vector<int> &vec, int left, int right) {
    int index = left;//用来遍历的指针
    int small = left - 1;//用于比较的指针，大于比较值则不动，小于比较值则交换
    swap(vec[index], vec[right]);//选取第一个作为哨兵比较
    for (; index < right; index++) {//遍历
        if (vec[index] < vec[right]) {//将小的扔到左边,大的不变
            small++;
            swap(vec[small],vec[index]);//交换
        }
    }
    small++;
    swap(vec[small], vec[right]);//交换初始值
    return small;
}



void quickSort(vector<int> &vec, int left, int right) {
    if (left > right) return;
    int index = partition2(vec, left, right);
    if (index > left) quickSort(vec, left, index - 1);
    if (index < right) quickSort(vec, index + 1, right);
}

int partition3(vector<int> data,int left,int right){
    int val =data[right];
    while(left<right){
        while(left<right&&data[left]<=val) left++;
        while(left<right&&data[right]>=val) right--;
        swap(data[left],data[right]);
    }
    swap(data[left],val);
    return left;
}

void quickSort3(vector<int> data,int left,int right){
    if(left>right) return ;
    int index = partition3(data,left,right);
    if(index>left) quickSort3(data,left,index-1);
    if(index<right) quickSort3(data,index+1,right);
}

int main() {

    vector<int> data = {4, 7, 8, 3, 1, 1, 2, 6, 5};
    print(data);
//    bubleSort(data);
    quickSort2(data, 0, data.size() - 1);
//    selectSort(data);


    print(data);


    return 0;
}