#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void keepHeap(vector<int>& data,int heap_size,int k) {
	int left = 2 * k + 1;
	int right = 2 * k + 2;
	int largest = k;

	if (left<heap_size&&data[left]>data[k]) {
		largest = left;
	}
	if (right<heap_size&&data[right]>data[largest]) {
		largest = right;
	}
	if (largest != k) {
		swap(data[k],data[largest]);
		keepHeap(data,heap_size,largest);//递归调用叶子节点.
	}
}

void buildHeap(vector<int>& data, int heap_size) {
	int i = heap_size/2-1;
	while (i >= 0) 
	{
		keepHeap(data, heap_size, i);
		i--;
	}
}



void heapSort(vector<int>& data,int length) {
	int heap_size = length;
	buildHeap(data, heap_size);
	for (int i = heap_size - 1; i > 0; --i) {
		swap(data[0], data[i]);
		heap_size=heap_size-1;
		keepHeap(data, heap_size, 0);
	 }
 }


 

 
int main() {

	vector<int> vec = { 4, 2, 6,1, 7, 1, 3, 5, 8 };
	for_each(vec.begin(), vec.end(), [](int i) { cout << i << " "; });
	cout << endl;
	heapSort(vec, vec.size());

	for_each(vec.begin(), vec.end(), [](int i) { cout << i << " "; });

	cin.get();

	return 0;
 
}

