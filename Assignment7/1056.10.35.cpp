#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

class Heap {
public:
    int tree[110];
    int len;
    static int father(int pos) {
        return (pos + 1) / 3;
    }
    static int son1(int pos) {
        return pos * 3 - 1;
    }
    static int son2(int pos) {
        return pos * 3;
    }
    static int son3(int pos) {
        return pos * 3 + 1;
    }
    void up_update(int pos) {
        for (; pos > 1; pos /= 3) {
            if (tree[father(pos)] >= tree[pos]) {
                break;
            }
            swap(tree[father(pos)], tree[pos]);
        }
    }
    void down_update(int pos) {
        for (pos = son1(pos); pos <= len; pos = son1(pos)) {
            int new_pos = pos;
            if (pos + 1 <= len && tree[pos + 1] >= tree[new_pos]) {
                new_pos = pos + 1;
            }
            if (pos + 2 <= len && tree[pos + 2] >= tree[new_pos]) {
                new_pos = pos + 2;
            }
            pos = new_pos;
            if (tree[father(pos)] >= tree[pos]) {
                break;
            }
            swap(tree[father(pos)], tree[pos]);
        }
    }
    Heap() {
        len = 0;
    }
    void insert(int xx) {
        tree[++len] = xx;
        up_update(len);
    }
    void delete_best() {
        swap(tree[1], tree[len]);
        len -= 1;
        down_update(1);
    }
    int sort() {
        int old_len = len;
        while (len > 0) {
            delete_best();
            // print_heap();
        }
        return old_len;
    }
    void init(int new_len) {
        len = new_len;
        for (int i = len; i >= 1; i --) {
            down_update(i);
        }
    }
    // void print_heap() {
    //     printf("==================================\n");
    //     for (int i = 1; i <= len; i++) {
    //         printf("%d\t", tree[i]);
    //         if (i == 1 || i == 4 || i == 13 || i == 30 || i == 111) {
    //             printf("\n");
    //         }
    //     }
    //     printf("\n==================================\n");
    // }
};


int main() {
    Heap heap;
    int * pp = heap.tree + 1;
    char ch;
    while (scanf("%d%c", pp, &ch) == 2) {
        pp += 1;
    }
    heap.init(pp - heap.tree - 1);

    // heap.print_heap();

    int nn = heap.sort();

    bool is_first = true;
    for (int i = 1; i <= nn; i++) {
        if (!is_first) {
            printf(",");
        }
        is_first = false;
        printf("%d", heap.tree[i]);
    }
    printf("\n");
    return 0;
}