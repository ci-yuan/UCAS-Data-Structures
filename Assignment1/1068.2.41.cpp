// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct linkNode {
    int aa, pw;
    linkNode * next, * pre;
    linkNode() {
        aa = 0;
        pw = 0;
        next = NULL;
        pre = NULL;
    }
    linkNode(int aa_, int pw_): aa(aa_), pw(pw_) {
        next = NULL;
        pre = NULL;
    }
};

void printpppitem(linkNode * item, bool is_first, bool is_end) {
    if (item->aa < 0) {
        printf("- ");
    } else if (!is_first) {
        printf("+ ");
    }
    int aa_abs = abs(item->aa);
    if (aa_abs != 1 || item->pw == 0) {
        printf("%d", aa_abs);
    }
    if (item->pw == 1) {
        printf("x");
    } else if (item->pw != 0) {
        printf("x^%d", item->pw);
    }
    if (is_end) {
        printf("\n");
    } else {
        printf(" ");
    }
}

void printppp(linkNode * ppp) {
    linkNode * p;
    int flg = 0;
    for (p = ppp->next; p != ppp; p = p->next) {
        printpppitem(p, p == ppp->next, p->next == ppp);
        flg = 1;
    }
    if (!flg) {
        printf("0\n");
    }
}

void link2(linkNode * p, linkNode * q) {
    if (p) {
        p->next = q;
    }
    if (q) {
        q->pre = p;
    }
}

void link3(linkNode * p, linkNode * x, linkNode * q) {
    if (p) {
        p->next = x;
    }
    if (q) {
        q->pre = x;
    }
    x->pre = p;
    x->next = q;
}

void insertppp(linkNode * ppp, linkNode * item) {
    linkNode * p;
    for (p = ppp->next; p != ppp; p = p->next) {
        if (p->pw <= item->pw) {
            break;
        }
    }
    if (p != ppp && p->pw == item->pw) {
        p->aa += item->aa;
        delete item;
        if (p->aa == 0) {
            link2(p->pre, p->next);
            delete p;
        }
    } else {
        link3(p->pre, item, p);
    }
}

void ppp2ap(char * str, int & aan, int & pwn) {
    int len = strlen(str);
    int px = -1;
    for (int i = 0; i < len; i++) {
        if (str[i] == 'x') {
            px = i;
            str[i] = 0;
            break;
        }
    }
    if (px == 0) {
        aan = 1;
    } else {
        sscanf(str, "%d", &aan);
    }
    if (px == -1) {
        pwn = 0;
    } else if (str[px + 1] == '^') {
        sscanf(str + px + 2, "%d", &pwn);
    } else {
        pwn = 1;
    }
}

linkNode * readppp() {
    linkNode * ppp = new linkNode;
    link2(ppp, ppp);
    int sgn = 1;
    int aan, pwn;
    char str[30];
    while (scanf("%s", str) == 1) {
        if (str[0] == '+') {
            sgn = 1;
            continue;
        } else if (str[0] == '-') {
            sgn = -1;
            continue;
        }
        ppp2ap(str, aan, pwn);
        aan *= sgn;
        linkNode * item = new linkNode(aan, pwn);
        insertppp(ppp, item);
    }
    return ppp;
}

void diffppp(linkNode * ppp) {
    linkNode * p, * p_next;
    for (p = ppp->next; p != ppp; p = p_next) {
        p_next = p->next;
        if (p->pw == 0) {
            link2(p->pre, p->next);
            delete p;
        } else {
            p->aa *= p->pw;
            p->pw -= 1;
        }
    }
}

int main() {
    linkNode * ppp = readppp();
    diffppp(ppp);
    printppp(ppp);
    return 0;
}