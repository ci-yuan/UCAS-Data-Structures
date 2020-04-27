// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

// 根据题集的要求实现了 StringType，虽然要 AC 这道题不需要这么麻烦……

class StringType {
private:
    char * str;
    int len;
public:
    StringType(): str(NULL), len(0) {}
    // for StrAssign
    StringType(const char * new_str) {
        len = strlen(new_str);
        str = new char[len + 1];
        memcpy(str, new_str, len);
        str[len] = 0;
    }
    StringType(const char * new_str, int new_len) {
        len = new_len;
        str = new char[len + 1];
        memcpy(str, new_str, len);
        str[len] = 0;
    }
    StringType(const StringType & new_str) {
        len = new_str.len;
        str = new char[len + 1];
        memcpy(str, new_str.str, len);
        str[len] = 0;
    }
    StringType & operator = (const StringType & new_str) {
        len = new_str.len;
        str = new char[len + 1];
        memcpy(str, new_str.str, len);
        str[len] = 0;
        return *this;
    }
    ~StringType() {
        delete[] str;
    }
    void print() {
        printf("%s", str);
    }
    // for StrLength
    int length() {
        return len;
    }
    // for StrCompare
    static int compare(const StringType & a, const StringType & b) {
        for (int i = 0; i <= min(a.len, b.len); i++) {
            if (a.str[i] != b.str[i]) {
                return a.str[i] - b.str[i];
            }
        }
        return 0;
    }
    // for Concat
    static StringType concat(const StringType & s, const StringType & t) {
        StringType res;
        res.str = new char[s.len + t.len];
        memcpy(res.str, s.str, s.len);
        memcpy(res.str + s.len, t.str, t.len);
        res.len = s.len + t.len;
        res.str[res.len] = 0;
        return res;
    }
    // for SubString
    StringType subString(int start, int sub_len) const {
        StringType res(str + start, sub_len);
        return res;
    }
};

char tmp_str[210];

int main() {
    fgets(tmp_str, 210, stdin);
    StringType str(tmp_str);
    StringType res = "";
    for (int i = 0; i < str.length() - 1; i++) {
        res = StringType::concat(str.subString(i, 1), res);
    }
    res.print();
    printf("\n");
    return 0;
}