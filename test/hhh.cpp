#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int ttttt(int n) {
    int count = 0;
    int x = 2;
    while (x < n / 2) {
        x *= 2;
        count ++;
    }
    return count;
}

int main() {
    int aaa;
    while (scanf("%d", &aaa) == 1) {
        printf("ans: %d\n", ttttt(aaa));
    }
    return 0;
}