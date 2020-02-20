#include <iostream>
#include <stddef.h>

using namespace std;

//class Singleton {
//private:
//    static Singleton *instance;    //静态单例指针
//    Singleton();    //构造函数声明为私有
//public:
//    static Singleton *getInstance();    //公共接口用于获取单例对象（也可以直接把定义放在这边）
//};


class Singleton {
private:
    static Singleton *instance;

    Singleton() {
        cout << "Singleton begin ~" << endl;
    }

public:
    static Singleton *getInstance();
};

Singleton *Singleton::getInstance() {
    return instance;
}

Singleton *Singleton::instance = new Singleton();



//Singleton::Singleton() {
//    std::cout << "Create a Singleton" << std::endl;
//}
//
//Singleton *Singleton::getInstance() {
//    return instance;    //返回本类的单例（在14行创建的）
//}
//
////饿汉模式
//Singleton *Singleton::instance = new Singleton();    //饿汉模式在类定义处构建单例（这里是类外）



int main() {
    std::cout << "Enter main" << std::endl;    //这里主函数开始
    Singleton *test1 = Singleton::getInstance();    //通过公共接口获取单例对象
    Singleton *test2 = Singleton::getInstance();    //通过公共接口获取单例对象
    if (test1 == test2)    //判断获取到的单例是否是同一个，从而判断单例对象是否唯一
    {
        std::cout << "This is a real Singleton!" << std::endl;
    } else {
        std::cout << "Fake Singleton?" << std::endl;
    }
    std::cout << "End" << std::endl;
    return 0;
}
