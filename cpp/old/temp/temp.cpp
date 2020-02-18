#include <iostream>
#include <list>
using namespace std;

int main(){
    char a[] = "abc";
    char a2[] = "abc";
    char *b = "abc";
    char c[] = {'a', 'b', 'c'};
    if(a==b) cout<<"a==b";
    if(a==c) cout<<"a==c";
    if(b==c) cout<<"b==c";
    if(a==a2) cout<<"a==a2";
    cout<<"==";


    return 0;
}

