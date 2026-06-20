// concise solution
#include <bits/stdc++.h>
using namespace std;

const int n = 8;
int column[n];
int diag1[2*n - 1];
int diag2[2*n - 1];
int reserved[n][n];
int count = 0;

void search(int y) {
    if (y == n) {
        ::count++;
        return;
    }
    for (int x = 0; x < n; x++) {
        if (column[x] || diag1[x+y] || diag2[x-y+(n-1)] || reserved[y][x]) continue;
        column[x] = diag1[x+y] = diag2[x-y+(n-1)] = 1;
        search(y+1);
        column[x] = diag1[x+y] = diag2[x-y+(n-1)] = 0;
    }
}

int main() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            char x;
            cin >> x;
            reserved[i][j] = (x == '*');
        }
    }
    search(0);

    cout << ::count << endl;
}