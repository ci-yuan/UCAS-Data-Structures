#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;
int array_pre[maxn];
int array_mid[maxn];
int array_post[maxn];
int cnt = 0;

struct BTnode {
    BTnode * parent;
    BTnode * son_L;
    BTnode * son_R;
    int value;
    BTnode(): parent(NULL), son_L(NULL), son_R(NULL) {}
    BTnode(int value, BTnode * parent): 
        value(value), parent(parent), son_L(NULL), son_R(NULL) {}
};

BTnode * build_BT(BTnode * parent, int pre_l, int pre_r, int mid_l, int mid_r) {
    // printf("%d: %d %d %d %d\n", array_pre[pre_l], pre_l, pre_r, mid_l, mid_r);
    if (pre_l >= pre_r || mid_l >= mid_r) {
        return NULL;
    }
    BTnode * root = new BTnode(array_pre[pre_l], parent);
    int mid_index;
    for (mid_index = mid_l; mid_index < mid_r; mid_index ++) {
        // printf("!! %d == %d\n", array_mid[mid_index], array_pre[pre_l]);
        if (array_mid[mid_index] == array_pre[pre_l]) {
            break;
        }
    }
    // printf("--%d\n", mid_index);
    int len_l = mid_index - mid_l;
    int len_r = mid_r - mid_index - 1;
    root->son_L = build_BT(root, pre_l + 1, pre_l + len_l + 1, mid_l, mid_index);
    root->son_R = build_BT(root, pre_l + len_l + 1, pre_r, mid_index + 1, mid_r);
    return root;
}


void print_postorder(BTnode * root) {
    if (root->son_L) {
        print_postorder(root->son_L);
    }
    if (root->son_R) {
        print_postorder(root->son_R);
    }
    array_post[cnt++] = root->value;
}

int main() {
    int tmp;
    char ch;
    int iii = 0;
    while (scanf("%d%c", &tmp, &ch) == 2) {
        array_pre[iii] = tmp;
        iii ++;
        if (ch != ',') {
            break;
        }
    }
    int nn = iii;
    iii = 0;
    while (scanf("%d%c", &tmp, &ch) == 2) {
        array_mid[iii] = tmp;
        iii ++;
        if (ch != ',') {
            break;
        }
    }
    BTnode * root = build_BT(NULL, 0, nn, 0, nn);
    print_postorder(root);
    bool is_first = true;
    for (int i = 0; i < cnt; i++) {
        if (!is_first) {
            printf(",");
        }
        is_first = false;
        printf("%d", array_post[i]);
    }
    printf("\n");
    return 0;
}