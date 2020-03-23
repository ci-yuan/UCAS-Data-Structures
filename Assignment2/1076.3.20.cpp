// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int mapp_all[5][10][17] = {
    {
        {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0}, 
        {0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0}, 
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}, 
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, 
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}
    }, {
        {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0}, 
        {0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0}, 
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}, 
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, 
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}
    }, {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}, 
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, 
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}
    }, {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}, 
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, 
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}
    }, {
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, 
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}
    }
};

const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};
const char res_ch[] = ".#*";

int row_size, column_size;
int x_start, y_start;
int dir_start, mapp_num;

class MyQue {
private:
    int que_x[500];
    int que_y[500];
    int qfront;
    int qend;
public:
    MyQue(): qfront(0), qend(0) {}
    bool empty() {
        return qfront == qend;
    }
    int frontX() {
        if (!empty()) {
            return que_x[qfront];
        }
        return -1;
    }
    int frontY() {
        if (!empty()) {
            return que_y[qfront];
        }
        return -1;
    }
    void pop() {
        if (!empty()) {
            qfront += 1;
        }
    }
    int push(int x, int y) {
        que_x[qend] = x;
        que_y[qend] = y;
        qend += 1;
    }
};

bool inMapp(int x, int y) {
    return x >= 0 && x < row_size && y >= 0 && y < column_size;
}


int main() {
    scanf("%d %d %d %d %d %d", &row_size, &column_size, &x_start, &y_start, &dir_start, &mapp_num);
    int (&mapp)[10][17] = mapp_all[mapp_num];
    int color_start = mapp[x_start][y_start];
    MyQue que;
    que.push(x_start, y_start);
    mapp[x_start][y_start] = 2;
    while (!que.empty()) {
        int xxx = que.frontX();
        int yyy = que.frontY();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int cur_dir = (i + dir_start) % 4;
            int cur_x = xxx + dx[cur_dir];
            int cur_y = yyy + dy[cur_dir];
            if (inMapp(cur_x, cur_y) && mapp[cur_x][cur_y] == color_start) {
                que.push(cur_x, cur_y);
                mapp[cur_x][cur_y] = 2;
            }
        }
    }
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < column_size; j++) {
            printf("%c", res_ch[mapp[i][j]]);
        }
        printf("\n");
    }
    return 0;
}