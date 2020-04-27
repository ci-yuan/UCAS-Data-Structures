// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

struct GLNode {
    bool is_list;
    string data;
    GLNode * list;
    GLNode * nxt;
    GLNode(string data): is_list(false), data(data), nxt(NULL) { }
    GLNode(GLNode * list): is_list(true), list(list), nxt(NULL) { }
    void link(GLNode * bb) {
        bb->nxt = nxt;
        nxt = bb;
    }
    ~GLNode() { }
};

GLNode * buildGL() {
    char ch = getchar();
    string tmp_str;
    GLNode * head = new GLNode(string("0"));
    GLNode * ppp = head;
    while (ch != EOF && ch != ')' && ch != '\n') {
        if (ch == ',') {
            ch = getchar();
            continue;
        } else if (ch == '(') {
            ppp->nxt = new GLNode(buildGL());
            ppp = ppp->nxt;
            ch = getchar();
        } else {
            tmp_str = ch;
            ch = getchar();
            while (ch != ',' && ch != ')' && ch != '(') {
                tmp_str += ch;
                ch = getchar();
            }
            ppp->nxt = new GLNode(tmp_str);
            ppp = ppp->nxt;
        }
    }
    ppp = head->nxt;
    delete head;
    return ppp;
}

void printGL(GLNode * pp) {
    for (; pp; pp = pp->nxt) {
        if (pp->is_list) {
            printf("(");
            printGL(pp->list);
            printf(")");
        } else {
            printf("%s", pp->data.c_str());
        }
        if (pp->nxt) {
            printf(",");
        }
    }
}

GLNode * deleteData(GLNode * pp, string x) {
    GLNode * head = new GLNode(string("0"));
    head->nxt = pp;
    pp = head;
    while (pp->nxt) {
        if (pp->nxt->is_list) {
            pp->nxt->list = deleteData(pp->nxt->list, x);
            pp = pp->nxt;
        } else if (pp->nxt->data == x) {
            pp->nxt = pp->nxt->nxt;
        } else {
            pp = pp->nxt;
        }
    }
    pp = head->nxt;
    delete head;
    return pp;
}

int main() {
    char ch = getchar();
    string xxx;
    while (ch != ';') {
        xxx += ch;
        ch = getchar();
    }
    GLNode * head = buildGL();
    head = deleteData(head, xxx);
    printGL(head);
    printf("\n");
    return 0;
}