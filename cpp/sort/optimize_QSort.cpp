#include<iostream>
#include<cassert>
#include<stack>

using namespace std;

void QSwap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//???1?????????
int GetMidIndex(int *a, int left, int right)//???1????????��?
{
	int mid = left + ((right - left) >> 1);//??????��??????��?
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

//???2??��???????---?????????��??13???????????????????
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

//???????
int PartSort1(int *a, int left, int right)//???????
{
	int mid = GetMidIndex(a, left, right);
	QSwap(&a[mid], &a[right]);

	int key = a[right];//?????????????????????
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

//????
int PartSort2(int *a, int left, int right)//????
{
	int mid = GetMidIndex(a, left, right);
	QSwap(&a[mid], &a[right]);

	int key = a[right];//????????????????????
	int blank = right;//????????��?
	while (left < right) {
		while (left < right && a[left] <= key)
			++left;
		if (left != right) {
			QSwap(&a[left], &a[blank]);//??????????????????
			blank = left;
		}

		while (left < right && a[right] >= key)
			--right;
		if (left != right) {
			QSwap(&a[right], &a[blank]);//???????????��??????
			blank = right;
		}
	}
	return left;
}

//??????
int PartSort3(int *a, int left, int right)//??????
{
	int cur = left;
	int prev = cur - 1;
	int key = a[right];
	while (cur != right) {
		if (a[cur] < key) {
			++prev;
			if (cur != prev)
				QSwap(&a[cur], &a[prev]);//??prev????????????��??????
		}
		cur++;
	}
	++prev;
	QSwap(&a[cur], &a[prev]);
	return prev;
}

//??????
void QuickSort1(int *a, int left, int right)//??????
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

//???????
void QuickSort2(int *a, int left, int right)//???????
{
	stack<int> s;
	s.push(right);
	s.push(left);
	while (!s.empty()) {
		int begin = s.top();//????????
		s.pop();
		int end = s.top();//????????
		s.pop();
		int div = PartSort1(a, begin, end);
		if (begin < div - 1)//???????????
		{
			s.push(div - 1);
			s.push(begin);
		}
		if (div + 1 < end)//???????????
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

	int arr2[] = {9, 1, 2, 3, 4, 5, 6, 7, 8};//??????????????
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	//QuickSort1(arr2, 0, sz2 - 1);
	QuickSort2(arr2, 0, sz2 - 1);
	QPrint(arr2, sz2);

	int arr3[] = {6, 3, 2, 1, 4, 5, 7, 8, 9};//?????????????(7 8 9)
	int sz3 = sizeof(arr3) / sizeof(arr3[0]);
	//QuickSort1(arr3, 0, sz3 - 1);
	QuickSort2(arr3, 0, sz3 - 1);
	QPrint(arr3, sz3);

	int arr4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};//????????????????????��?
	int sz4 = sizeof(arr4) / sizeof(arr4[0]);
	//QuickSort1(arr4, 0, sz4 - 1);
	QuickSort2(arr4, 0, sz4 - 1);
	QPrint(arr4, sz4);
}

int main4435() {

	Test1();

}
