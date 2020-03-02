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
        // For single kind of parentheses, we only need a counter(top pointer) rather than a stack.
        int cnt = 0;
        for (int i = 0; str[i]; i++) {
            if (str[i] == '(') {
                cnt ++;
            } else if (str[i] == ')') {
                if (cnt) {
                    cnt --;
                } else {
                    cnt = -1;
                    break;
                }
            }
        }
        if (cnt == 0) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
    return 0;
}