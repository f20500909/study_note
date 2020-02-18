#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

int partition(vector<int>& vec, int len, int start, int end) {
	assert(len > 0 && start >= 0 && end >= start);//����
	int index = start;//����������ָ��
	int small = start - 1;//���ڱȽϵ�ָ�룬���ڱȽ�ֵ�򲻶���С�ڱȽ�ֵ�򽻻�
	swap(vec[index], vec[end]);//ѡȡ��һ����Ϊ�ڱ��Ƚ�
	for (; index < end; index++) {//����
		if (vec[index] < vec[end]) {//��С���ӵ����,��Ĳ���
			small++;
			swap(vec[small],vec[index]);//����
		}
	}
	small++;
	swap(vec[small], vec[end]);//������ʼֵ
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
