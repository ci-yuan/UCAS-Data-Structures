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

void print_tree_mid(BTnode * cur, bool & is_first) {
    if (cur == NULL) {
        return;
    }
    print_tree_mid(cur->son_L, is_first);
    if (!is_first) {
        cout << ",";
    }
    is_first = false;
    cout << cur->value;
    print_tree_mid(cur->son_R, is_first);
}

void insert_node(BTnode * &root, BTnode * xx) {
    if (root == NULL) {
        root = xx;
        xx->son_L = NULL;
        xx->son_R = NULL;
        return;
    }
    if (xx->value < root->value) {
        insert_node(root->son_L, xx);
    } else {
        insert_node(root->son_R, xx);
    }
}

void merge_tree(BTnode * pp, BTnode * qq) {
    if (qq == NULL) {
        return;
    }
    merge_tree(pp, qq->son_L);
    merge_tree(pp, qq->son_R);
    insert_node(pp, qq);
}

int main() {
    string input_string, pp_string, qq_string;
    getline(cin, input_string);
    int tmp_1 = input_string.find_first_of(';');
    pp_string = input_string.substr(0, tmp_1);
    qq_string = input_string.substr(tmp_1 + 1);

    pp_string.push_back(',');
    qq_string.push_back(',');
    BTnode * pp_root = build_BT(pp_string);
    BTnode * qq_root = build_BT(qq_string);

    merge_tree(pp_root, qq_root);
    bool is_first = true;
    print_tree_mid(pp_root, is_first);
    cout << endl;
    return 0;
}