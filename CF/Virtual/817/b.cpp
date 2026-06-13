#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n;
    cin >> t;
    while (cin >> n) {
        char row1[n], row2[n];
        for (int i = 0; i < 2*n; ++i) {
            char x;
            cin >> x;
            if (i < n)
                row1[i] = x;
            else 
                row2[i-n] = x;
        }

        bool same = true;
        for (int i = 0; i < n; ++i) {

            if (row1[i] == row2[i] 
                || ((row1[i] == 'G') && (row2[i] == 'B')) 
                || ((row1[i] == 'B') && (row2[i] == 'G'))) {
                } else {
                    same = false;
                    break;
                }
        }
        if (same) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}