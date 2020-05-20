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
    int tag_L, tag_R;
    int depth;
    string value;
    BTnode(): parent(NULL), son_L(NULL), son_R(NULL), depth(0), tag_L(0), tag_R(0) {}
    BTnode(const string & str, BTnode * parent, int depth): 
        value(str), parent(parent), son_L(NULL), son_R(NULL), depth(depth), tag_L(0), tag_R(0) {}
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

BTnode * pre_node;

void initial_midorder(BTnode * root) {
    if (root == NULL) {
        return;
    }
    initial_midorder(root->son_L);
    if (!root->son_L) {
        root->tag_L = 1;
        root->son_L = pre_node;
    }
    if (!pre_node->son_R) {
        pre_node->tag_R = 1;
        pre_node->son_R = root;
    }
    pre_node = root;
    initial_midorder(root->son_R);
}

BTnode * search_node(BTnode * head_node, string value) {
    BTnode * cur = head_node->son_R;
    while (cur != head_node) {
        while (cur->tag_L == 0) {
            cur = cur->son_L;
        }
        // printf("---1:%s\n", cur->value.c_str());
        if (cur->value == value) {
            return cur;
        }
        // printf("---1:finish\n");
        while (cur->tag_R == 1 && cur->son_R != head_node) {
            // printf("some\n");
            cur = cur->son_R;
            // printf("---2:%s\n", cur->value.c_str());
            if (cur->value == value) {
                return cur;
            }
        }
        // printf("some2\n");
        cur = cur->son_R;
    }
    return NULL;
}
bool is_first = true;

BTnode * print_result(BTnode * head_node) {
    BTnode * cur = head_node->son_R;
    while (cur != head_node) {
        while (cur->tag_L == 0) {
            cur = cur->son_L;
        }
        if (!is_first) {
            printf(";");
        }
        is_first = true;
        printf("%d,%s,", cur->tag_L, cur->son_L->value.c_str());
        printf("%d,%s", cur->tag_R, cur->son_R->value.c_str());
        // printf("---1:finish\n");
        while (cur->tag_R == 1 && cur->son_R != head_node) {
            // printf("some\n");
            cur = cur->son_R;
            
            if (!is_first) {
                printf(";");
            }
            is_first = true;
        }
        // printf("some2\n");
        cur = cur->son_R;
    }
    return NULL;
}

int main() {
    string input_string, pp_string, qq_string, pos_string;
    getline(cin, input_string);
    int start = 0;
    int index = input_string.find_first_of(';', start);
    pp_string = input_string.substr(start, index - start);
    start = index + 1;
    index = input_string.find_first_of(';', start);
    qq_string = input_string.substr(start, index - start);
    pos_string = input_string.substr(index + 1);

    input_string.push_back(',');

    BTnode * root = build_BT(pp_string);
    BTnode * head_node = new BTnode();
    head_node->value = "head";
    pre_node = head_node;
    initial_midorder(root);
    pre_node->son_R = head_node;
    head_node->son_L = pre_node;

    BTnode * root_2 = build_BT(qq_string);
    BTnode * head_node_2 = new BTnode();
    head_node_2->value = "head_2";
    pre_node = head_node_2;
    initial_midorder(root);
    pre_node->son_R = head_node_2;
    head_node_2->son_L = pre_node;

    BTnode * pos = search_node(head_node, pos_string);

    if (pos->tag_L) {
        head_node_2->son_R->son_L = pos->son_L;
        if (pos->tag_R) {
            pos->son_R = head_node_2->son_R;
        }
        head_node_2->son_L->son_R = pos;
        pos->son_L = root_2;
    } else {
        BTnode * cur = pos->son_L;
        while (cur->tag_L == 0) {
            cur = cur->son_L;
        }
        if (cur->son_L->tag_R) {
            cur->son_L->son_R = head_node_2->son_R;
        }
        head_node_2->son_R->son_L = cur->son_L;
        cur->son_L = pos;
        root_2->son_R = pos->son_L;
        pos->son_L = root_2;
    }
    print_result(head_node);
    
    return 0;
}