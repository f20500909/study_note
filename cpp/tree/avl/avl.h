#ifndef _MYHEAD_H
#define _MYHEAD_H
#include<vector>
class Node
{
public:
    int key = 0;
    int height = 0;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int key_t = 0)
    {
        key = key_t;
        height = 1;
        left = right = nullptr;
    }
};

class AVL
{
private:
    Node *header; //header结点并非根结点，header->left指向的才是根结点。

    Node *ll_rotate(Node *y);
    Node *rr_rotate(Node *y);
    Node *lr_rotate(Node *y);
    Node *rl_rotate(Node *y);



    int get_height(Node *node);
    int get_balance(Node *node);

    Node *insert_real(int key, Node *node);
    Node *&find_real(int key, Node *&node);

    Node *erase_real(int key, Node *node);



    int destory(Node *node);

public:
    AVL();
    ~AVL();
    void insert(int key);
    // (递归实现)查找"AVL"中键值为key的节点
    Node *find(int key);

    //(非递归实现)查找"AVL"中键值为key的节点
    Node *loop_find(int key);

    void erase(int key);
};
#endif
