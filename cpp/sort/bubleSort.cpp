#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;


void bubbleSort(vector<int>& vec, int len) {
	for (int i = 0; i < len-1; i++) {
		for (int j = 0; j < len-i-1; j++) {
			if (vec[j] > vec[j+1])swap(vec[j], vec[j+1]);

		}
		//for_each(vec.begin(), vec.end(), [](int i) { cout << i << " "; });
		//cout << endl;
	}




	return;
}




int main() {
	vector<int> vec = { 4, 2, 6, 7,1, 1, 3, 5, 8 };
	for_each(vec.begin(), vec.end(), [](int i) { cout << i << " "; });
	cout << endl;
	bubbleSort(vec, vec.size());

	for_each(vec.begin(), vec.end(), [](int i) { cout << i << " "; });

	cin.get();

	return 0;
}
