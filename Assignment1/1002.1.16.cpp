// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c;
    while (scanf("%d %d %d", &a, &b, &c) == 3) {
        int tt;
        if (a < b) {
            swap(a, b);
        }
        if (c >= a) {
            printf("%d %d %d\n", c, a, b);
        } else if (b >= c) {
            printf("%d %d %d\n", a, b, c);
        } else {
            printf("%d %d %d\n", a, c, b);
        }
    }
    return 0;
}