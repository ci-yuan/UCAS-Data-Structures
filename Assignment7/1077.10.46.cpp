#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Node {
    int key;                        // 关键字
    void * content;                 // 指向内容的指针
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

void swap_key(Node * xx, Node * yy) {
    int tt = xx->key;
    xx->key = yy->key;
    yy->key = tt;
    void * cc = xx->content;
    xx->content = yy->content;
    yy->content = cc;
}

void quick_sort(Node * arr_l, Node * arr_r) {
    Node * stk_l[100];
    Node * stk_r[100];
    int stk_top = 0;

    stk_l[stk_top] = arr_l;
    stk_r[stk_top] = arr_r;
    stk_top += 1;
    while (stk_top) {
        stk_top -= 1;
        Node * cur_l = stk_l[stk_top];
        Node * cur_r = stk_r[stk_top];
        // printf("========================\n");
        // print_link_list(arr_l->pre);
        // printf("========================\n");
        // printf("::[%d : %d]\n", cur_l->key, cur_r->key);
        
        // printf("--[%d : %d]\n", cur_l - arr_l, cur_r - arr_l);
        if (cur_l != cur_r) {
            Node * ii = cur_l;
            Node * jj = cur_r;

            while (ii != jj) {
                while (ii != jj && cur_l->key <= jj->key) {
                    jj = jj->pre;
                }
                while (ii != jj && ii->key <= cur_l->key) {
                    ii = ii->nxt;
                }
                if (ii != jj) {
                    swap_key(ii, jj);
                } else {
                    swap_key(ii, cur_l);
                }
            }
            if (cur_l != ii) {
                stk_l[stk_top] = cur_l;
                stk_r[stk_top] = ii->pre;
                stk_top += 1;
            }
            if (jj != cur_r) {
                stk_l[stk_top] = jj->nxt;
                stk_r[stk_top] = cur_r;
                stk_top += 1;
            }
        } 
        // for (int * qq = arr_l; qq != arr_r; qq += 1) {
        //     printf("%d\t", qq - arr_l);
        // }
        // printf("\n");
        // for (int * qq = arr_l; qq != arr_r; qq += 1) {
        //     printf("%d\t", *qq);
        // }
        // printf("\n");
    }
}

int aa[110];
int cnt = 0;

int main() {
    int tt;
    Node * head = new Node();
    Node * pp = head;
    // printf("###\n");
    while (scanf("%d", &tt) == 1) {
        pp->insert(new Node(tt));
        pp = pp->nxt;
    }
    // printf("???\n");
    quick_sort(head->nxt, pp);  // 对（关键字，内容指针）链表排序
    // printf("!!!\n");
    for (pp = head->nxt; pp; pp = pp->nxt) {
        aa[cnt] = pp->key;      // 复制，因为没有内容，所以只复制关键字
        cnt += 1;
    }
    bool is_first = true;
    for (int i = 0; i < cnt; i++) {
        if (!is_first) {
            printf(" ");
        }
        is_first = false;
        printf("%d", aa[i]);
    }
    printf("\n");
    return 0;
}