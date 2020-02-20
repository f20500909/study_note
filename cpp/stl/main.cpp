#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <ctime>
#include <assert.h>
using namespace std;
const int EMPTY=0;//��δ������ݱ�־
const int REMOVE=-1;//����ɾ����־
typedef int KeyType;//�ؼ�������
#include "func.cpp"
#include "HashTable.h"
int main()
{
    HashTable<DATA> h;
    int i, j, n, p=0;
    bool m;
    DATA e;
    KeyType k;
    ifstream fin("test.txt");
    fin>>n;
    for(i=0; i<n; i++)
    {
        InputFromFile(fin, e);
        j=h.InsertHash(e);
        if(j==EXIST)
        {
            cout<<"��������Ҫ���Ѿ��������Ĺؼ��֣�2Kս��������"<<e.key<<"����ͼ�ٲ����Ϊ: ";
            Visit(e);
            cout<<endl;
        }
        if(j==UNSUCCESS)
            j=h.InsertHash(e);
    }
    fin.close();
    cout<<endl;
    cout<<"����ϣ��ַ��˳�������ϣ��"<<endl;
    h.TraverseHash(Visit);
    if(h.d_type==1)
    {
        cout<<"�������ɾ�����ǵĹؼ��֣�2Kս��������";
        InputKey(k);
        m=h.DeleteHash(k, e);
        if(m)
        {
            cout<<"�ɹ�ɾ����Ԫ��";
            Visit(e);
            cout<<endl;
        }
    }
    cout<<"��������������ǵĹؼ��֣�2Kս��������";
    InputKey(k);
    n=0;
    j=h.SearchHash(k, p, n);
    if(j==SUCCESS)
    {
        Visit(h.GetElem(p));
        cout<<endl;
    }
    else
        cout<<"δ�ҵ�"<<endl;
    if(h.d_type==1)
    {
        cout<<"�������ǣ���������������ǵĹؼ��֣�2Kս��������";
        InputKey(e.key);
        cout<<"��������������ǵ����֣�";
        cin>>e.star;
        j=h.InsertHash(e);
        cout<<j<<endl;
        cout<<endl;
        cout<<"����ϣ��ַ��˳�������ϣ��"<<endl;
        h.TraverseHash(Visit);
    }

    return 0;
}

