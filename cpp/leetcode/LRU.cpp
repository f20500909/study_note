#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    int cap;    // 总容量
    int count;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> list;

public:
    LRUCache(int capacity) {
        cap = capacity;
        count = 0;
    }

    int get(int key) {
        int res = -1;
        auto p = m.find(key); //在红黑树中查找key
        if (p != m.end()) {   //如果没找到
            res = p->second->second;  // p   [ key    [ ]   ]
            list.erase(p->second);    //链表中删除改节点
            list.push_front(make_pair(key, res));
            p->second = list.begin();
        }
        return res;
    }

    void put(int key, int value) {
        auto p = m.find(key);
        if (p != m.end()) {
            list.erase(p->second);
        } else if (count == cap) {
            int delkey = list.back().first;
            list.pop_back();
            m.erase(delkey);
        } else {
            ++count;
        }
        list.push_front(make_pair(key, value));
        m[key] = list.begin();
    }


};


int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << cache.get(1) << endl;       // 返回  1
    cache.put(3, 3);    // 该操作会使得密钥 2 作废

    std::cout << cache.get(2) << endl;       // 返回  1
    cache.put(4, 4);    // 该操作会使得密钥 1 作废


    std::cout << cache.get(1) << endl;       // 返回  1
    std::cout << cache.get(2) << endl;       // 返回  1
    std::cout << cache.get(2) << endl;       // 返回  1


    cache.get(1);       // 返回 -1 (未找到)
    cache.get(3);       // 返回  3
    cache.get(4);       // 返回  4

    return 0;
}


