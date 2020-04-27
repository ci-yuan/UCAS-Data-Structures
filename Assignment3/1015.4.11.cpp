// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

char str1[210];
char str2[210];
int len1, len2;
bool flg[130];
char res[130];
int pos[130];
int cnt = 0;

int main() {
    scanf("%s %s", str1, str2);
    len1 = strlen(str1);
    len2 = strlen(str2);
    for (int i = 0; i < len2; i++) {
        flg[str2[i]] = true;
    }
    for (int i = 0; i < len1; i++) {
        if (!flg[str1[i]]) {
            flg[str1[i]] = true;
            res[cnt] = str1[i];
            pos[cnt] = i;
            cnt += 1;
        }
    }
    res[cnt] = 0;
    if (cnt) {
        printf("%s ", res);
        for (int i = 0; i < cnt; i++) {
            printf("%d", pos[i]);
        }
        printf("\n");
    } else {
        printf("-1\n");
    }

    return 0;
}