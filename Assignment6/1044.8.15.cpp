#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Block {
    Block * llink;
    int address;
    bool is_busy;
    int size;
    Block * rlink;
    Block(int address, int size): address(address), size(size), is_busy(0) {
        llink = this;
        rlink = this;
    }
    Block * insert(Block * xx) {
        if (!xx) {
            return NULL;
        }
        xx->llink = this;
        xx->rlink = this->rlink;
        this->rlink->llink = xx;
        this->rlink = xx;
        return xx;
    }
    bool is_left_free() {
        return llink->address + llink->size == address && !llink->is_busy;
    }
    bool is_right_free() {
        return address + size == rlink->address && !rlink->is_busy;
    }
    Block * merge_right() {
        if (!is_right_free()) {
            return this->rlink;
        }
        Block * new_right_block = rlink->rlink;
        size += rlink->size;
        delete rlink;
        this->rlink = new_right_block;
        new_right_block->llink = this;
        return this;
    }
};

int lowbound, highbound, cellsize;

int main() {
    int tag;
    Block * root = NULL;
    Block * cur = NULL;
    Block * ppp = NULL;
    cin >> lowbound >> highbound >> cellsize;
    for (int addr = lowbound; addr < highbound; addr += cellsize) {
        cin >> tag;
        if (tag == 0) {
            if (!root) {
                cur = new Block(addr, cellsize);
                root = cur;
            } else {
                cur = cur->insert(new Block(addr, cellsize));
            }
            cur = cur->llink->merge_right();
        }
    }
    if (root) {
        for (ppp = root; ppp->rlink != root; ppp = ppp->rlink) {
            cout << "0 " << ppp->address << " " << ppp->size << endl;
        }
        cout << "0 " << ppp->address << " " << ppp->size << endl;
    } else {
        cout << "0 0 0" << endl;
    }
    return 0;
}