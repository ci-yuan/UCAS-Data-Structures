// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXINT = 65535;
const int ARRSIZE = 300;
int arr[ARRSIZE + 10];
int mx = 0;

int main() {
    int n;
    arr[0] = 1;
    while (scanf("%d", &n) == 1) {
        mx = 0;
        for (int i = 1; i < n; i++) {
            arr[i] = arr[i - 1] * i * 2;
            if (arr[i] > MAXINT) {
                arr[i] = 0;
                break; 
            }
            mx = arr[i];
        }
        printf("%d\n", mx);
    }
    return 0;
}