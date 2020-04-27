#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n = 1;
    for (n; n <= 25; n++) {
        int cnt = 0;
        int i = 1;
        int j;
        int k = 0;
        do {
            cnt ++;
            k += 10 * i;
            i ++;
        } while (i <= n-1);
        // printf("%d\n", cnt);
        cnt = 0;
        k = 0;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= i; j++) {
                for (k = 1; k <= j; k++) {
                    cnt++;
                }
            }
        }
        // printf("%d\n", cnt);
        cnt = 0;
        i = 1; j = 0;
        while (i + j <= n) {
            if (i > j) j++, cnt++;
            else i++;
        }
        // printf("%d\n", cnt);
        printf("%d: ", n);
        int x = n; 
        int y = 0;
        while (x >= (y + 1)*(y + 1)) {
            y++;
        }
        printf("%d\n", y);
    }
    printf("---\n");
    int cnt1 = 0, cnt2 = 0;
    int x = 91, y = 100;
    while (y > 0) {
        cnt1 ++;
        if (x > 100) {
            x -= 10;
            y--;
            cnt2 ++;
        } else {
            x++;
        }
    }
    printf("%d %d\n", cnt1, cnt2);
    return 0;
}