#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Node {
    Node * llink;
    Node * rlink;
    int address;
    int size_k;
    Node(int addr, int size_k): address(addr), size_k(size_k) {
        llink = this;
        rlink = this;
    }
    Node * link(Node * xx) {
        this->rlink = xx;
        if (xx) {
            xx->llink = this;
        }
        return xx;
    }
    Node * insert(Node * xx) {
        xx->link(this->rlink);
        this->link(xx);
        return xx;
    }
};
Node * free_list[32];


void delete_node(Node * xx) {
    if (free_list[xx->size_k] == xx) {
        free_list[xx->size_k] = xx->rlink;
    }
    if (free_list[xx->size_k] == xx) {
        free_list[xx->size_k] = NULL;
    }
    xx->llink->link(xx->rlink);
    delete xx;
}

Node * insert_node(int addr, int size_k) {
    Node * new_node;
    if (free_list[size_k]) {
        if (free_list[size_k]->address > addr) {
            new_node = free_list[size_k]->llink->insert(new Node(addr, size_k));
            free_list[size_k] = new_node;
        } else {
            Node * pp;
            for (pp = free_list[size_k]->rlink; pp != free_list[size_k]; pp = pp->rlink) {
                if (pp->address > addr) {
                    break;
                }
            }
            new_node = pp->llink->insert(new Node(addr, size_k));
        }
    } else {
        new_node = free_list[size_k] = new Node(addr, size_k);
    }
    return new_node;
}

Node * merge(Node * xx) {
    if (xx == NULL) {
        return NULL;
    }
    Node * buddy;
    int buddy_addr, new_addr;
    if (xx->address % (1 << (xx->size_k + 1)) == 0) {
        buddy = xx->rlink;
        buddy_addr = xx->address + (1 << xx->size_k);
        new_addr = xx->address;
    } else if (xx->address % (1 << (xx->size_k + 1)) == (1 << xx->size_k)) {
        buddy = xx->llink;
        buddy_addr = xx->address - (1 << xx->size_k);
        new_addr = buddy_addr;
    } else {
        // printf("### NULL\n");
        return NULL;
    }
    if (buddy->size_k != xx->size_k || buddy->address != buddy_addr) {
        // printf("### NULL\n");
        return NULL;
    }
    // printf("### %d: %d, %d\n", xx->size_k, xx->address, buddy->address);
    Node * new_node = insert_node(new_addr, xx->size_k + 1);
    delete_node(xx);
    delete_node(buddy);
    new_node = merge(new_node);
    return new_node;
}

void print_free_list() {
    // printf("======================================\n");
    for (int i = 0; i < 31; i++) {
        if (free_list[i]) {
            printf("%d", i);
            printf(" %d", free_list[i]->address);
            for (Node * pp = free_list[i]->rlink; pp != free_list[i]; pp = pp->rlink) {
                printf(" %d", pp->address);
            }
            printf("\n");
        }
    }
    // printf("======================================\n");
}

int main() {
    char line_str[110];
    char * tmp_str;
    while (fgets(line_str, 100, stdin)) {
        if (strcmp(line_str, "\n") == 0) {
            break;
        }
        tmp_str = strtok(line_str, " ");
        int kkk;
        sscanf(tmp_str, "%d", &kkk);
        while (tmp_str = strtok(NULL, " ")) {
            int addr;
            sscanf(tmp_str, "%d", &addr);
            // printf("----: %d, %d\n", kkk, addr);
            insert_node(addr, kkk);
            // print_free_list();
        }
    }
    while (fgets(line_str, 100, stdin)) {
        tmp_str = strtok(line_str, " ");
        int kkk;
        sscanf(tmp_str, "%d", &kkk);
        while (tmp_str = strtok(NULL, " ")) {
            int addr;
            sscanf(tmp_str, "%d", &addr);
            // printf("----: %d, %d\n", kkk, addr);
            merge(insert_node(addr, kkk));
            // print_free_list();
        }
    }
    print_free_list();
    return 0;
}