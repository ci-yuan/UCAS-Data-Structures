#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

// 使用桶排序

int bucket[5];

int main() {
    int tt;
    char ch;
    while (scanf("%d%c", &tt, &ch) == 2) {
        bucket[tt] ++;
    }
    bool is_first = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < bucket[i]; j++) {
            if (!is_first) {
                printf(",");
            }
            is_first = false;
            printf("%d", i);
        }
    }
    printf("\n");
    return 0;
}