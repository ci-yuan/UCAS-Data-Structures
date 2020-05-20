#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct BTnode {
    BTnode * parent;
    BTnode * son_L;
    BTnode * son_R;
    int depth;
    string value;
    BTnode(): parent(NULL), son_L(NULL), son_R(NULL), depth(0) {}
    BTnode(const string & str, BTnode * parent, int depth): 
        value(str), parent(parent), son_L(NULL), son_R(NULL), depth(depth) {}
};

BTnode * build_BT(string & str) {
    int start = 0;
    int index = str.find_first_of(',', 0);
    BTnode * root = new BTnode(str.substr(start, index - start), NULL, 1);
    start = index + 1;
    index = str.find_first_of(',', start);

    queue <BTnode *> que;
    que.push(root);
    while (!que.empty()) {
        BTnode * parent = que.front();
        que.pop();

        string one_part = str.substr(start, index - start);
        if (one_part != "null") {
            BTnode * new_son_L = new BTnode(str.substr(start, index - start), parent, parent->depth + 1);
            parent->son_L = new_son_L;
            que.push(new_son_L);
        }
        start = index + 1;
        index = str.find_first_of(',', start);
        if (index == str.npos) {
            break;
        }

        one_part = str.substr(start, index - start);
        if (one_part != "null") {
            BTnode * new_son_R = new BTnode(str.substr(start, index - start), parent, parent->depth + 1);
            parent->son_R = new_son_R;
            que.push(new_son_R);
        }
        start = index + 1;
        index = str.find_first_of(',', start);
        if (index == str.npos) {
            break;
        }
    }
    return root;
}

void print_preorder(BTnode * root) {
    stack <BTnode *> stk;
    stk.push(root);
    bool is_first = true;
    while (!stk.empty()) {
        BTnode * root = stk.top();
        stk.pop();
        if (!is_first) {
            printf(",");
        }
        is_first = false;
        printf("%s", root->value.c_str());
        if (root->son_R) {
            stk.push(root->son_R);
        }
        if (root->son_L) {
            stk.push(root->son_L);
        }
    }   
    printf("\n");
}

BTnode * dfs_search(BTnode * root, string value) {
    if (root->value == value) {
        return root;
    }
    BTnode * res;
    if (root->son_L) {
        if (res = dfs_search(root->son_L, value)) {
            return res;
        }
    }
    if (root->son_R) {
        if (res = dfs_search(root->son_R, value)) {
            return res;
        }
    }
    return NULL;
}

bool check_complete(BTnode * root) {
    queue<BTnode *> que;
    que.push(root);
    while (!que.empty()) {
        BTnode * cur = que.front();
        que.pop();
        // printf("---%s\n", cur->value.c_str());

        if (cur->son_L && cur->son_R) {
            que.push(cur->son_L);
            que.push(cur->son_R);
            // printf("==here1\n");
        } else if (cur->son_R) {
            // printf("==here2\n");
            return false;
        } else {
            break;
        }
    }
    while (!que.empty()) {
        BTnode * cur = que.front();
        que.pop();
        if (cur->son_L || cur->son_R) {
            return false;
        }
    }
    return true;
}

int main() {
    string input_string, pp_string, qq_string;
    getline(cin, input_string);
    input_string.push_back(',');

    BTnode * root = build_BT(input_string);

    if (check_complete(root)) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}