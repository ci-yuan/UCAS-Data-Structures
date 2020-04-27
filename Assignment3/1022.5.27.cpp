// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;

struct linkNode {
    int x, y, data;
    linkNode * down, * right;
    linkNode(int x, int y, int data): x(x), y(y), data(data), down(NULL), right(NULL) { }
};

linkNode * x_head[maxn];
linkNode * y_head[maxn];

void insertMatrix(int x, int y, int data) {
    // printf("===: %d, %d = %d\n", x, y, data);
    linkNode * new_node = new linkNode(x, y, data);
    linkNode * p;
    for (p = x_head[x]; p->right; p = p->right) {
        if (p->y == y || p->right->y > y) {
            break;
        }
    }
    // printf("-->p: %d, %d = %d\n", p->x, p->y, p->data);
    if (p->y == y) {
        p->data += data;
        delete new_node;
        return;
    } else if (p->y < y) {
        new_node->right = p->right;
        p->right = new_node;
    }
    for (p = y_head[y]; p->down; p = p->down) {
        if (p->down->x > x) {
            break;
        }
    }
    if (p->x < x) {
        new_node->down = p->down;
        p->down = new_node;
    }
}

int main() {
    int mm, nn;
    int tmp;
    scanf("%d;%d;", &mm, &nn);
    for (int i = 0; i < mm; i++) {
        x_head[i] = new linkNode(i, -1, i);
    }
    for (int i = 0; i < nn; i++) {
        y_head[i] = new linkNode(-1, i, i);
    }
    scanf("[");
    bool is_first_1 = true;
    for (int i = 0; i < mm; i++) {
        if (!is_first_1) {
            scanf(";");
        }
        is_first_1 = false;
        scanf("[");
        bool is_first = true;
        for (int j = 0; j < nn; j++) {
            if (!is_first) {
                scanf(",");
            }
            is_first = false;
            scanf("%d", &tmp);
            if (tmp) {
                insertMatrix(i, j, tmp);
            }
        }
        scanf("]");
    }
    scanf("]");

    // for (int i = 0; i < mm; i++) {
    //     for (linkNode * p = x_head[i]; p; p = p->right) {
    //         printf("(%d %d), ", p->y, p->data);
    //     }
    //     printf("\n");
    // }
    // printf("---------\n");
    // for (int i = 0; i < nn; i++) {
    //     for (linkNode * p = y_head[i]; p; p = p->down) {
    //         printf("(%d %d), ", p->x, p->data);
    //     }
    //     printf("\n");
    // }
    // printf("---------\n");

    scanf("+");
    scanf("[");
    is_first_1 = true;
    for (int i = 0; i < mm; i++) {
        if (!is_first_1) {
            scanf(";");
        }
        is_first_1 = false;
        scanf("[");
        bool is_first = true;
        for (int j = 0; j < nn; j++) {
            if (!is_first) {
                scanf(",");
            }
            is_first = false;
            scanf("%d", &tmp);
            if (tmp) {
                insertMatrix(i, j, tmp);
            }
        }
        scanf("]");
    }
    scanf("]");
    is_first_1 = true;

    // for (int i = 0; i < mm; i++) {
    //     for (linkNode * p = x_head[i]; p; p = p->right) {
    //         printf("(%d %d), ", p->y, p->data);
    //     }
    //     printf("\n");
    // }
    // printf("---------\n");
    // for (int i = 0; i < nn; i++) {
    //     for (linkNode * p = y_head[i]; p; p = p->down) {
    //         printf("(%d %d), ", p->x, p->data);
    //     }
    //     printf("\n");
    // }
    // printf("---------\n");

    printf("[");
    for (int i = 0; i < mm; i++) {
        if (!is_first_1) {
            printf(";");
        }
        is_first_1 = false;
        printf("[");
        linkNode * p = x_head[i]->right;
        bool is_first = true;
        for (int j = 0; j < nn; j++) {
            if (!is_first) {
                printf(",");
            }
            is_first = false;
            if (p && p->y == j) {
                printf("%d", p->data);
                p = p->right;
            } else {
                printf("0");
            }
        }
        printf("]");
    }
    printf("]\n");
    return 0;
}