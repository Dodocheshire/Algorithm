#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "[line " << __LINE__ << "] " << #v << " = " << v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int N = 0;
    cin >> N;
    int swap[2*N];
    int guess[N];
    for (int i = 0; i < N; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        swap[2*i] = x;
        swap[2*i+1] = y;
        guess[i] = z;
    }
    int best_score = 0;
    for (int pos = 0; pos < 3; ++pos) {
        int score = 0;
        int c_pos = pos;
        for (int i = 0; i < N; ++i) {
            int l = swap[2*i] - 1, r = swap[2*i+1] - 1;
            if (c_pos == l) {
                c_pos = r;
            } else if (c_pos == r) {
                c_pos = l;
            }
            if (c_pos == guess[i] - 1) score++;
        }
        best_score = max(best_score, score);
    }

    cout << best_score << endl;
}