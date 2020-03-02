// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct stk {
    int arr[110];
    int tp;
    stk() {
        tp = 0;
    }
    int empty() {
        return tp == 0;
    }
    int size() {
        return tp;
    }
    int top() {
        if (tp) {
            return arr[tp - 1];
        }
        return 0;
    }
    int pop() {
        if (tp) {
            return arr[--tp];
        }
        return 0;
    }
    void push(int x) {
        arr[tp++] = x;
    }
    void print() {
        for (int i = 0; i < tp; i++) {
            printf("%c ", arr[i]);
        }
        printf("\n");
    }
};

int optcmp(char oa, char ob) {
    if (oa == '(') {
        return 1;
    }
    if ((oa == '-' || oa == '+') && (ob == '*' || ob == '/')) {
        return 1;
    }
    return 0;
}

void in2ps(char * str1, char * str2) {
    stk optstk;
    int p = 0;
    for (int i = 0; str1[i]; i++) {
        if (isalpha(str1[i])) {
            str2[p++] = str1[i];
        } else if (str1[i] == '(') {
            optstk.push('(');
        } else if (str1[i] == ')') {
            while (!optstk.empty() && optstk.top() != '(') {
                str2[p++] = optstk.pop();
            }
            if (optstk.top() == '(') {
                optstk.pop();
            }
        } else {
            while (!optstk.empty() && !optcmp(optstk.top(), str1[i])) {
                str2[p++] = optstk.pop();
            }
            optstk.push(str1[i]);
        }
    }
    while (!optstk.empty()) {
        str2[p++] = optstk.pop();
    }
    str2[p] = 0;
}

int main() {
    char str1[110], str2[110];
    scanf("%s", str1);
    in2ps(str1, str2);
    printf("%s\n", str2);
    return 0;
}