#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;
int array_L[maxn];
int array_R[maxn];

bool is_children(int uu, int vv) {
    // printf("---%d %d", uu, vv);
    if (uu == vv) {
        return true;
    }
    bool ans = false;
    if (array_L[uu]) {
        ans = ans || is_children(array_L[uu], vv);
    }
    if (array_R[uu]) {
        ans = ans || is_children(array_R[uu], vv);
    }
    return ans;
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
    if (is_children(vv, uu)) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    return 0;
}