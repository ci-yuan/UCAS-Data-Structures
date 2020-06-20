#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int aaa[110];
int ccc[110];
int len = 0;

void init_ccc(int len, int aaa[], int ccc[]) {
    memset(ccc, 0, sizeof(int) * len);
    for (int i = 1; i <= len; i++) {
        for (int j = i + 1; j <= len; j++) {
            if (aaa[i] < aaa[j]) {
                ccc[j] += 1;
            } else if (aaa[i] > aaa[j]) {
                ccc[i] += 1;
            }
        }
    }
}

void count_sort(int len, int aaa[], int ccc[]) {
    init_ccc(len, aaa, ccc);
    // for (int i = 1; i <= len; i++) {
    //     printf("%d\t", aaa[i]);
    // }
    // printf("\n");
    // for (int i = 1; i <= len; i++) {
    //     printf("%d\t", ccc[i]);
    // }
    // printf("\n");
    int tmp_aaa, tmp_ccc;
    for (int i = 1; i <= len; i++) {
        tmp_aaa = aaa[i];
        tmp_ccc = ccc[i];
        while (tmp_ccc != ccc[tmp_ccc + 1]) {
            // printf("---swap, tmp_ccc = %d, tmp_aaa = %d\n", tmp_ccc, tmp_aaa);
            // for (int i = 1; i <= len; i++) {
            //     printf("%d\t", aaa[i]);
            // }
            // printf("\n");
            // for (int i = 1; i <= len; i++) {
            //     printf("%d\t", ccc[i]);
            // }
            // printf("\n");
            swap(tmp_aaa, aaa[tmp_ccc + 1]);
            swap(tmp_ccc, ccc[tmp_ccc + 1]);
            // printf("===swap, tmp_ccc = %d, tmp_aaa = %d\n", tmp_ccc, tmp_aaa);
            // for (int i = 1; i <= len; i++) {
            //     printf("%d\t", aaa[i]);
            // }
            // printf("\n");
            // for (int i = 1; i <= len; i++) {
            //     printf("%d\t", ccc[i]);
            // }
            // printf("\n");
        }
    }
}

int main() {
    int tt;
    while (scanf("%d", &tt) == 1) {
        len += 1;
        aaa[len] = tt;
    }
    count_sort(len, aaa, ccc);


    bool is_first = true;
    for (int i = 1; i <= len; i++) {
        if (!is_first) {
            printf(" ");
        }
        is_first = false;
        printf("%d", aaa[i]);
    }
    printf("\n");
    return 0;
}