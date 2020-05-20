#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Edge {
    int uu, vv, ww;
    Edge * nxt;
    Edge() {}
    Edge(int uu, int vv, int ww, Edge * nxt): uu(uu), vv(vv), ww(ww), nxt(nxt) {}
};

Edge * AL[110];
int dis[110];
bool node_ok[110];

void insert_edge(int uu, int vv, int ww) {
    AL[uu] = new Edge(uu, vv, ww, AL[uu]);
}

void dijkstra(int nn, int ss) {
    memset(dis, 0x3f, sizeof(dis));
    dis[ss] = 0;
    int kk = nn;
    while (kk--) {
        int cur_node = 0;
        int cur_dis = 0x3f3f3f3f;
        for (int i = 1; i <= nn; i++) {
            if (!node_ok[i] && dis[i] < cur_dis) {
                cur_dis = dis[i];
                cur_node = i;
            }
        }
        node_ok[cur_node] = true;
        for (Edge * p = AL[cur_node]; p; p = p->nxt) {
            dis[p->vv] = min(dis[p->vv], cur_dis + p->ww);
        }
    }
}

int main() {
    int nn, ss;
    scanf("%d %d", &nn, &ss);
    int uu, vv, ww;
    while (scanf("%d-%d %d", &uu, &vv, &ww) == 3) {
        insert_edge(uu, vv, ww);
    }
    dijkstra(nn, ss);
    bool is_first = true;
    for (int i = 1; i <= nn; i++) {
        if (i == ss) {
            continue;
        }
        if (!is_first) {
            printf(",");
        }
        is_first = false;
        printf("%d", dis[i]);
    }
    printf("\n");
    return 0;
}