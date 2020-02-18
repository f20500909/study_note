#include <iostream>
#include <vector>
using namespace std;


int binarySearch(vector<int> data, int len, int key) {
	int low = 0;
	int high = len - 1;
	int mid = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (data[mid] == key) return mid;
		if (data[mid] < key)low = mid + 1;
		else high = mid - 1;
	 }
	return -1;
}




int main() {
	vector<int> vec = {1,2,3,4,5,6};

	cout << binarySearch(vec,vec.size(),4) << endl;

	cin.get();

	return 0;
}