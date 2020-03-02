// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int sumM[6], sumF[6];

int main() {
    char event[10], sex[10], school[10];
    int tt;
    while (scanf("%s %s %s %d", event, sex, school, &tt) == 4) {
        if (sex[0] == 'M') {
            sumM[school[0] - 'A'] += tt;
        } else {
            sumF[school[0] - 'A'] += tt;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (sumM[i]) {
            printf("%c M %d\n", i + 'A', sumM[i]);
        }
        if (sumF[i]) {
            printf("%c F %d\n", i + 'A', sumF[i]);
        }
        if (sumM[i] + sumF[i]) {
            printf("%c %d\n", i + 'A', sumM[i] + sumF[i]);
        }
    }
    return 0;
}