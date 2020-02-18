#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>

using namespace std;
using namespace stdext;

class LRUCache {
private:
    int cap;
    // ˫����װ�� (key, value) Ԫ��
    list<pair<int, int>> cache;
    // ��ϣ��key ӳ�䵽 (key, value) �� cache �е�λ��
    unordered_map<int, list<pair<int, int>>::iterator> map;
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }

    int get(int key) {
        auto it = map.find(key);
        // ���ʵ� key ������
        if (it == map.end()) return -1;
        // key ���ڣ��� (k, v) ������ͷ
        pair<int, int> kv = *map[key];
        cache.erase(map[key]);
        cache.push_front(kv);
        // ���� (key, value) �� cache �е�λ��
        map[key] = cache.begin();
        return kv.second; // value
    }

    void put(int key, int value) {
        /* Ҫ���ж� key �Ƿ��Ѿ����� */
        auto it = map.find(key);
        if (it == map.end()) {
            /* key �����ڣ��ж� cache �Ƿ����� */
            if (cache.size() == cap) {
                // cache ������ɾ��β���ļ�ֵ����λ��
                // cache �� map �е����ݶ�Ҫɾ��
                auto lastPair = cache.back();
                int lastKey = lastPair.first;
                map.erase(lastKey);
                cache.pop_back();
            }
            // cache û��������ֱ�����
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        } else {
            /* key ���ڣ����� value ��������ͷ */
            cache.erase(map[key]);
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        }
    }

};


int main(int argc, char **argv) {
    LRUCache s(2);
    s.put(2, 2222222);
    s.put(1, 11111111);
    cout << s.get(2) << endl;
    s.put(4, 44444444);
    s.put(5, 22222222);
    cout << s.get(5) << endl;
    cout << s.get(4) << endl;
    return 0;
}
