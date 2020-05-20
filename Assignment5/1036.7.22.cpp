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

bool is_visited[110];

bool is_connected(int uu, int vv) {
    if (uu == vv) {
        return true;
    }
    for (Node * p = AL[uu].nxt; p; p = p->nxt) {
        if (!is_visited[p->value]) {
            is_visited[p->value] = true;
            if (is_connected(p->value, vv)) {
                return true;
            }
        }
    }
    return false;
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
    int uu, vv;
    scanf("%d,%d", &uu, &vv);
    printf("%s\n", is_connected(uu, vv) ? "yes" : "no");
    return 0;
}