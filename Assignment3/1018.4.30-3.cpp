// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
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
    static int findLongestCommonStrKMP(StringType & str, StringType & ans);
};

char str_tmp[210];
int len_tmp;
StringType str;
StringType ans;

int StringType::findLongestCommonStrKMP(StringType & str, StringType & ans) {
    int nxt[210];
    int max_len = 0;
    int pos = 0;
    for (int k = 0; k < str.len; k++) {
        int i = k;
        int j = k - 1;
        nxt[k] = k - 1;
        int len = 0;
        while (i < str.len) {
            if (j == k - 1 || str.str[i] == str.str[j]) {
                i += 1;
                j += 1;
                nxt[i] = j;
                if (str.str[i] == str.str[j]) {
                    len = j - k + 1;
                } else {
                    len = j - k;
                }
            } else {
                j = nxt[j];
            }
            if (len > max_len) {
                pos = k;
                max_len = len;
            }
        }
    }
    ans = str.subString(pos, max_len);
    return pos;
}

int main() {
    scanf("%s", str_tmp);
    str = str_tmp;
    int pos = StringType::findLongestCommonStrKMP(str, ans);
    if (ans.length()) {
        ans.print();
        printf(" %d\n", pos);
    } else {
        printf("-1\n");
    }
    return 0;
}