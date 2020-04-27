// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int ck[maxn];
int cnt = 0;
void readInMultiArray(int mm, int nn) {
    char tmp;
    if (mm == 0) {
        scanf("%d", ck + cnt);
        cnt += 1;
        return;
    }
    bool is_first = true;
    scanf("%c", &tmp);          // [
    for (int i = 0; i < nn; i++) {
        if (!is_first) {
            scanf("%c", &tmp);  // ;,
        }
        is_first = false;
        readInMultiArray(mm - 1, nn);
    }
    scanf("%c", &tmp);          // ]
}

void printSingleFormula(int cnt, int mm, int nn) {
    int box[12];
    for (int i = mm; i > 0; i--) {
        box[i] = cnt % nn;
        cnt /= nn;
    }
    for (int i = 1; i <= mm; i++) {
        if (box[i]) {
            printf("x%d", i);
            if (box[i] != 1) {
                printf("E%d", box[i]);
            }
        }
    }
}

int main() {
    int mm, nn;
    char tmp;
    scanf("%d%c%d%c", &mm, &tmp, &nn, &tmp);
    // printf("%d %d\n", mm, nn);
    readInMultiArray(mm, nn);
    bool is_first = true;
    for (int i = cnt - 1; i >= 0; i--) {
        if (ck[i]) {
            if (!is_first) {
                printf("+");
            }
            is_first = false;
            if (ck[i] != 1 || i == 0) {
                printf("%d", ck[i]);
            }
            printSingleFormula(i, mm, nn);
        }
    }
    printf("\n");
    return 0;
}