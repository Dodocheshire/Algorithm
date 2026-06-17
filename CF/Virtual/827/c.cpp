#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 8;
    int t;
    cin >> t;

    while (t--) {
        vector<string> m;
        for (int i = 0; i < N; ++i) {
            string row;
            cin >> row;
            m.push_back(row);
        }
        
        // check each row
        bool found_row = false;
        for (int r = 0; r < N; ++r) {
            if (count(m[r].begin(), m[r].end(), 'R') == N) {
                found_row = true;
                break;
            }
        }
        if (found_row) {
            cout << 'R' << '\n';
        } else { // else there must be a col with the same color
            cout << 'B' << '\n';
        }
    }

}

