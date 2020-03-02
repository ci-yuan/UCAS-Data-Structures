// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int strA[110], strB[110];
int lenA = 0, lenB = 0;

int main() {
    char ch;
    while ((ch = getchar()) != EOF && ch != ';') {
        if (ch != ',') {
            strA[lenA++] = ch;
        }
    }
    strA[lenA] = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch != ',') {
            strB[lenB++] = ch;
        }
    }
    strB[lenB] = 0;
    for (int i = 0; i <= lenA && i <= lenB; i++) {
        if (strA[i] < strB[i]) {
            printf("1\n");
            return 0;
        } else if (strA[i] > strB[i]) {
            printf("2\n");
            return 0;
        }
    }
    printf("0\n");
    return 0;
}