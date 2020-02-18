/*-------------------------------------
*   ���ڣ�2015-03-31
*   ���ߣ�SJF0115
*   ��Ŀ: ʵ��string��
*   ��Դ���ٶ�
*   ���ͣ�
------------------------------------*/
#include <iostream>
#include <cstring>
using namespace std;

class String {
public:
	// Ĭ�Ϲ��캯��
	String(const char* str = NULL);
	// ���ƹ��캯��
	String(const String &str);
	// ��������
	~String();
	// �ַ�������
	String operator+(const String & str);
	// �ַ�����ֵ
	String & operator=(const String &str);
	// �ַ�����ֵ
	String & operator=(const char* str);
	// �ж��Ƿ��ַ������
	bool operator==(const String &str);
	// ��ȡ�ַ�������
	int length();
	// �����ַ���[start,start+n-1]
	String substr(int start, int n);
	// �������
	friend ostream & operator<<(ostream &o, const String &str);
private:
	char* data;
	int size;
};
// ���캯��
String::String(const char *str) {
	if (str == NULL) {
		data = new char[1];
		data[0] = '\0';
		size = 0;
	}//if
	else {
		size = strlen(str);
		data = new char[size + 1];
		strcpy(data, str);
	}//else
}
// ���ƹ��캯��
String::String(const String &str) {
	size = str.size;
	data = new char[size + 1];
	strcpy(data, str.data);
}
// ��������
String::~String() {
	delete[] data;
}
// �ַ�������
String String::operator+(const String &str) {
	String newStr;
	//�ͷ�ԭ�пռ�
	delete[] newStr.data;
	newStr.size = size + str.size;
	newStr.data = new char[newStr.size + 1];
	strcpy(newStr.data, data);
	strcpy(newStr.data + size, str.data);
	return newStr;
}
// �ַ�����ֵ
String & String::operator=(const String &str) {
	if (data == str.data) {
		return *this;
	}//if
	delete[] data;
	size = str.size;
	data = new char[size + 1];
	strcpy(data, str.data);
	return *this;
}
// �ַ�����ֵ
String& String::operator=(const char* str) {
	if (data == str) {
		return *this;
	}//if
	delete[] data;
	size = strlen(str);
	data = new char[size + 1];
	strcpy(data, str);
	return *this;
}
// �ж��Ƿ��ַ������
bool String::operator==(const String &str) {
	return strcmp(data, str.data) == 0;
}
// ��ȡ�ַ�������
int String::length() {
	return size;
}
// �����ַ���[start,start+n-1]
String String::substr(int start, int n) {
	String newStr;
	// �ͷ�ԭ���ڴ�
	delete[] newStr.data;
	// ���������ڴ�
	newStr.data = new char[n + 1];
	for (int i = 0; i < n; ++i) {
		newStr.data[i] = data[start + i];
	}//for
	newStr.data[n] = '\0';
	newStr.size = n;
	return newStr;
}
// �������
ostream & operator<<(ostream &o, const String &str) {
	o << str.data;
	return o;
}

int main() {
	String str1("hello ");
	String str2 = "world";
	String str3 = str1 + str2;
	cout << "str1->" << str1 << " size->" << str1.length() << endl;
	cout << "str2->" << str2 << " size->" << str2.length() << endl;
	cout << "str3->" << str3 << " size->" << str3.length() << endl;

	String str4("helloworld");
	if (str3 == str4) {
		cout << str3 << " �� " << str4 << " ��һ����" << endl;
	}//if
	else {
		cout << str3 << " �� " << str4 << " �ǲ�һ����" << endl;
	}

	cout << str3.substr(6, 5) << " size->" << str3.substr(6, 5).length() << endl;
	return 0;
}

