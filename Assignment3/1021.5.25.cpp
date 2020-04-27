// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int mapp[210][210];

int main() {
    int mm, nn;
    char tmp;
    scanf("%d;%d;", &mm, &nn);
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
            scanf("%d", &mapp[i][j]);
        }
        scanf("]");
    }
    scanf("]");
    printf("[");
    is_first_1 = true;
    for (int i = 0; i < mm; i++) {
        for (int j = 0; j < nn; j++) {
            if (mapp[i][j]) {
                if (!is_first_1) {
                    printf(",");
                }
                is_first_1 = false;
                printf("%d", mapp[i][j]);
            }
        }
    }
    printf("];");
    printf("[");
    is_first_1 = true;
    for (int i = 0; i < mm; i++) {
        if (!is_first_1) {
            printf(";");
        }
        is_first_1 = false;
        printf("[");
        bool is_first = true;
        for (int j = 0; j < nn; j++) {
            if (!is_first) {
                printf(",");
            }
            is_first = false;
            printf("%d", mapp[i][j] ? 1 : 0);
        }
        printf("]");
    }
    printf("]\n");
    return 0;
}