#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Node {
    int value;
    Node * nxt;
    Node() {}
    Node(int value, Node * nxt): value(value), nxt(nxt) {}
};

Node AL[110];

void insert_into_AL(Node * head, int value) {
    while (head->nxt && head->nxt->value > value) {
        head = head->nxt;
    }
    head->nxt = new Node(value, head->nxt);
}

int main() {
    int nn, mm;
    scanf("%d,%d", &nn, &mm);
    int start_i = 1;
    int end_i = nn;
    for (int i = 0; i < mm; i++) {
        int uu, vv;
        char tmp;
        scanf("%d-%d%c", &uu, &vv, &tmp);
        if (uu == 0 || vv == 0) {
            start_i = 0;
            end_i = nn - 1;
        }
        insert_into_AL(AL + uu, vv);
    }
    for (int i = start_i; i <= end_i; i++) {
        printf("%d", i);
        if (AL[i].nxt) {
            printf(" ");
            bool is_first = true;
            for (Node * pos = AL[i].nxt; pos; pos = pos->nxt) {
                if (!is_first) {
                    printf(",");
                }
                is_first = false;
                printf("%d", pos->value);
            }
        }
        printf("\n");
    }
    return 0;
}