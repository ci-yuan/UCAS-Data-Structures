#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr_s[110];
int arr_fst[110];
int arr_lst[110];
int len_s;

bool visited[10];
bool visit_mark[110];

bool exist_cycle(int ss) {
    visited[ss] = true;
    if (visit_mark[ss]) {
        return true;
    }
    visit_mark[ss] = true;
    for (int i = arr_fst[ss]; i < arr_lst[ss]; i ++) {
        if (exist_cycle(arr_s[i])) {
            return true;
        }
    }
    visit_mark[ss] = false;
    return false;
}

int main() {
    int nn;
    scanf("%d", &nn);
    for (int i = 0; true; i++) {
        char tmp;
        scanf("%d%c", arr_s + i, &tmp);
        if (tmp != ' ') {
            len_s = i;
            break;
        }
    }
    for (int i = 0; true; i++) {
        char tmp;
        scanf("%d%c", arr_fst + i, &tmp);
        if (tmp != ' ') {
            break;
        }
    }
    for (int i = 0; true; i++) {
        char tmp;
        scanf("%d%c", arr_lst + i, &tmp);
        if (tmp != ' ') {
            break;
        }
    }
    bool res = false;
    for (int i = 1; i <= nn; i++) {
        if (!visited[i] && exist_cycle(i)) {
            res = true;
            break;
        }
    }
    printf("%s\n", res? "yes" : "no");
    return 0;
}