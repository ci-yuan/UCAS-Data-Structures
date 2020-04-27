// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int compare(const char * a, const char * b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    for (int i = 0; i <= min(len_a, len_b); i++) {
        if (a[i] != b[i]) {
            return a[i] - b[i] < 0 ? -1 : 1;
        }
    }
    return 0;
}

char tmp_str1[210];
char tmp_str2[210];

int main() {
    scanf("%s %s", tmp_str1, tmp_str2);
    printf("%d\n", compare(tmp_str1, tmp_str2));
    return 0;
}