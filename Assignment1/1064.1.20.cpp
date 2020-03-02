// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    int sum;
    scanf("%d %d", &n, &x);
    int xn = 1;
    scanf("%d", &sum);
    for (int i = 1; i < n; i++) {
        int tt;
        scanf("%d", &tt);
        xn *= x;
        sum += tt * xn;
    }
    printf("%d\n", sum);
    return 0;
}