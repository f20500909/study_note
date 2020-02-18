#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
};
void print(ListNode* pHead) {
	ListNode* _p = pHead;
	while (_p != NULL) {
		cout << _p->val<<"  ";
		_p = _p->next;
	}
	cout << endl;

}
ListNode* initListNode(vector<int>& vec) {
	ListNode* demo=new ListNode();
	demo->val = 0;
	demo->next = NULL;
	ListNode* p = demo;
	for (int i = 0; i < vec.size(); i++) {
			ListNode* pNewNode = new ListNode;
			pNewNode->val = vec[i]; // ���½ڵ��ֵ��ֵΪi
			pNewNode->next = NULL;
			p->next = pNewNode; // ��һ���ڵ�ָ������½����Ľڵ�
			p = p->next;
	}
	return demo;
}

ListNode* ReverseList(ListNode* pHead) {
	ListNode* res=NULL;
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;
	while (pNode != NULL) {
		ListNode* pNext = pNode->next;//�ȼ�¼��ǰ�ڵ����һ���ڵ�
		if (pNext == NULL)
			res = pNode;

		pNode->next = pPrev; //����һ���ڵ����ǰһ���ڵ�
		pPrev = pNode;//��ǰ�ڵ���ڵ�ǰ�ڵ�
		pNode = pNext;//ָ����һ���ڵ�
	}
	return res;
}

int main() {
	vector<int> vec = { 1,2,3,4,5 };
	ListNode* demo=initListNode(vec);
	print(demo);
	ListNode* res = ReverseList(demo);
	print(res);

	cin.get();

	return 0;
}