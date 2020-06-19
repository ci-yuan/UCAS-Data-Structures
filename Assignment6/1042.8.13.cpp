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
    // void merge_left() {
    //     if (!is_left_free()) {
    //         return;
    //     }
    //     Block * new_left_block = llink->llink;
    //     address = llink->address;
    //     size += llink->size;
    //     delete llink;
    //     this->llink = new_left_block;
    //     new_left_block->rlink = this;
    // }
    Block * merge_right() {
        if (!is_right_free()) {
            return this;
        }
        Block * new_right_block = rlink->rlink;
        size += rlink->size;
        delete rlink;
        this->rlink = new_right_block;
        new_right_block->llink = this;
        return this;
    }
};

int main() {
    int tag, addr, size;
    Block * root = NULL;
    Block * cur = NULL;
    Block * ppp = NULL;
    while (cin >> tag >> addr >> size) {
        if (tag) {
            for (cur = root; cur->rlink != root; cur = cur->rlink) {
                if (cur->address < addr && addr < cur->rlink->address) {
                    break;
                }
            }
        }
        if (!root) {
            cur = new Block(addr, size);
            root = cur;
        } else {
            cur = cur->insert(new Block(addr, size));
        }
        // cur->merge_left();
        if (tag) {
            cur = cur->merge_right();
            cur = cur->llink->merge_right();
        }
        // cout << "!!!!!!all!!!!!!" << endl;
        // for (ppp = root; ppp->rlink != root; ppp = ppp->rlink) {
        //     cout << "0 " << ppp->address << " " << ppp->size << endl;
        // }
        // cout << "0 " << ppp->address << " " << ppp->size << endl;
        // cout << "!!!!!!all!!!!!!" << endl;
    }
    for (ppp = root; ppp->rlink != root; ppp = ppp->rlink) {
        cout << "0 " << ppp->address << " " << ppp->size << endl;
    }
    cout << "0 " << ppp->address << " " << ppp->size << endl;
    return 0;
}