#include<iostream>
#include<cassert>
#include<stack>

using namespace std;

void QSwap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//�Ż�1������ȡ��
int GetMidIndex(int *a, int left, int right)//�Ż�1������ȡ�з�
{
	int mid = left + ((right - left) >> 1);//ȡ�����м�Ԫ�ص��±�
	if (a[left] > a[mid])//left > mid
	{
		if (a[left] < a[right])//mid < left < right
			return left;
		else//left > mid,left > right
		{
			if (a[right] > a[mid])//mid < right < left
				return right;
			else//right < mid < left
				return mid;
		}
	} else//left < mid
	{
		if (mid > right)//left < mid < right
			return mid;
		else//mid < left,mid < right
		{
			if (left < right)//mid < left < right
				return left;
			else
				return right;
		}
	}
}

//�Ż�2��С�����Ż�---������Ԫ��С��13ʱ��ֱ�Ӳ���ֱ�Ӳ�������
void InsertSort(int *a, int left, int right) {
	int end = 0;
	for (int i = 1; i < right; i++) {
		end = i - 1;
		int temp = a[i];
		while (end >= 0) {
			if (a[end] > temp) {
				a[end + 1] = a[end];
				--end;
			} else
				break;
		}
		a[end + 1] = temp;
	}
}

//����ָ�뷨
int PartSort1(int *a, int left, int right)//����ָ�뷨
{
	int mid = GetMidIndex(a, left, right);
	QSwap(&a[mid], &a[right]);

	int key = a[right];//����������ұߵ�ֵ��Ϊ��׼ֵ
	int keyidx = right;
	while (left < right) {
		while (left < right && a[left] <= key)
			++left;
		while (left < right && a[right] >= key)
			--right;
		if (a[left] != a[right])
			QSwap(&a[left], &a[right]);
	}
	QSwap(&a[left], &a[keyidx]);
	return left;
}

//�ڿӷ�
int PartSort2(int *a, int left, int right)//�ڿӷ�
{
	int mid = GetMidIndex(a, left, right);
	QSwap(&a[mid], &a[right]);

	int key = a[right];//ѡ��������ұߵ�ֵ��Ϊ��׼ֵ
	int blank = right;//�ӻ�׼ֵ���±�
	while (left < right) {
		while (left < right && a[left] <= key)
			++left;
		if (left != right) {
			QSwap(&a[left], &a[blank]);//���ҵ��ıȻ�׼ֵ���ֵ���
			blank = left;
		}

		while (left < right && a[right] >= key)
			--right;
		if (left != right) {
			QSwap(&a[right], &a[blank]);//���ҵ��ıȻ�׼ֵС��ֵ���
			blank = right;
		}
	}
	return left;
}

//ǰ��ָ�뷨
int PartSort3(int *a, int left, int right)//ǰ��ָ�뷨
{
	int cur = left;
	int prev = cur - 1;
	int key = a[right];
	while (cur != right) {
		if (a[cur] < key) {
			++prev;
			if (cur != prev)
				QSwap(&a[cur], &a[prev]);//��prevָ��һֱָ��Ȼ�׼ֵС������
		}
		cur++;
	}
	++prev;
	QSwap(&a[cur], &a[prev]);
	return prev;
}

//�ݹ�ʵ��
void QuickSort1(int *a, int left, int right)//�ݹ�ʵ��
{
	assert(a);
	if (left < right) {
		//int div = PartSort1(a, left, right);
		//int div = PartSort2(a, left, right);
		int div = PartSort3(a, left, right);

		/*if (left-right+1 <= 13)
		{
				InsertSort(a, left, right);
				return;
		}*/
		QuickSort1(a, left, div - 1);
		QuickSort1(a, div + 1, right);
	}
}

//�ǵݹ�ʵ��
void QuickSort2(int *a, int left, int right)//�ǵݹ�ʵ��
{
	stack<int> s;
	s.push(right);
	s.push(left);
	while (!s.empty()) {
		int begin = s.top();//������߽�
		s.pop();
		int end = s.top();//�����ұ߽�
		s.pop();
		int div = PartSort1(a, begin, end);
		if (begin < div - 1)//ģ��ݹ�������
		{
			s.push(div - 1);
			s.push(begin);
		}
		if (div + 1 < end)//ģ��ݹ�������
		{
			s.push(end);
			s.push(div + 1);
		}
	}
}

void QPrint(int *a, int len) {
	for (int i = 0; i < len; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void Test1() {
	int arr1[] = {2, 4, 5, 8, 1, 3, 0, 6, 7};
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	QuickSort1(arr1, 0, sz1 - 1);
	//QuickSort2(arr1, 0, sz1 - 1);
	QPrint(arr1, sz1);

	int arr2[] = {9, 1, 2, 3, 4, 5, 6, 7, 8};//ֻ��Ҫ����ð�ݼ���
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	//QuickSort1(arr2, 0, sz2 - 1);
	QuickSort2(arr2, 0, sz2 - 1);
	QPrint(arr2, sz2);

	int arr3[] = {6, 3, 2, 1, 4, 5, 7, 8, 9};//��벿����������(7 8 9)
	int sz3 = sizeof(arr3) / sizeof(arr3[0]);
	//QuickSort1(arr3, 0, sz3 - 1);
	QuickSort2(arr3, 0, sz3 - 1);
	QPrint(arr3, sz3);

	int arr4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};//���������ֵ����������Сֵ
	int sz4 = sizeof(arr4) / sizeof(arr4[0]);
	//QuickSort1(arr4, 0, sz4 - 1);
	QuickSort2(arr4, 0, sz4 - 1);
	QPrint(arr4, sz4);
}

int main4435() {

	Test1();

}
