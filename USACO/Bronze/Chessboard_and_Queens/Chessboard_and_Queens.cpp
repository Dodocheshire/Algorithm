#include <bits/stdc++.h>
using namespace std;

bool reserved[8][8];
int ans = 0;
int col_count[8];
void backtrack(vector<int> &prefix) {
    // 检查(经过prefix最后一个皇后的)2个对角线上没有重复的皇后
    int n = prefix.size();

    if (n > 0) {
        for (int row = 0; row < n - 1; ++row) {
            if (row - prefix[row] == n-1 - prefix[n-1]) return;
            if (row + prefix[row] == n-1 + prefix[n-1]) return;
        }
    }

    if (n == 8) {
        ans++;
        return;
    }
    // 考虑下一行的皇后的列标
    for (int col = 0; col < 8; ++col ) {
        if (col_count[col] || reserved[n][col]) continue;
        col_count[col]++;
        prefix.push_back(col);
        backtrack(prefix);
        prefix.pop_back();
        col_count[col]--;
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
    vector<int> partial_solution;
    backtrack(partial_solution);

    cout << ans;
}