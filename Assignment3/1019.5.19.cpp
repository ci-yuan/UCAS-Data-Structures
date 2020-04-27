// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int mapp[210][210];
int min_x[210];
int max_y[210];
int spl[210];
int cnt = 0;

int main() {
    bool is_first;
    int mm = 0, nn = 0;
    char tch;
    memset(min_x, 0x3f, sizeof(min_x));
    while (true) {
        scanf("%d", &mapp[mm][nn]);
        min_x[mm] = min(min_x[mm], mapp[mm][nn]);
        max_y[nn] = max(max_y[nn], mapp[mm][nn]);
        scanf("%c", &tch);
        if (tch == ',') {
            nn += 1;
        } else if (tch == ';') {
            nn = 0;
            mm += 1;
        } else {
            nn += 1;
            mm += 1;
            break;
        }
    }
    for (int i = 0; i < mm; i++) {
        for (int j = 0; j < nn; j++) {
            if (mapp[i][j] == min_x[i] && mapp[i][j] == max_y[j]) {
                spl[cnt++] = mapp[i][j];
            }
        }
    }
    if (cnt) {
        sort(spl, spl + cnt);
        is_first = true;
        for (int i = 0; i < cnt; i++) {
            printf("%s%d", is_first? "" : ",", spl[i]);
            is_first = false;
        }
        printf("\n");
    } else {
        printf("null\n");
    }

    // for (int i = 0; i < mm; i++) {
    //     for (int j = 0; j < nn; j++) {
    //         printf("%d ", mapp[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}