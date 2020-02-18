#include<iostream>

using namespace std;

void insertSort(int a[], int length) {
	for (int i = 1; i < length; i++) {
		for (int j = i - 1; j >= 0 && a[j + 1] < a[j]; j--) {
			swap(a[j], a[j + 1]);
		}
	}
}


void insertSort2(int *arr, int len) {
	for (int i = 1; i < len; i++) {
		for (int j = i; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j - 1], arr[j]);
			}
		}
	}
}

int main() {

	int a[10] = {3, 1, 1, 3, 2, 4, 5, 8, 7, 6};
	insertSort2(a, 10);
	for (int i = 0; i < 10; ++i)
		cout << a[i] << " ";
}

