// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int fff[110];

int main() {
    fff[0] = 1;
    int x;
    scanf("%d", &x);
    for (int i = 1; i <= x; i++) {
        fff[i] = i * fff[i / 2];
    }
    printf("%d\n", fff[x]);
    return 0;
}