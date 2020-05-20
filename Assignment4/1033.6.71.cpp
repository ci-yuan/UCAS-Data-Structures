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

void print_tree(BTnode * root, int depth) {
    for (int i = 0; i < depth; i++) {
        printf(" ");
    }
    printf("%s\n", root->value.c_str());
    if (root->son_L) {
        print_tree(root->son_L, depth + 1);
    }
    if (root->son_R) {
        print_tree(root->son_R, depth);
    }
}

int main() {
    string input_string, pp_string, qq_string;
    getline(cin, input_string);
    input_string.push_back(',');

    BTnode * root = build_BT(input_string);
    print_tree(root, 0);

    return 0;
}