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

void print_not_less_than(BTnode * root, const string & xx, bool & is_first) {
    if (root == NULL) {
        return;
    }
    print_not_less_than(root->son_R, xx, is_first);
    if (root->value >= xx) {
        if (!is_first) {
            cout << ",";
        }
        is_first = false;
        cout << root->value.c_str();
        print_not_less_than(root->son_L, xx, is_first);
    }
}

int main() {
    string input_string, xx_string;
    getline(cin, input_string);
    int tmp_1 = input_string.find_first_of(';');
    xx_string = input_string.substr(tmp_1 + 1);

    input_string = input_string.substr(0, tmp_1);
    input_string.push_back(',');
    BTnode * root = build_BT(input_string);
    bool is_first = true;
    print_not_less_than(root, xx_string, is_first);
    cout << endl;
    return 0;
}