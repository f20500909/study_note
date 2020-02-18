#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define UNSUCCESS 0
#define OVERFLOW -1
#define OK 1
#define ERROR -1

typedef int Status;
typedef int KeyType;

typedef struct
{
    KeyType key;
} RcdType;

typedef struct
{
    RcdType *rcd;
    int size;
    int count;
    int *tag;
} HashTable;

int hashsize[] = {11, 31, 61, 127, 251, 503};
int index = 0;

Status InitHashTable(HashTable &H, int size)
{
    int i;
    H.rcd = (RcdType *)malloc(sizeof(RcdType) * size);
    H.tag = (int *)malloc(sizeof(int) * size);
    if (NULL == H.rcd || NULL == H.tag)
        return OVERFLOW;
    for (i = 0; i < size; i++)
        H.tag[i] = 0;
    H.size = size;
    H.count = 0;
    return OK;
}

int Hash(KeyType key, int m)
{
    return (3 * key) % m;
}

void collision(int &p, int m)
{ //����̽��
    p = (p + 1) % m;
}

Status SearchHash(HashTable H, KeyType key, int &p, int &c)
{
    p = Hash(key, H.size);
    int h = p;
    c = 0;
    while ((1 == H.tag[p] && H.rcd[p].key != key) || -1 == H.tag[p])
    {
        collision(p, H.size);
        c++;
    }

    if (1 == H.tag[p] && key == H.rcd[p].key)
        return SUCCESS;
    else
        return UNSUCCESS;
}

void printHash(HashTable H) //��ӡ��ϣ��
{
    int i;
    printf("key : ");
    for (i = 0; i < H.size; i++)
        printf("%3d ", H.rcd[i].key);
    printf("\n");
    printf("tag : ");
    for (i = 0; i < H.size; i++)
        printf("%3d ", H.tag[i]);
    printf("\n\n");
}

Status InsertHash(HashTable &H, KeyType key); //�Ժ���������

//�ع�
Status recreateHash(HashTable &H)
{
    RcdType *orcd;
    int *otag, osize, i;
    orcd = H.rcd;
    otag = H.tag;
    osize = H.size;

    InitHashTable(H, hashsize[index++]);
    //������Ԫ�أ������¹�ϣ�����ŵ��±���
    for (i = 0; i < osize; i++)
    {
        if (1 == otag[i])
        {
            InsertHash(H, orcd[i].key);
        }
    }
    return 0;
}

Status InsertHash(HashTable &H, KeyType key)
{
    int p, c;
    if (UNSUCCESS == SearchHash(H, key, p, c))
    { //û����ͬkey
        if (c * 1.0 / H.size < 0.5)
        { //��ͻ����δ�ﵽ����
            //�������
            H.rcd[p].key = key;
            H.tag[p] = 1;
            H.count++;
            return SUCCESS;
        }
        else
            recreateHash(H); //�ع���ϣ��
    }
    return UNSUCCESS;
}

Status DeleteHash(HashTable &H, KeyType key)
{
    int p, c;
    if (SUCCESS == SearchHash(H, key, p, c))
    {
        //ɾ������
        H.tag[p] = -1;
        H.count--;

        return SUCCESS;
    }
    else
        return UNSUCCESS;
}

int main()
{
    printf("-----��ϣ��-----\n");
    HashTable H;
    int i;
    int size = 11;
    KeyType array[8] = {22, 41, 53, 46, 30, 13, 12, 67};
    KeyType key;
    RcdType e;

    //��ʼ����ϣ��
    printf("��ʼ����ϣ��\n");
    if (SUCCESS == InitHashTable(H, hashsize[index++]))
        printf("��ʼ���ɹ�\n");

    //�����ϣ��
    printf("�����ϣ��\n");
    for (i = 0; i <= 7; i++)
    {
        key = array[i];
        InsertHash(H, key);
        printHash(H);
    }

    //ɾ����ϣ��
    printf("ɾ����ϣ��\n");
    int p, c;
    if (SUCCESS == DeleteHash(H, 12))
    {
        printf("ɾ���ɹ�����ʱ��ϣ��Ϊ��\n");
        printHash(H);
    }

    //��ѯ��ϣ��
    printf("��ѯ��ϣ��\n");
    if (SUCCESS == SearchHash(H, 67, p, c))
        printf("��ѯ�ɹ�\n");

    //�ٴβ��룬���Թ�ϣ����ع�
    printf("�ٴβ��룬���Թ�ϣ����ع���\n");
    KeyType array1[8] = {27, 47, 57, 47, 37, 17, 93, 67};
    for (i = 0; i <= 7; i++)
    {
        key = array1[i];
        InsertHash(H, key);
        printHash(H);
    }
    return 0;
}
