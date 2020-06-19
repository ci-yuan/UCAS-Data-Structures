#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
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

bool check_BT(BTnode * root) {
    if (root == NULL) {
        return true;
    }
    bool res = true;
    res = res && (root->son_L == NULL || root->son_L->value <= root->value);
    res = res && (root->son_R == NULL || root->value <= root->son_R->value);
    res = res && check_BT(root->son_L);
    res = res && check_BT(root->son_R);
    return res;
}


int main() {
    string input_string;
    getline(cin, input_string);
    input_string.push_back(',');
    BTnode * root = build_BT(input_string);
    // cout << "asdf" << endl;
    printf("%d\n", check_BT(root) ? 1 : 0);
    return 0;
}