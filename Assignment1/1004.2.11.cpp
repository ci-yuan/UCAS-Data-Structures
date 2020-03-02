// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1010];

int main() {
    int n, p;
    
    // read in
    for (n = 0; scanf("%d", arr + n) == 1; n++);
    n -= 1;
    int x = arr[n];
    p = n;
    for (int i = 0; i < n; i++) {
        if (arr[i] > x) {
            p = i;
            break;
        }
    }
    for (int i = n; i > p; i--) {
        arr[i] = arr[i - 1];
    }
    arr[p] = x;
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[n]);
    return 0;
}