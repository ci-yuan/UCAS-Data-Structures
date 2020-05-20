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
int MPL[110];

void insert_into_AL(Node * head, int value) {
    while (head->nxt && head->nxt->value > value) {
        head = head->nxt;
    }
    head->nxt = new Node(value, head->nxt);
}

bool is_visited[110];

int max_path(int ss) {
    if (MPL[ss] >= 0) {
        return MPL[ss];
    }
    int res = 0;
    for (Node * p = AL[ss].nxt; p; p = p->nxt) {
        res = max(res, max_path(p->value) + 1);
    }
    MPL[ss] = res;
    return res;
}

int main() {
    int nn;
    scanf("%d", &nn);
    int start_i = 1;
    int end_i = nn;
    for (int i = 0; true; i++) {
        int uu, vv;
        char tmp;
        scanf("%d-%d%c", &uu, &vv, &tmp);
        if (uu == 0 || vv == 0) {
            start_i = 0;
            end_i = nn - 1;
        }
        insert_into_AL(AL + uu, vv);
        if (tmp != ',') {
            break;
        }
    }
    memset(MPL, -1, sizeof(MPL));
    bool is_first = true;
    for (int i = start_i; i <= end_i; i++) {
        if (!is_first) {
            printf(",");
        }
        is_first = false;
        printf("%d", max_path(i));
    }
    printf("\n");
    return 0;
}