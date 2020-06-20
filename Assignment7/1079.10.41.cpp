#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

// 使用桶排序

int bucket[10010];

int main() {
    int tt;
    while (scanf("%d", &tt) == 1) {
        bucket[tt] ++;
    }
    bool is_first = true;
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < bucket[i]; j++) {
            if (!is_first) {
                printf(" ");
            }
            is_first = false;
            printf("%d", i);
        }
    }
    printf("\n");
    return 0;
}