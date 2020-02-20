#include <iostream>

using namespace std;

int main() {
    int nNum = 0x12345678;
    char chData = *(char *) (&nNum);

    if (chData == 0x12) {
        cout << "big" << endl;
    } else {
        cout << "small" << endl;
    }
    return 0;
}
