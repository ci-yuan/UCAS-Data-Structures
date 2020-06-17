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

void clear_thread(BTnode * root) {
    if (root == NULL) {
        return;
    }
    if (root->tag_L) {
        root->tag_L = 0;
        root->son_L = NULL;
    }
    if (root->tag_R) {
        root->tag_R = 0;
        root->son_R = NULL;
    }
    clear_thread(root->son_L);
    clear_thread(root->son_R);
}

BTnode * threading_BT(BTnode * root) {
    BTnode * head_node = new BTnode();
    head_node->value = "0";
    head_node->tag_L = 0;
    head_node->tag_R = 1;
    head_node->son_L = root;
    head_node->son_R = head_node;
    pre_node = head_node;
    // printf("2222222222\n");
    initial_midorder(root);
    // printf("2222222222\n");
    pre_node->son_R = head_node;
    pre_node->tag_R = 1;
    head_node->son_R = pre_node;
}

BTnode * search_node(BTnode * head_node, string value) {
    BTnode * cur = head_node->son_L;
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

void print_result(BTnode * head_node) {
    BTnode * cur = head_node->son_L;
    while (cur != head_node) {
        while (cur->tag_L == 0) {
            cur = cur->son_L;
        }
        if (!is_first) {
            printf(";");
        }
        is_first = false;
        printf("%d,%s,", cur->tag_L, cur->son_L->value.c_str());
        printf("%d,%s", cur->tag_R, cur->son_R->value.c_str());
        // printf("---1:finish\n");
        while (cur->tag_R == 1 && cur->son_R != head_node) {
            // printf("some\n");
            cur = cur->son_R;
            
            if (!is_first) {
                printf(";");
            }
            is_first = false;
            printf("%d,%s,", cur->tag_L, cur->son_L->value.c_str());
            printf("%d,%s", cur->tag_R, cur->son_R->value.c_str());
        }
        // printf("some2\n");
        cur = cur->son_R;
    }
}

void print_mid_order(BTnode * root) {
    if (root == NULL) {
        return;
    }
    if (root->tag_L == 0) {
        print_mid_order(root->son_L);
    }
    printf("%s\n", root->value.c_str());
    if (root->tag_R == 0) {
        print_mid_order(root->son_R);
    }
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

    pp_string.push_back(',');
    qq_string.push_back(',');

    BTnode * root = build_BT(pp_string);
    
    BTnode * head_node = threading_BT(root);

    BTnode * root_2 = build_BT(qq_string);
    
    BTnode * head_node_2 = threading_BT(root_2);

    // printf("whh0\n");
    BTnode * pos = search_node(head_node, pos_string);
    printf("2333:::%s\n", pos->value.c_str());

    delete head_node;
    clear_thread(root);

    if (pos->son_L == NULL) {
        // printf("你好\n");
        pos->son_L = root_2;
        pos->tag_L = 0;
    } else {
        root_2->son_R = pos->son_L;
        root_2->son_L->tag_R = 0;
        pos->son_L = root_2;
        pos->tag_L = 0;
    }
    // printf("whh122\n");
    printf("whh122\n");
    head_node = threading_BT(root);

    printf("whh2\n");
    print_result(head_node);
    printf("\n");
    return 0;
}