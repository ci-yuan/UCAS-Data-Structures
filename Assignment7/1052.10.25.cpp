#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    Node * pre, * nxt;
    Node * link(Node * xx) {
        this->nxt = xx;
        if (xx) {
            xx->pre = this;
        }
        return xx;
    }
    Node * insert(Node * xx) {
        xx->link(this->nxt);
        this->link(xx);
        return xx;
    }
    Node(int vv): key(vv) {
        pre = NULL;
        nxt = NULL;
    }
};


void print_link_list(Node * head) {
    bool is_first = true;
    for (Node * pp = head->nxt; pp; pp = pp->nxt) {
        if (!is_first) {
            printf(",");
        }
        is_first = false;
        printf("%d", pp->key);
    }
    printf("\n");
}

void insert_sort(Node * head) {
    Node * end, * qq, *tt;
    for (end = head->nxt; end->nxt; ) {
        qq = end->nxt;
        for (tt = head; tt != end; tt = tt->nxt) {
            if (qq->key < tt->nxt->key) {
                qq->pre->link(qq->nxt);
                tt->insert(qq);
                break;
            }
        }
        if (tt == end) {
            end = end->nxt;
        }
    }
}

int main() {
    int tt;
    char ch;
    Node * head = new Node(0);
    Node * pp = head;
    while (scanf("%d%c", &tt, &ch) == 2) {
        pp->insert(new Node(tt));
        pp = pp->nxt;
    }
    insert_sort(head);
    print_link_list(head);
    return 0;
}