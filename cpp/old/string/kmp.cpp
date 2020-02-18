#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getNext(string T) {
    int len = T.size();
    vector<int> next(len, 0);
    int k = 0;
    next[0] = -1;
    for (int i = 2; i < len; i++) {
        while (k > 0 && T[i - 1] != T[k]) k = next[k];
        if (T[i - 1] == T[k]) k++;
        next[i] = k;
    }
    return next;
}


void print(vector<int> &vec) {
    for (auto v:vec) {
        cout << v << " ";
    }
    cout << endl;
}


int kmp(char* s, char* t) {
    vector<int> next = getNext(t);
    print(next);
    int i = 0;
    int j = 0;
    while (s[i] != '\0' && t[j] != '\0') {
        if (s[i] == t[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
        if (j == -1) {
            i++;
            j++;
        }
    }
    if (t[j] == '\0') return i - j;
    return -1;
}


int main1() {
    char *S = "ababaababcbdfsdf4rsdfs";
    char *T = "babcbdf";
    int num = kmp(S, T);
    cout << num;
    return 0;
}