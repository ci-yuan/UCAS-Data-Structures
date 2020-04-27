// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int CHUNK_SIZE = 4;

struct chunk {
    char ch[CHUNK_SIZE];
    chunk * nxt;
};

char str[210];
int len;

chunk * makeChunkList(char * p_ch) {
    chunk * res = new chunk;
    chunk * ppp = res;
    int cur = 0;
    while (*p_ch) {
        if (cur >= CHUNK_SIZE) {
            ppp->nxt = new chunk;
            ppp = ppp->nxt;
            cur = 0;
        }
        ppp->ch[cur] = *p_ch;
        p_ch++;
        cur++;
    }
    return res;
}

char stk[210];
int st = 0;

int main() {
    chunk * head;
    fgets(str, 210, stdin);
    len = strlen(str);
    len -= 1;
    str[len] = 0;
    head = makeChunkList(str);
    int cur = 0;
    chunk * ppp = head;

    for (int i = 0; i < len / 2; i++) {
        stk[st++] = ppp->ch[cur];
        cur++;
        if (cur >= CHUNK_SIZE) {
            ppp = ppp->nxt;
            cur = 0;
        }
    }
    if (len % 2) {
        cur ++;
        if (cur >= CHUNK_SIZE) {
            ppp = ppp->nxt;
            cur = 0;
        }
    }
    bool ok_flg = true;
    for (int i = 0; i < len / 2; i++) {
        if (ppp->ch[cur] != stk[--st]) {
            ok_flg = false;
            break;
        }
        cur ++;
        if (cur >= CHUNK_SIZE) {
            ppp = ppp->nxt;
            cur = 0;
        }
    }
    printf("%s\n", ok_flg ? "Yes" : "No");
    return 0;
}