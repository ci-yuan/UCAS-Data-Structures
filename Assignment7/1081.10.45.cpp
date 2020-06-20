#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

// 不太明白题目所描述的“借助“计数”实现基数排序”是什么意思……
// 使用了桶排序，大概算是“计数”

int cnt[1100];

int main() {
    for (int i = 0; i < 10; i++) {
        int tt;
        scanf("%d", &tt);
        cnt[tt] += 1;
    }
    bool is_first = true;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            if (!is_first) {
                printf(" ");
            }
            is_first = false;
            printf("%03d", i);
        }
    }
    printf("\n");
    return 0;
}