/*����˳����У���ν���������*/

#include <iostream>
#include <queue>
using namespace std;
#define MAXSIZE 100
typedef struct Node* Btree;
struct Node   //�������ݽṹ
{
	int data;
	Node *lchild, *rchild;
};

struct queue  //���е����ݽṹ
{
	Btree *data[MAXSIZE];
	int front, rear;
};

 

Btree creatbintree()
{
	//1.�Ƚ����ڵ���ӣ������в�Ϊ��ʱ��ѭ��ִ�����²�����
	//2.������������ֵ����Ϊ�գ��������
	//3.������������ֵ����Ϊ�գ��������
	int a;
	Btree root;
	std::queue<Btree> q;
	cout << "������ڵ�ֵ��-1��ʾ�սڵ㣺" << endl;
	cin >> a;
	if (a == -1)    //�����һ���ڵ�Ϊ�գ���ֱ�ӷ��ؿ���
		return NULL;
	else
	{
		root = new Node();
		root->data = a;
		q.push(root);  //���ڵ����
	}
	while (q.size()>0)   //�����в�Ϊ��
	{
		//���������ӵ�ֵ���������Һ��ӵ�ֵ
		Btree p = new Node();
		cin >> a;
		if (a == -1)   //����Ϊ��
			p->lchild = NULL;
		else
		{
			p->lchild = new Node();
			p->lchild->data = a;
			q.push(p);
		}
		cin >> a;
		if (a == -1)   //�Һ���Ϊ��
			p->rchild = NULL;
		else
		{
			p->rchild = new Node();
			p->rchild->data = a;
			q.push(p);
		}

	}
	return root;
}

void showbintree(Btree root)
{
	//1.�Ƚ����ڵ���ӣ������в�Ϊ��ʱ��ѭ��ִ�����²�����
	//2.����һ��Ԫ�أ�������
	//3.����������Ϊ�գ��������
	//4.����������Ϊ�գ��������
	std::queue<Btree> Q;
	Btree p;
	if (root == NULL)
		return;
	Q.push(p);
	while (Q.size()>0)
	{
		p = Q.front();
		cout << p->data << ' ';
		if (p->lchild)
			Q.push(p);
		if (p->rchild)
			Q.push(p);
	}
	cout << endl;
}

int main()
{
	Btree root = NULL;
	root = creatbintree();
	showbintree(root);
	cin.get();
	return 0;
}

