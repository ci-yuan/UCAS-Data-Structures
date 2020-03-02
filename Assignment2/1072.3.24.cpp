// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int ggg(int m, int n) {
    if (m == 0) {
        return 0;
    }
    return ggg(m - 1, 2 * n) + n;
}

int main() {
    int m, n;
    scanf("%d,%d", &m, &n);
    printf("%d\n", ggg(m, n));
    return 0;
}