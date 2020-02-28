#include <iostream>
#include <cassert>
#include <memory>
#include <ostream>
#include <memory.h>
#include <bitset>

class BitMap {
public:
    BitMap() {
        data = NULL;
        size = 0;
    }

    BitMap(int size) { // contractor, init the data
        data = NULL;
        data = new char[size / 8];
        assert(data);
        memset(data, 0x0, size * sizeof(char));
        this->size = size;
    }


    bool set(int index, bool status) {
        if (status) {
            return setTrue(index);
        } else {

            return setFalse(index);
        }
    }


    int setTrue(int index) {
        int addr = index / 8;
        int addroffset = index % 8;
        unsigned char temp = 0x1 << addroffset;
        if (addr > (size + 1)) {
            return 0;
        } else {
            data[addr] |= temp;
            return 1;
        }
    }

    bool set(int charId, int bitId, bool status) {
        int index = charId * 8 + bitId;
        return set(index, status);
    }


    bool get(int index) {
        int addr = index / 8;
        int addroffset = index % 8;
        unsigned char temp = 0x1 << addroffset;
        if (addr > (size + 1)) {
            return 0;
        } else {
            return (data[addr] & temp) > 0 ? 1 : 0;
        }
    }


    int setFalse(int index) {
        if (get(index) == 0) {
            return 0;
        }
        int addr = index / 8;
        int addroffset = index % 8;
        unsigned char temp = 0x1 << addroffset;
        if (addr > (size + 1)) {
            return 0;
        } else {
            data[addr] ^= temp;
            return 1;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const BitMap m) {
        int cnt = 0;
        while (m.data[cnt] != '\0') {
            os << std::bitset<8>(m.data[cnt]);
        }

        os << std::endl;
        return os;
    }


private:
    char *data;
    int size;
};


int main() {

    BitMap m(1024);


    return 0;
}
