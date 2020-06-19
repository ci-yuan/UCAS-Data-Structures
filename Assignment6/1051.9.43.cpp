#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int max_dep;

struct Node {
    int cnt;
    char tag;
    Node * son[26];
    Node(char tag): cnt(0), tag(tag) {
        memset(son, 0, sizeof(son));
    }
};

void print_tree(Node * root, bool & is_first) {
    if (root == NULL) {
        return;
    }
    if (root->tag != '#') {
        if (!is_first) {
            cout << ",";
        }
        is_first = false;
        cout << root->cnt;
    }
    for (int i = 0; i < 26; i++) {
        print_tree(root->son[i], is_first);
    }
}

void insert_string(Node * root, string str, int dep) {
    root->cnt += 1;
    if (dep < max_dep && str.length()) {
        if (root->son[str[0] - 'a']) {
            insert_string(root->son[str[0] - 'a'], str.substr(1), dep + 1);
        } else {
            root->son[str[0] - 'a'] = new Node(str[0]);
            insert_string(root->son[str[0] - 'a'], str.substr(1), dep + 1);
        }
    }
}

void delete_string(Node * root, string str, int dep) {
    root->cnt -= 1;
    if (dep < max_dep && str.length()) {
        if (root->son[str[0] - 'a']) {
            delete_string(root->son[str[0] - 'a'], str.substr(1), dep + 1);
        }
    }
}

int main() {
    Node * root = new Node('#');

    string input_string, tmp_string;
    getline(cin, input_string);
    int tmp_p = input_string.find_first_of(';');
    tmp_string = input_string.substr(0, tmp_p);
    sscanf(tmp_string.c_str(), "%d", &max_dep);
    int tmp_q = tmp_p + 1;
    while ((tmp_p = input_string.find_first_of(';', tmp_q)) != string::npos) {
        tmp_string = input_string.substr(tmp_q, tmp_p - tmp_q);
        // cout << tmp_string << endl;
        insert_string(root, tmp_string, 0);
        tmp_q = tmp_p + 1;
    }
    tmp_string = input_string.substr(tmp_q);
    delete_string(root, tmp_string, 0);

    bool is_first = true;
    print_tree(root, is_first);
    cout << endl;
    return 0;
}