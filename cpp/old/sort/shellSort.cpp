#include<iostream>

using namespace std;
const int INCRGAP = 2;

void shellSort(int a[], int len) {
    int insertNum = 0;
    int gap = len / INCRGAP;
    while (gap)
    {
        for (int i = gap; i < len; ++i)
        {
            insertNum = a[i];
            int j = i;
            while (j >= gap && insertNum < a[j - gap])
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = insertNum;
        }
        gap = gap / INCRGAP;
    }
}


void shellSort2(int* arr,int len){
    int gap=len/2;
    while(gap>=1){
        for(int i=gap;i<len;i++){
            int insertNum=arr[i];
            int j=i;
            while(j>=gap&&insertNum<a[j-gap]){
                a[j]=a[j-gap];
                j-=gap;
            }
            a[j]=insertNum;
        }
        gap=gap>>1;
    }
    return ;
}




int main() {
    int array[13] = {2, 1, 4, 3, 3, 4, 11, 6, 5, 7, 8, 10, 15};
//	shellSort(array, 13);
    shellSort2(array, 13);
    for (auto it: array) {
        cout << it << " ";
    }
    return 0;
}

