// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef char DT;

struct linkNode {
    DT data;
    linkNode * next;

    linkNode() {
        data = 0;
        next = NULL;
    }
    linkNode(DT data_): data(data_) {
        next = NULL;
    }
    void insert(linkNode * p) {
        p->next = next;
        next = p;
    }
    void link(linkNode * p) {
        next = p;
    }
};

struct specialQueue {
private:
    linkNode * pp;
public:
    specialQueue() {
        pp = NULL;
    }
    bool empty() {
        return pp == NULL;
    }
    DT back() {
        if (empty()) {
            return 0;
        }
        return pp->data;
    }
    DT front() {
        if (empty()) {
            return 0;
        }
        return pp->next->data;
    }
    void push(DT x) {
        linkNode * xx = new linkNode(x);
        if (empty()) {
            xx->link(xx);
        } else {
            pp->insert(xx);
        }
        pp = xx;
    }
    void pop() {
        linkNode * xx = pp->next;
        if (xx == pp) {
            pp = NULL;
            delete xx;
        } else {
            pp->link(xx->next);
            delete xx;
        }
    }
};

int main() {
    specialQueue sq;
    int n, tt;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d,", &tt);
        sq.push(tt);
    }
    char str[110];
    int cnt = 0;
    while (!sq.empty()) {
        cnt += sprintf(str + cnt, "%d,", sq.front());
        sq.pop();
    }
    if (cnt) {
        str[cnt - 1] = 0;
    } else {
        str[cnt] = 0;
    }
    printf("%s\n", str);
    return 0;
}