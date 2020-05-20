#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Edge {
    int uu, vv;
    Edge * nxt;
    Edge() {}
    Edge(int uu, int vv, Edge * nxt): uu(uu), vv(vv), nxt(nxt) {}
};

Edge * AL[110];
string nodes[110];

void insert_edge(int uu, int vv) {
    AL[uu] = new Edge(uu, vv, AL[uu]);
}

void print_formula(int cur) {
    if (nodes[cur] == "+" || nodes[cur] == "-" || nodes[cur] == "*" || nodes[cur] == "/") {
        for (Edge * p = AL[cur]; p; p = p->nxt) {
            print_formula(p->vv);
        }
    }
    printf("%s", nodes[cur].c_str());
}

int main() {
    int nn;
    scanf("%d", &nn);
    for (int i = 0; i < nn; i++) {
        cin >> nodes[i];
        if (nodes[i] == "+" || nodes[i] == "-" || nodes[i] == "*" || nodes[i] == "/") {
            int t1, t2;
            cin >> t1 >> t2;
            insert_edge(i, t1);
            insert_edge(i, t2);
        }
    }
    print_formula(0);
    printf("\n");
    return 0;
}