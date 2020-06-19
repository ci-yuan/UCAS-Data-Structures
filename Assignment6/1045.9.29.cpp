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
        pre = this;
        nxt = this;
    }
};

Node * hh = NULL;
Node * tt = NULL;

void print_link_list(Node * head, char ch) {
    printf("list:: %d", head->key);
    for (Node * pp = head->nxt; pp != head; pp = pp->nxt) {
        printf(" %d", pp->key);
    }
    printf("\n");
}

void search_in_list(Node * & hh, Node * & tt, int key) {
    printf("%d", tt->key);
    if (tt->key < key) {
        tt = tt->nxt;
    } else if (key < tt -> key) {
        tt = hh;
    } else {
        return;
    }
    for (; tt->key != key; tt = tt->nxt) {
        printf(",%d", tt->key);
    }
    printf(",%d", key);
}

int main() {
    int kk;
    char ch;
    while (scanf("%d%c", &kk, &ch)) {
        if (hh) {
            tt = tt->insert(new Node(kk));
        } else {
            tt = new Node(kk);
            hh = tt;
        }
        if (ch == ';') {
            break;
        }
    }
    tt = hh;
    bool is_first = true;
    while (scanf("%d%c", &kk, &ch)) {
        if (!is_first) {
            printf(";");
        }
        is_first = false;
        search_in_list(hh, tt, kk);
        if (ch != ',') {
            break;
        }
    }
    printf("\n");
    return 0;
}