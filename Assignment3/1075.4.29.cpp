// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct linkNode {
    char ch;
    linkNode * succ;
    linkNode * nxt;
    int id;
    linkNode(char ch, int id): ch(ch), succ(NULL), nxt(NULL), id(id) { }
};

char str1[110];
char str2[110];

int main() {
    bool is_first;
    scanf("%s", str1);
    scanf("%s", str2);
    int len1 = 0;
    int len2 = 0;
    linkNode * head1 = new linkNode(0, 0);
    linkNode * head2 = new linkNode(0, 0);
    char * pch = str1;
    linkNode * ppp = head1;
    while (* pch) {
        ppp->succ = new linkNode(* pch, ++len1);
        ppp->succ->nxt = ppp;
        ppp = ppp->succ;
        pch ++;
    }
    pch = str2;
    ppp = head2;
    while (* pch) {
        ppp->succ = new linkNode(* pch, ++len2);
        ppp = ppp->succ;
        pch ++;
    }

    ppp = head2->succ;
    linkNode * ptt = head2;
    head2->succ->nxt = head2;
    while (ppp) {
        if (ptt == head2 || ppp->ch == ptt->ch) {
            ppp = ppp->succ;
            ptt = ptt->succ;
            if (!ppp) {
                break;
            }
            if (ppp->ch != ptt->ch) {
                ppp->nxt = ptt;
            } else {
                ppp->nxt = ptt->nxt;
            }
            // ppp->nxt = ptt;
        } else {
            ptt = ptt->nxt;
        }
    }

    head1 = head1->succ;
    bool ok_flg = true;
    is_first = true;
    while (ok_flg) {
        ok_flg = false;
        ppp = head1;
        ptt = head2->succ;
        while (ppp) {
            // cout << "ppp:" << ppp->id << endl;
            // cout << "ptt:" << ptt->id << endl;
            if (ptt == head2 || ppp->ch == ptt->ch) {
                if (ptt->succ) {
                    ppp = ppp->succ;
                    ptt = ptt->succ;
                } else {
                    ok_flg = true;
                    printf("%s%d", is_first? "" : " ", ppp->id - len2 + 1);
                    is_first = false;
                    break;
                }
            } else {
                ptt = ptt->nxt;
            }
        }
        if (ok_flg) {
            while (head1 && ppp && head1->id <= ppp->id - len2 + 1) {
                head1 = head1->succ;
            }
        }
    }

    // ppp = head1->succ;
    // ptt = head2->succ;
    // while (ppp) {
    //     // cout << "ppp:" << ppp->id << endl;
    //     // cout << "ptt:" << ptt->id << endl;
    //     if (ptt == head2 || ppp->ch == ptt->ch) {
    //         if (ptt->succ) {
    //             ppp = ppp->succ;
    //             ptt = ptt->succ;
    //         } else {
    //             printf("%d ", ppp->id - len2 + 1);
    //             ptt = ptt->nxt;
    //         }
    //     } else {
    //         ptt = ptt->nxt;
    //     }
    // }
    
    printf("\n");
    ptt = head2->succ;
    is_first = true;
    while (ptt) {
        printf("%s%d", is_first? "" : " ", ptt->nxt->id);
        ptt = ptt->succ;
        is_first = false;
    }
    printf("\n");
    return 0;
}