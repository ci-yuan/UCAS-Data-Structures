// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1010];

int main() {
    int k, m;
    while (scanf("%d %d", &k, &m) == 2) {
        if (m < k - 1) {
            printf("0\n");
            continue;
        }
        for (int i = 0; i < k - 1; i++) {
            arr[i] = 0;
        }
        arr[k - 1] = 1;
        for (int i = k; i <= m; i++) {
            arr[i] = 0;
            for (int j = 1; j <= k; j++) {
                arr[i] += arr[i - j];
            }
        }
        printf("%d\n", arr[m]);
    }
    return 0;
}