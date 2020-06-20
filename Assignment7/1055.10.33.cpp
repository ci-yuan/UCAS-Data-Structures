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
        return xx;
    }
    Node * insert(Node * xx) {
        xx->nxt = this->nxt;
        this->nxt = xx;
        return xx;
    }
    Node(int vv): key(vv) {
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

Node * select_sort(Node * head) {
    Node * new_head = new Node(0);
    Node * qq = new_head;
    while (head->nxt) {
        Node * mn_node_pre = NULL;
        for (Node * pp = head; pp->nxt; pp = pp->nxt) {
            // printf("----%d\n", pp->nxt->key);
            if (mn_node_pre == NULL || mn_node_pre->nxt->key > pp->nxt->key) {
                mn_node_pre = pp;
            }
        }
        // printf("===%d\n", mn_node_pre->nxt->key);
        Node * mn_node = mn_node_pre->nxt;
        mn_node_pre->link(mn_node_pre->nxt->nxt);
        qq->insert(mn_node);
        qq = qq->nxt;
        // printf("old: ");
        // print_link_list(head);
        // printf("new: ");
        // print_link_list(new_head);
    }
    delete head;
    return new_head;
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
    head = select_sort(head);
    print_link_list(head);
    return 0;
}