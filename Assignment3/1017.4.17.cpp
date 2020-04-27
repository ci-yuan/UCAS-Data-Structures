// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

char sss[210];
char ttt[210];
char vvv[210];
char tmp[210];

bool replace(char * sss, char * ttt, char * vvv) {
    bool have_replace = false;
    int len_tmp = strlen(sss);
    int len_ttt = strlen(ttt);
    int len_vvv = strlen(vvv);
    int pos_tmp = 0;
    int pos_sss = 0;
    memcpy(tmp, sss, len_tmp);
    for (int i = 0; i < len_tmp; i++) {
        bool ok_flg = true;
        for (int j = 0; j < len_ttt; j++) {
            if (tmp[i + j] != ttt[j]) {
                ok_flg = false;
                break;
            }
        }
        if (ok_flg) {
            have_replace = true;
            memcpy(sss + pos_sss, tmp + pos_tmp, i - pos_tmp);
            pos_sss += i - pos_tmp;
            memcpy(sss + pos_sss, vvv, len_vvv);
            pos_sss += len_vvv;
            pos_tmp = i + len_ttt;
            i += len_ttt - 1;
        }
    }
    memcpy(sss + pos_sss, tmp + pos_tmp, len_tmp - pos_tmp);
    pos_sss += len_tmp - pos_tmp;
    sss[pos_sss] = 0;
    return have_replace;
}

int main() {
    scanf("%s %s %s", sss, ttt, vvv);
    if (replace(sss, ttt, vvv)) {
        printf("%s\n", sss);
    }
    return 0;
}