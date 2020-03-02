// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct linkNode {
    int v;
    linkNode* nxt;
    linkNode() {
        v = 0;
        nxt = NULL;
    }
    linkNode(int x): v(x) {
        nxt = NULL;
    }
};

void printll(linkNode * a) {
    if (a->v == 0 || !a->nxt) {
        printf("NULL\n");
        return;
    }
    a = a->nxt;
    while(a->nxt) {
        printf("%c,", a->v);
        a = a->nxt;
    }
    printf("%c\n", a->v);
}

int main() {
    char ch;
    linkNode * lla = new linkNode;
    linkNode * llb = new linkNode;
    linkNode * llc = new linkNode;
    linkNode * p = lla;
    while ((ch = getchar()) != EOF && ch != ';') {
        if (ch != ',') {
            p->nxt = new linkNode(ch);
            lla->v += 1;
            p = p->nxt;
        }
    }
    p = llb;
    while ((ch = getchar()) != EOF && ch != ';') {
        if (ch != ',') {
            p->nxt = new linkNode(ch);
            llb->v += 1;
            p = p->nxt;
        }
    }
    p = llc;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch != ',') {
            p->nxt = new linkNode(ch);
            llc->v += 1;
            p = p->nxt;
        }
    }
    // printll(lla);
    // printll(llb);
    // printll(llc);

    linkNode * pa = lla->nxt;
    linkNode * pa_prv = lla;
    linkNode * pb = llb->nxt;
    linkNode * pc = llc->nxt;
    while (pa && pb && pc) {
        // printf("---%c %c %c\n", pa->v, pb->v, pc->v);
        if (pa->v == pb->v && pa->v == pc->v) {
            // printf("===1\n");
            pa_prv->nxt = pa->nxt;
            delete pa;
            pa = pa_prv->nxt;
        } else if (pa->v < pb->v && pa->v < pc->v) {
            // printf("===2\n");
            pa_prv = pa;
            pa = pa->nxt;
        } else if (pb->v < pc->v) {
            // printf("===3\n");
            pb = pb->nxt;
        } else {
            // printf("===4\n");
            pc = pc->nxt;
        }
    }
    printll(lla);
    return 0;
}