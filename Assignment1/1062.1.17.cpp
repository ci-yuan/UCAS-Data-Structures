// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1010];

int fibonacci(int k, int m) {
    if (m < k - 1) {
        return 0;
    }
    if (m == k - 1) {
        return 1;
    }
    if (arr[m]) {
        return arr[m];
    }
    arr[m] = 0;
    for (int j = 1; j <= k; j++) {
        arr[m] += fibonacci(k,m - j);
    }
    return arr[m];
}

int main() {
    int k, m;
    scanf("%d %d", &k, &m);
    printf("%d\n", fibonacci(k, m));
    return 0;
}