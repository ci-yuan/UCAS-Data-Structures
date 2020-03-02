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
        while (i < j) {
            if (str[i] != str[j]) {
                break;
            }
            i++;
            j--;
        }
        if (i == j && str[i] == '&') {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
    return 0;
}