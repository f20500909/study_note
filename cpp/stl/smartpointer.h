/*
* file name : smartpointer.h
* desp : ����ָ��汾v3
*/
#ifndef __SMARTPOINTER_H__
#define __SMARTPOINTER_H__

template <typename T>  // ������ָ���ඨ���ģ����
class SmartPointer {
public:
	// Ĭ�Ϲ��캯��
	SmartPointer() :mPointer(NULL) { std::cout << "Create null smart pointer." << std::endl; }
	// ���ղ�ͬ�������͵Ĺ��캯��
	SmartPointer(T *p) :mPointer(p) {
		std::cout << "Create smart pointer at " << static_cast<const void*>(p) << std::endl;
		/*����ָ��ָ����T�����ü�����1*/
		if (mPointer) mPointer->incRefCount();
	}
	// ��������
	~SmartPointer() {
		std::cout << "Release smart pointer at " << static_cast<const void*>(mPointer) << std::endl;
		// ʵ���ڴ���Դ�Զ����ٻ���
		if (mPointer && mPointer->decRefCount() == 0) delete mPointer;
	}
	// �������캯��
	SmartPointer(const SmartPointer &other) :mPointer(other.mPointer) {
		std::cout << "Copy smart pointer at " << static_cast<const void*>(other.mPointer) << std::endl;
		// ���ü�����1
		if (mPointer) mPointer->incRefCount();
	}
	// ��ֵ������         
	SmartPointer &operator = (const SmartPointer &other) {
		T *temp(other.mPointer);
		// ��ָ��������ü���ֵ��1
		if (temp) temp->incRefCount();
		// ԭָ��������ü���ֵ��1�������1�����ü���Ϊ0 ����ԭ��Դ����
		if (mPointer && mPointer->decRefCount() == 0) delete mPointer;
		// ����ָ��ָ������Դ����
		mPointer = temp;
		return *this;
	}

private:
	T *mPointer; // ָ������ָ��ʵ�ʶ�Ӧ���ڴ���Դ�����ݲ����Զ��Ƶ����򣬶����ڲ���Դָ������
};

/*���ü�������*/
class RefBase
{
public:
	RefBase() : mCount(0) { }
	void incRefCount() {
		mCount++;
	}
	int decRefCount() {
		return --mCount;
	}
	// ���Խӿڣ����ض���ǰ���ü���   
	int getRefCount() {
		return mCount;
	}
	virtual ~RefBase() { }
private:
	int mCount;
};
#endif // __SMARTPOINTER_H__

