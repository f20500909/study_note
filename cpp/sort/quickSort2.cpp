#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

int partition(vector<int>& vec, int len, int start, int end) {
	assert(len > 0 && start >= 0 && end >= start);//断言
	int index = start;//用来遍历的指针
	int small = start - 1;//用于比较的指针，大于比较值则不动，小于比较值则交换
	swap(vec[index], vec[end]);//选取第一个作为哨兵比较
	for (; index < end; index++) {//遍历
		if (vec[index] < vec[end]) {//将小的扔到左边,大的不变
			small++;
			swap(vec[small],vec[index]);//交换
		}
	}
	small++;
	swap(vec[small], vec[end]);//交换初始值
	return small;
}
 
void quickSort(vector<int>& vec, int len, int start, int end) {
	if (start >= end) return;
	int index = partition(vec, len, start, end);
	if (index > start) quickSort(vec, len, start, index - 1);
	if (index < end) quickSort(vec, len, index + 1, end);
}

int main() {
	vector<int> vec = { 4, 2, 6, 7,1, 1, 3, 5, 8 };
	for_each(vec.begin(), vec.end(), [](int i) { cout << i << " "; });
	cout << endl;
	quickSort(vec, vec.size(), 0, vec.size() - 1);

	for_each(vec.begin(), vec.end(), [](int i) { cout << i << " "; });

	cin.get();

	return 0;
}
