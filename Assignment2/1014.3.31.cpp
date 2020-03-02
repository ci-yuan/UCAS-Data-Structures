// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    char str[100];
    while (scanf("%s", str) == 1) {
        int len = strlen(str);
        int i = 0;
        int j = len - 2;
        int flg = 1;
        while (i < j) {
            if (str[i] != str[j]) {
                flg = 0;
                break;
            }
            i++;
            j--;
        }
        printf("%d\n", flg);
    }
    return 0;
}