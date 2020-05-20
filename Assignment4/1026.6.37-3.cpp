#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector <string> BT;

void build_BT(string & str) {
    BT.push_back("");
    int start = 0;
    int index = str.find_first_of(',', 0);
    int ii = 1;
    while (index != str.npos) {
        if (ii != 1 && BT[ii / 2] == "") {
            BT.push_back("");
        } else {
            string one_part = str.substr(start, index - start);
            if (one_part != "null") {
                BT.push_back(str.substr(start, index - start));
            } else {
                BT.push_back("");
            }
            start = index + 1;
            index = str.find_first_of(',', start);
        }
        ii += 1;
    }
    BT.push_back(str.substr(start));
}

int main() {
    string input_string;
    getline(cin, input_string);
    build_BT(input_string);
    // for (int i = 0; i < BT.size(); i++) {
    //     printf("%d: %s\n", i, BT[i].c_str());
    // }
    stack <int> stk;
    stk.push(1);
    bool is_first = true;
    while (!stk.empty()) {
        int cur_pos = stk.top();
        stk.pop();
        if (!is_first) {
            printf(",");
        }
        is_first = false;
        printf("%s", BT[cur_pos].c_str());
        if (cur_pos * 2 + 1 < BT.size() && BT[cur_pos * 2 + 1] != "") {
            stk.push(cur_pos * 2 + 1);
        }
        if (cur_pos * 2 < BT.size() && BT[cur_pos * 2] != "") {
            stk.push(cur_pos * 2);
        }
    }
    printf("\n");
    return 0;
}