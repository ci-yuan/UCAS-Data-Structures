#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int mapp[110][110];

int vex[110];
int cnt = 0;

int main() {
    int nn, mm;
    scanf("%d", &nn);
    int start_i = 1;
    int end_i = nn;
    for (int i = 0; true; i++) {
        int uu, vv;
        char tmp;
        scanf("%d-%d%c", &uu, &vv, &tmp);
        if (uu == 0 || vv == 0) {
            start_i = 0;
            end_i = nn - 1;
        }
        mapp[uu][vv] = 1;
        if (tmp != ',') {
            break;
        }
    }
    for (int i = start_i; i <= end_i; i++) {
        vex[cnt++] = i;
    }
    string input_string;
    while (getline(cin, input_string)) {
        if (input_string.substr(0, 2) == "IV") {
            int tmp1;
            sscanf(input_string.substr(3).c_str(), "%d", &tmp1);
            vex[cnt++] = tmp1;
        } else if (input_string.substr(0, 2) == "IA") {
            int tmp1, tmp2;
            sscanf(input_string.substr(3).c_str(), "%d,%d", &tmp1, &tmp2);
            mapp[tmp1][tmp2] = 1;
        } else if (input_string.substr(0, 2) == "DV") {
            int tmp1;
            sscanf(input_string.substr(3).c_str(), "%d", &tmp1);
            for (int i = 0; i < cnt; i++) {
                if (vex[i] == tmp1) {
                    vex[i] = -1;
                }
            }
        } else if (input_string.substr(0, 2) == "DA") {
            int tmp1, tmp2;
            sscanf(input_string.substr(3).c_str(), "%d,%d", &tmp1, &tmp2);
            mapp[tmp1][tmp2] = 0;
        }
    }
    for (int i = 0; i < cnt; i++) {
        if (vex[i] < 0) {
            continue;
        }
        bool is_first = true;
        for (int j = 0; j < cnt; j++) {
            if (vex[j] < 0) {
                continue;
            }
            if (!is_first) {
                printf(",");
            }
            is_first = false;
            // printf("[%d][%d]: ", vex[i], vex[j]);
            printf("%d", mapp[vex[i]][vex[j]]);
            // printf("\n");
        }
        printf("\n");
    }
    return 0;
}