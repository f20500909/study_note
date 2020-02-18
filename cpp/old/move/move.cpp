#include <iostream>

using std::cout;
using std::endl;

template<typename T>
void func(T& param) {
	cout << "���������ֵ0" << endl;
}


template<typename T>
void func(const T& param) {
	cout << "���������ֵ1" << endl;
}


template<typename T>
void func(T&& param) {
	cout << "���������ֵ" << endl;
}


template<typename T>
void warp(T&& param) {
	func(param);
}


int main() {
	const int num = 2019;
	warp(num);
	warp(2019);
	return 0;
}

