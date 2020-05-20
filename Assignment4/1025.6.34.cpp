#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;
int array_L[maxn];
int array_R[maxn];
int array_T[maxn];

bool is_parent(int uu, int vv) {
    // printf("---%d %d\n", uu, vv);
    if (uu == vv) {
        return true;
    }
    if (array_T[vv]) {
        return is_parent(uu, array_T[vv]);
    }
    return false;
}

int main() {
    int tmp;
    char ch;
    int iii = 0;
    while (scanf("%d%c", &tmp, &ch) == 2) {
        array_L[iii] = tmp;
        iii ++;
        if (ch == ';') {
            break;
        }
    }
    int nn = iii;
    iii = 0;
    while (scanf("%d%c", &tmp, &ch) == 2) {
        array_R[iii] = tmp;
        iii ++;
        if (ch == ';') {
            break;
        }
    }
    int uu, vv;
    scanf("%d;%d", &uu, &vv);
    for (int i = 0; i < nn; i++) {
        if (array_L[i]) {
            array_T[array_L[i]] = i;
        }
        if (array_R[i]) {
            array_T[array_R[i]] = i;
        }
    }
    // for (int i = 0; i < nn; i++) {
    //     printf("%d ", array_T[i]);
    // }
    if (is_parent(vv, uu)) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    return 0;
}