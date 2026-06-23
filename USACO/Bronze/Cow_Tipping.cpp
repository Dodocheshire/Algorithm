#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    int N;
    cin >> N;
    vector<string> cows;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        cows.push_back(s);
    }
    auto flip = [&](int r, int c) {
        for (int i = 0; i <= r; ++i) {
            for (int j = 0; j <= c; ++j) {
                cows[i][j] = (cows[i][j] == '0') ? '1' : '0';
            }
        }
    };
    int ans = 0;
    for (int row = N-1; row >= 0; --row) {
        for (int col = N-1; col >= 0; --col) {
            if (cows[row][col] == '1') {
                ans++;
                flip(row, col);
            }
        }
    }

    cout << ans;
}