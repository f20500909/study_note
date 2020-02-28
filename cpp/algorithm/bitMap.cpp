#include <iostream>
#include <cassert>
#include <memory>
#include <ostream>
#include <memory.h>
#include <bitset>

class BitMap {
public:
    BitMap() {
        data = nullptr;
        size = 0;
    }

    BitMap(int size) : size(size), charSize(size / 8) { // contractor, init the data
        data = new char[charSize];
        assert(data);
        memset(data, 0x0, charSize * sizeof(char));
    }

    ~BitMap() {
        delete[] data;
    }

    void set(int index, bool status) {
        if (status) {
            setTrue(index);
        } else {
            setFalse(index);
        }
    }

    void setTrue(int index) {
        int addr = index / 8;
        int addroffset = index % 8;
        unsigned char temp = 0x1 << (7 - addroffset);
        assert (addr <= charSize + 1);
        data[addr] |= temp;
    }

    void set(int charId, int bitId, bool status) {
        int index = charId * 8 + bitId;
        set(index, status);
    }

    bool get(int charId, int bitId) {
        int index = charId * 8 + bitId;
        return get(index);
    }

    bool get(int index) {
        int addr = index / 8;
        int addroffset = index % 8;
        unsigned char temp = 0x1 << (7 - addroffset);
        assert(addr <= charSize);
        return (data[addr] & temp) > 0 ? 1 : 0;
    }

    void setFalse(int index) {
        if (get(index) == 0) {
            return;
        }
        int addr = index / 8;
        int addroffset = index % 8;
        unsigned char temp = 0x1 << (7 - addroffset);
        assert(addr <= charSize);
        data[addr] ^= temp;
        return;
    }

    friend std::ostream &operator<<(std::ostream &os, const BitMap &map) {
        for (int i = 0; i < map.charSize; i++) {
            os << std::bitset<8>(map.data[i]) << " ";
        }
        os << std::endl;
        return os;
    }


private:
    char *data;
    int charSize;
    int size;
};


int main() {

    BitMap m(64);
    m.set(0, 1);
    m.set(1, 1, 1);
    m.set(2, 3, 1);
    std::cout << m << std::endl;
    std::cout << m.get(0) << std::endl;
    std::cout << m.get(9) << std::endl;
    std::cout << m.get(19) << std::endl;
    std::cout << m.get(2,3) << std::endl;
    std::cout << m.get(20) << std::endl;
    std::cout << m << std::endl;
    return 0;
}
