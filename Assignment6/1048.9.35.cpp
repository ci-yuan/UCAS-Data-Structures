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
    bool is_thread_L;
    bool is_thread_R;
    string value;
    BTnode(): parent(NULL), son_L(NULL), son_R(NULL), is_thread_L(false), is_thread_R(false) {}
    BTnode(const string & str, BTnode * parent): value(str), parent(parent), son_L(NULL), son_R(NULL), is_thread_L(false), is_thread_R(false) {}
    void link(BTnode * xx) {
        if (!this->is_thread_R && this->son_R == NULL) {
            this->is_thread_R = true;
            this->son_R = xx;
        }
        if (!xx->is_thread_L && xx->son_L == NULL) {
            xx->is_thread_L = true;
            xx->son_L = this;
        }
    }
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

BTnode * last_visit = NULL;
BTnode * first_node = NULL;

void init_thread(BTnode * cur) {
    if (cur == NULL) {
        return;
    }
    if (cur->son_L) {
        init_thread(cur->son_L);
    }
    // cout << "###" << cur->value << endl;
    if (first_node == NULL) {
        first_node = cur;
    } 
    if (last_visit != NULL) {
        last_visit->link(cur);
    }
    last_visit = cur;
    if (cur->son_R) {
        init_thread(cur->son_R);
    }
}

int main() {
    string input_string, pp_string, qq_string;
    getline(cin, input_string);
    int tmp_1 = input_string.find_first_of(';');
    int tmp_2 = input_string.find_first_of(',', tmp_1 + 1);
    pp_string = input_string.substr(tmp_1 + 1, tmp_2 - tmp_1 - 1);
    qq_string = input_string.substr(tmp_2 + 1);
    input_string = input_string.substr(0, tmp_1);
    input_string.push_back(',');

    BTnode * root = build_BT(input_string);
    // cout << "whh1" << endl;
    init_thread(root);
    // cout << "whh2" << endl;

    bool is_first = true;
    for (BTnode * tt = first_node; tt != NULL; ) {
        // printf("233\n");
        if (tt->value > pp_string && tt->value < qq_string) {
        // if (true) {
            if (!is_first) {
                cout << ",";
            }
            is_first = false;
            cout << tt->value;
        }
        if (tt->is_thread_R) {
            // cout << "%% is thread R" << endl;
            tt = tt->son_R;
            // cout << "^^ is thread R" << endl;
        } else {
            // cout << "%% is not thread" << endl;
            tt = tt->son_R;
            while (tt && !tt->is_thread_L && tt->son_L) {
                tt = tt->son_L;
            }
            // cout << "^^ is not thread" << endl;
        }
    }
    cout << endl;

    return 0;
}