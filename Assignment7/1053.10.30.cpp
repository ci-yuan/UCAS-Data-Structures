#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

void quick_sort(int * arr_l, int * arr_r) {
    
    // for (int * qq = arr_l; qq != arr_r; qq += 1) {
    //     printf("%d\t", qq - arr_l);
    // }
    // printf("\n");
    // for (int * qq = arr_l; qq != arr_r; qq += 1) {
    //     printf("%d\t", *qq);
    // }
    // printf("\n");
    int * stk_l[100];
    int * stk_r[100];
    int stk_top = 0;

    stk_l[stk_top] = arr_l;
    stk_r[stk_top] = arr_r;
    stk_top += 1;
    while (stk_top) {
        stk_top -= 1;
        int * cur_l = stk_l[stk_top];
        int * cur_r = stk_r[stk_top];
        
        // printf("--[%d : %d]\n", cur_l - arr_l, cur_r - arr_l);
        if (cur_r - cur_l > 3) {
            int * ii = cur_l;
            int * jj = cur_r;

            while (jj - ii > 1) {
                while (jj - ii > 1 && *cur_l <= *(jj - 1)) {
                    jj --;
                }
                while (jj - ii > 1 && *ii <= *cur_l) {
                    ii ++;
                }
                if (jj - ii > 1) {
                    int tmp = *ii;
                    *ii = *(jj - 1);
                    *(jj - 1) = tmp;
                } else {
                    int tmp = *ii;
                    *ii = *cur_l;
                    *cur_l = tmp;
                }
            }
            // printf("!!! i = %ld; j = %ld\n", ii - arr_l, jj - arr_l);
            if (ii - cur_l < cur_r - jj) {
                // printf("~~~ insert [%ld : %ld]\n", jj - arr_l, cur_r - arr_l);
                stk_l[stk_top] = jj;
                stk_r[stk_top] = cur_r;
                stk_top += 1;

                // printf("~~~ insert [%ld : %ld]\n", cur_l - arr_l, ii - arr_l);
                stk_l[stk_top] = cur_l;
                stk_r[stk_top] = ii;
                stk_top += 1;
            } else {
                // printf("~~~ insert [%ld : %ld]\n", cur_l - arr_l, ii - arr_l);
                stk_l[stk_top] = cur_l;
                stk_r[stk_top] = ii;
                stk_top += 1;

                // printf("~~~ insert [%ld : %ld]\n", jj - arr_l, cur_r - arr_l);
                stk_l[stk_top] = jj;
                stk_r[stk_top] = cur_r;
                stk_top += 1;
            }
        } else if (cur_r - cur_l == 3) {
            int t1, t2, t3;
            t1 = *(cur_l);
            t2 = *(cur_l + 1);
            t3 = *(cur_l + 2);
            if (t1 <= t2 && t2 <= t3) {
                *(cur_l) = t1;
                *(cur_l + 1) = t2;
                *(cur_l + 2) = t3;
            } else if (t1 <= t3 && t3 <= t2) {
                *(cur_l) = t1;
                *(cur_l + 1) = t3;
                *(cur_l + 2) = t2;
            } else if (t2 <= t1 && t1 <= t3) {
                *(cur_l) = t2;
                *(cur_l + 1) = t1;
                *(cur_l + 2) = t3;
            } else if (t2 <= t3 && t3 <= t1) {
                *(cur_l) = t2;
                *(cur_l + 1) = t3;
                *(cur_l + 2) = t1;
            } else if (t3 <= t1 && t1 <= t2) {
                *(cur_l) = t3;
                *(cur_l + 1) = t1;
                *(cur_l + 2) = t2;
            } else if (t3 <= t2 && t2 <= t1) {
                *(cur_l) = t3;
                *(cur_l + 1) = t2;
                *(cur_l + 2) = t1;
            }
        } else if (cur_r - cur_l == 2) {
            int t1 = *(cur_l);
            int t2 = *(cur_l + 1);
            if (t1 <= t2) {
                *(cur_l) = t1;
                *(cur_l + 1) = t2;
            } else {
                *(cur_l) = t2;
                *(cur_l + 1) = t1;
            }
        }
        // for (int * qq = arr_l; qq != arr_r; qq += 1) {
        //     printf("%d\t", qq - arr_l);
        // }
        // printf("\n");
        // for (int * qq = arr_l; qq != arr_r; qq += 1) {
        //     printf("%d\t", *qq);
        // }
        // printf("\n");
    }
}

int arr[100];

int main() {
    int tt;
    char ch;
    int * pp = arr;
    while (scanf("%d%c", pp, &ch) == 2) {
        pp += 1;
    }
    // cout << "???" << endl;
    quick_sort(arr, pp);
    // cout << "!!!" << endl;
    bool is_first = true;
    for (int * qq = arr; qq != pp; qq += 1) {
        if (!is_first) {
            printf(",");
        }
        is_first = false;
        printf("%d", *qq);
    }
    printf("\n");
    return 0;
}