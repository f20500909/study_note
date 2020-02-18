/*
* file name : sptestcase3.cpp
* desp : ����ָ����Դ��� case3 ��������ָ������ü�������
*/

#include <iostream>
#include "smartpointer.h"

/*�̳������ü��������SomeClass��*/
class SomeClass : public RefBase {
public:
	SomeClass() { std::cout << "SomeClass default constructor !" << std::endl; }
	~SomeClass() { std::cout << "SomeClass deconstructor !" << std::endl; }
};

void testcase3(void)
{
	SomeClass *pSomeClass = new SomeClass(); //1
	SmartPointer<SomeClass> spOuter = pSomeClass;
	std::cout << "SomeClass Ref Count (" << pSomeClass->getRefCount() << ") outer 1." << std::endl;
	{ // inner ����
		SmartPointer<SomeClass> spInner = spOuter;
		std::cout << "SomeClass Ref Count (" << pSomeClass->getRefCount() << ") inner." << std::endl;
	}
	std::cout << "SomeClass Ref Count (" << pSomeClass->getRefCount() << ") outer 2." << std::endl;
	// delete pSomeClass ; ����ҪҲ����ִ��delete����!

	std::cout << "new another SomeClass class for spOuter." << std::endl;
	SmartPointer<SomeClass> spOuter2 = new SomeClass();
	spOuter = spOuter2;// 1��new������SomeClass���ᱻ�Զ��ͷ�  
}

int main(void)
{
	testcase3();

	std::cin.get();
	return 0;
}
