#include <iostream>
using namespace std;

class Job_A {
public:
    Job_A() {}

    void doIt() {
        cout << "买苹果..." << endl;
    }
};

class Job_B {
public:
    Job_B() {}

    void doIt() {
        cout << "买桃子..." << endl;
    }
};

class Job_C {
public:
    Job_C() {}

    void doIt() {
        cout << "买香蕉..." << endl;
    }
};

class Worker {
public:
    Worker() {
        p_a = new Job_A;
        p_b = new Job_B;
        p_c = new Job_C;
    }

    ~Worker() {
        delete p_a;
        delete p_b;
        delete p_c;
    }

    void do_a() {
        p_a->doIt();
    }

    void do_b() {
        p_b->doIt();
    }

    void do_c() {
        p_c->doIt();
    }

    void doAll(){
        cout << ".........全部都开始做........." << endl;
        p_a->doIt();
        p_b->doIt();
        p_c->doIt();
        cout << ".........全部都做完了........." << endl;
    }

public:
    Job_A *p_a;
    Job_B *p_b;
    Job_C *p_c;
};


int main34() {
    Worker* work=new Worker();
    work->do_a();
    work->do_b();
    work->do_c();

    work->doAll();
    return 0;
}