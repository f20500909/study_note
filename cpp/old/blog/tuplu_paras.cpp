#include <iostream>
#include <string>
#include <tuple>

using namespace std;


tuple<int, int> foo() {
    return make_tuple(1, 2);
}

tuple<int, char, string> foo(int k) {
    return make_tuple(1, '0', "para_3");
}

int main() {
    tuple<int, int> data = foo();
    cout << "the first para is " << get<0>(data) << endl;
    cout << "the second para is " << get<1>(data) << endl;


    cout << "======================== " << endl;

    auto data_1 = foo(3);
    cout << "the first para is " << get<0>(data_1) << endl;
    cout << "the second para is " << get<1>(data_1) << endl;
    cout << "the third para is " << get<2>(data_1) << endl;

    return 0;
}
