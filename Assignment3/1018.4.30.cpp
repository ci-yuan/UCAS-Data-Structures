// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

class StringType {
private:
    char str[210];
    int len;
public:
    StringType() {
        len = 0;
    }
    StringType(const char * new_str) {
        len = min(200, (int)strlen(new_str));
        memcpy(str, new_str, len);
        str[len] = 0;
    }
    StringType(const char * new_str, int new_len) {
        len = new_len;
        memcpy(str, new_str, len);
        str[len] = 0;
    }
    bool operator < (const StringType & b) const {
        for (int i = 0; i <= min(len, b.len); i++) {
            if (str[i] != b.str[i]) {
                return str[i] < b.str[i];
            }
        }
        return false;
    }
    // for SubString
    StringType subString(int start, int sub_len) const {
        StringType res(str + start, sub_len);
        return res;
    }
    void print() {
        printf("%s", str);
    }
    int length() {
        return len;
    }
    static int countPrefix(const StringType & a, const StringType & b) {
        for (int i = 0; i < min(a.len, b.len); i++) {
            if (a.str[i] != b.str[i]) {
                return i;
            }
        }
        return min(a.len, b.len);
    }
};

char str_tmp[210];
int len_tmp;

StringType suf_str[210];

int main() {
    scanf("%s", str_tmp);
    len_tmp = strlen(str_tmp);
    StringType src = str_tmp;
    for (int i = 0; i < len_tmp; i++) {
        suf_str[i] = src.subString(i, len_tmp - i);
        // suf_str[i].print();
        // printf("\n");
    }
    sort(suf_str, suf_str + len_tmp);
    int ans_len = -1;
    StringType ans;
    int ans_pos = -1;
    for (int i = 0; i < len_tmp; i++) {
        for (int j = 0; j < len_tmp; j++) {
            if (i == j) {
                continue;
            }
            // suf_str[i].print();
            // printf("\n");
            // suf_str[j].print();
            // printf("\n");
            int max_pre = StringType::countPrefix(suf_str[j], suf_str[i]);
            // printf("%d\n", max_pre);
            if (max_pre > ans_len || (max_pre == ans_len && ans_pos < max(suf_str[j].length(), suf_str[i].length()))) {
                if (max_pre <= abs(suf_str[j].length() - suf_str[i].length())) {
                    ans_len = max_pre;
                    ans_pos = max(suf_str[j].length(), suf_str[i].length());
                    ans = suf_str[i].subString(0, max_pre);
                }
            }
        }
    }

    if (ans_len != -1 && ans_len != 0) {
        ans.print();
        printf(" %d\n", len_tmp - ans_pos);
    } else {
        printf("-1\n");
    }

    // for (int i = 0; i < len_tmp; i++) {
    //     suf_str[i].print();
    //     printf("\n");
    // }
    return 0;
}