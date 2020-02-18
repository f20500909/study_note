#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int count(int n) {
	int res = 0;
	while (n > 0) {
		res++;
		n /= 10;
	}
	return res;
}

bool cmp(int a, int b) {
	int flag = 1;
	if (a < b) {
		swap(a, b);
		flag = -1;
	}
	int diff = count(a) - count(b);
	while (diff-- > 0) {
		b *= 10;
	}
	return (flag == 1 ? (a > b) : (b > a));
}


int main() {

	vector<int> vec = {7, 13, 4, 246};
	sort(vec.begin(), vec.end(), &cmp);
	for (auto v:vec) {
		cout << v << endl;
	}
}
