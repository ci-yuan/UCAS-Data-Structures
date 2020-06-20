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
    Node() {
        pre = NULL;
        nxt = NULL;
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
            printf(" ");
        }
        is_first = false;
        printf("%d", pp->key);
    }
    printf("\n");
}

Node * merge_sort(Node segments[], int & cnt_segments) {
    // cout << "????" << endl;
    for (Node * pp = segments->nxt->nxt; pp; pp = pp->nxt) {
        // cout << pp->key << "  ";
        if (pp->pre->key > pp->key) {
            // cout << endl;
            pp->pre->nxt = NULL;
            pp->pre = segments + cnt_segments;
            (segments + cnt_segments)->nxt = pp;
            cnt_segments += 1;
        }
    }
    // cout << "####" << endl;
    // for (int i = 0; i < cnt_segments; i++) {
    //     print_link_list(segments + i);
    // }
    Node * res = new Node();
    for (int i = 1; i < cnt_segments; i++) {
        Node * pp = segments->nxt;
        Node * qq = (segments + i)->nxt;
        Node * tt = res;
        while (pp || qq) {
            if (pp == NULL || pp && qq && qq->key <= pp->key) {
                tt->link(qq);
                tt = tt->nxt;
                qq = qq->nxt;
            } else if (qq == NULL || pp && qq && pp->key <= qq->key) {
                tt->link(pp);
                tt = tt->nxt;
                pp = pp->nxt;
            }
        }
        segments->link(res->nxt);
    }
    res->link(segments->nxt);
    return res;
}

Node segments[100];
int cnt_segments = 1;

int main() {
    int tt;
    Node * pp = segments;
    while (scanf("%d", &tt) == 1) {
        pp->insert(new Node(tt));
        pp = pp->nxt;
    }
    // cout << "!!!!" << endl;
    Node * result = merge_sort(segments, cnt_segments);
    print_link_list(result);
    return 0;
}