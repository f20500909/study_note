#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>

using namespace std;
typedef int ElemType;

class BTNode   //Binary Tree Node
{
public:
    ElemType data;
    BTNode *lchild;   //����
    BTNode *rchild;   //�Һ���
    BTNode(ElemType d, BTNode *left = NULL, BTNode *right = NULL) : data(d), lchild(left), rchild(right) {}
};

class BinarySearchTree {
private:
    BTNode *Root;
    int size;
public:
    BinarySearchTree(int *arr, int len);

    ~BinarySearchTree();

    bool empty() { return Root == NULL; }

    int getSize() { return size; }

    int leaf();

    bool search(ElemType);

    BTNode *parent(ElemType);

    BTNode *predecessor(ElemType);

    //��ȡ���
    BTNode *successor(ElemType);

    BTNode *minimum();

    BTNode *maximum();

    bool insertNode(ElemType);

    bool deleteNode(ElemType);

    void traverse() { inOrderWithoutRecursion(); }

    void inOrderWithoutRecursion();
};

//���췽��
BinarySearchTree::BinarySearchTree(int *arr, int len) {
    size = 0;
    Root = NULL;
    ElemType data;
    for (int i = 0; i < len; i++) {
        insertNode(arr[i]);
    }
}

//��������
BinarySearchTree::~BinarySearchTree() {
    if (!empty()) {
        queue<BTNode *> q;
        q.push(Root);
        BTNode *p = NULL;
        while (!q.empty()) {
            p = q.front();
            q.pop();
            //���Ӳ�Ϊ�գ����������
            if (p->lchild)
                q.push(p->lchild);
            //�Һ��Ӳ�Ϊ�գ����Һ������
            if (p->rchild)
                q.push(p->rchild);
            //�ͷ��ڴ�
            delete p;
        }
    }
}

//��Ҷ�ӽڵ���
int BinarySearchTree::leaf() {
    int num = 0;
    //���������
    if (!empty()) {
        stack<BTNode *> s;
        BTNode *p = Root;
        while (!s.empty() || p) {
            if (p) {
                s.push(p);
                p = p->lchild;
            } else {
                p = s.top();
                s.pop();
                //����������Ϊ�գ���ΪҶ�ӽڵ�
                if (p->lchild == NULL && p->rchild == NULL)
                    num++;
                p = p->rchild;
            }
        }
    }
    return num;
}

//����
bool BinarySearchTree::search(ElemType data) {
    if (!empty()) {
        BTNode *p = Root;
        while (p) {
            if (data == p->data)
                return true;
            else if (data < p->data)
                p = p->lchild;
            else
                p = p->rchild;
        }
    }
    //���ջ����ʧ��
    return false;
}

BTNode *BinarySearchTree::parent(ElemType data) {
    if (!empty()) {
        //���ڵ�ĸ��ڵ�Ϊ��
        if (Root->data == data)
            return NULL;
        stack<BTNode *> s;
        BTNode *p = Root;
        while (!s.empty() || p) {
            if (p) {
                if ((p->lchild && p->lchild->data == data) || (p->rchild && p->rchild->data == data))
                    return p;
                s.push(p);
                p = p->lchild;
            } else {//������������󣬷���������
                p = s.top();
                s.pop();
                p = p->rchild;
            }
        }
    }
    return NULL;
}

//��ȡǰ��
BTNode *BinarySearchTree::predecessor(ElemType data) {
    BTNode *pcur, *plastVisit;
    pcur = plastVisit = NULL;
    if (!empty()) {
        stack<BTNode *> s;
        pcur = Root;
        while (!s.empty() || pcur) {
            if (pcur) {
                //plastVisit = pcur;
                s.push(pcur);
                pcur = pcur->lchild;
            } else {
                pcur = s.top();
                s.pop();
                if (pcur->data == data)
                    return plastVisit;
                else
                    plastVisit = pcur;
                pcur = pcur->rchild;
            }
        }
    }
    return plastVisit;
}

//��ȡ���
BTNode *BinarySearchTree::successor(ElemType data) {
    BTNode *pcur = NULL;
    pcur = Root;
    if (!empty()) {
        stack<BTNode *> s;
        while (!s.empty() || pcur) {
            if (pcur) {
                s.push(pcur);
                pcur = pcur->lchild;
            } else {
                pcur = s.top();
                s.pop();
                if (pcur->data == data)
                    return pcur->rchild;
                pcur = pcur->rchild;
            }
        }
    }
    //����
    return NULL;
}

//��ȡ��С�ڵ�
BTNode *BinarySearchTree::minimum() {
    //��С�ڵ������������±�
    if (!empty()) {
        BTNode *p = Root;
        while (p->lchild)
            p = p->lchild;
        return p;
    }
    //����
    return NULL;
}

//��ȡ���ڵ�
BTNode *BinarySearchTree::maximum() {
    //���ڵ������������±�
    if (!empty()) {
        BTNode *p = Root;
        while (p->rchild)
            p = p->rchild;
        return p;
    }
    //����
    return NULL;
}

//�����½ڵ�
bool BinarySearchTree::insertNode(ElemType data) {
    /*
     �½ڵ㶼�ᱻ���뵽Ҷ�Ӵ�
     ����һ�㲻��ʧ�ܣ������ǲ������ظ��ڵ㡣
    */
    if (Root == NULL) {
        Root = new BTNode(data);
        size++;
        return true;
    } else {
        BTNode *p = Root;
        while (true) {
            if (data < p->data) {
                //����������������������������
                if (p->lchild)
                    p = p->lchild;
                else {//���򣬲���ڵ㣬��ͬ
                    p->lchild = new BTNode(data);
                    break;
                }
            } else if (data > p->data) {
                if (p->rchild)
                    p = p->rchild;
                else {
                    p->rchild = new BTNode(data);
                    break;
                }
            } else//�����ظ��ڵ�
                return false;
        }
        //�����½ڵ�ɹ����ڵ�������һ
        size++;
        return true;
    }
}

//ɾ���ڵ�
bool BinarySearchTree::deleteNode(ElemType data) {
    /*
    ɾ������
    1.����ɾ�ڵ������������������������ĸ��ڵ��滻����
    2.����ɾ�ڵ�����������������������Ѱ��������������һ���ڵ㣬�øýڵ��滻����
    */
    if (!empty()) {
        //�����޴˽ڵ㣬ɾ��ʧ��
        if (!search(data))
            return false;
        /*
        p:��ɾ���
        Parent:��ɾ���ڵ�ĸ��ڵ�
        temp:�滻�ڵ�
        tempp:�滻�ڵ�ĸ��ڵ�
        */
        BTNode *p, *Parent, *temp, *tempp;
        p = Parent = temp = tempp = NULL;
        //��ȡ��ɾ���ڵ�ĸ��ڵ�
        Parent = parent(data);
        //���ݸ��ڵ㣬ȷ����ɾ���
        if (Parent->lchild && Parent->lchild->data == data)
            p = Parent->lchild;
        else
            p = Parent->rchild;
        //�����������Ϊ�գ�������������������һ���ڵ�
        if (p->lchild) {
            temp = p->lchild;
            while (temp->rchild) {
                tempp = temp;
                //���ϱ���������
                temp = temp->rchild;
            }
            //���p�����Ӽ����滻�ڵ�
            if (tempp == NULL)
                p->lchild = temp->lchild;
            else//�滻�ڵ����������Ϊ�丸�ڵ��������(���������⣬��Ҫ������)
                tempp->rchild = temp->lchild;
            //�滻�ڵ�̳д�ɾ�������Һ���
            temp->lchild = p->lchild;
            temp->rchild = p->rchild;
        } else
            temp = p->rchild;
        //�滻�ڵ��滻����ɾ���(��Ҳ��Ϊʲô��Ҫ�ҵ���ɾ���ĸ��ڵ�)
        if (Parent == NULL)  //��ɾ���ǡΪ���ڵ�
            Root = temp;
        else if (Parent->lchild == p)  //��ɾ��㱾����������
            Parent->lchild = temp;
        else//��ɾ��㱾����������
            Parent->rchild = temp;
        //ɾ����ɾ���
        delete p;
        //�ڵ�������һ
        size--;
        return true;
    }
    //����
    return false;
}

//�������
void BinarySearchTree::inOrderWithoutRecursion() {
    if (!empty()) {
        stack<BTNode *> s;
        BTNode *p = Root;
        while (!s.empty() || p) {
            if (p) {
                s.push(p);
                p = p->lchild;
            } else {
                p = s.top();
                s.pop();
                cout << setw(4) << p->data;
                p = p->rchild;
            }
        }
        cout << endl;
    }
}

int main() {
    cout << "******����������***by David***" << endl;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    BinarySearchTree tree(arr, 9);
    cout << "�������" << endl;
    tree.traverse();
    cout << "���нڵ����� " << tree.getSize() << endl;
    cout << "Ҷ�ӽڵ��� " << tree.leaf() << endl;
    BTNode *p = NULL;
    p = tree.minimum();
    p ? cout << "��С�ڵ��� " << p->data << endl : cout << "���գ�" << endl;
    p = tree.maximum();
    p ? cout << "���ڵ��� " << p->data << endl : cout << "���գ�" << endl;
    ElemType data = 2;
    cout << endl << "���ҽڵ� " << data << endl;
    if (tree.search(data)) {
        cout << "�ڵ� " << data << " ���ҳɹ���" << endl;
        p = tree.predecessor(data);
        p ? cout << "�ڵ� " << data << " ��ǰ���� " << p->data << endl : cout << "��ǰ����" << endl;
        p = tree.successor(data);
        p ? cout << "�ڵ� " << data << " �ĺ���� " << p->data << endl : cout << "�޺�̣�" << endl;
    } else
        cout << "�ڵ� " << data << "�������У�" << endl;
    data = 6;
    cout << endl << "ɾ���ڵ� " << data << endl;
    if (tree.deleteNode(data)) {
        cout << "ɾ���ɹ���" << endl;
        cout << "�������" << endl;
        tree.traverse();
        cout << "���нڵ����� " << tree.getSize() << endl;
        cout << "Ҷ�ӽڵ��� " << tree.leaf() << endl;
        data = 5;
        cout << endl << "���ҽڵ� " << data << endl;
        if (tree.search(data)) {
            cout << "�ڵ� " << data << " ���ҳɹ���" << endl;
            p = tree.predecessor(data);
            p ? cout << "�ڵ� " << data << " ��ǰ���� " << p->data << endl : cout << "��ǰ����" << endl;
            p = tree.successor(data);
            p ? cout << "�ڵ� " << data << " �ĺ���� " << p->data << endl : cout << "�޺�̣�" << endl;
        } else
            cout << "�ڵ� " << data << "�������У�" << endl;
    } else
        cout << "ɾ��ʧ�ܣ�" << endl;
    cout << endl;
    system("pause");
    return 0;
}


