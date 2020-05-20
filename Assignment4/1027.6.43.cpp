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
    string value;
    BTnode(): parent(NULL), son_L(NULL), son_R(NULL) {}
    BTnode(const string & str, BTnode * parent): value(str), parent(parent), son_L(NULL), son_R(NULL) {}
};

BTnode * build_BT(string & str) {
    int start = 0;
    int index = str.find_first_of(',', 0);
    BTnode * root = new BTnode(str.substr(start, index - start), NULL);
    start = index + 1;
    index = str.find_first_of(',', start);

    queue <BTnode *> que;
    que.push(root);
    while (!que.empty()) {
        BTnode * parent = que.front();
        que.pop();

        string one_part = str.substr(start, index - start);
        if (one_part != "null") {
            BTnode * new_son_L = new BTnode(str.substr(start, index - start), parent);
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
            BTnode * new_son_R = new BTnode(str.substr(start, index - start), parent);
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

void exchange_sons(BTnode * root) {
    BTnode * tmp = root->son_L;
    root->son_L = root->son_R;
    root->son_R = tmp;
    if (root->son_R) {
        exchange_sons(root->son_R);
    }
    if (root->son_L) {
        exchange_sons(root->son_L);
    }
}

int main() {
    string input_string;
    getline(cin, input_string);
    input_string.push_back(',');
    BTnode * root = build_BT(input_string);
    exchange_sons(root);
    print_preorder(root);
    return 0;
}