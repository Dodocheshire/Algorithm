#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "line[" << __LINE__ << "]: " << #v << " = "  << (v) << endl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;
    while(cin >> n) {
        vector<string> g1(n), g2(n), g3(n);
        unordered_map<string, int> count;
        for (int i = 0; i < 3*n; ++i) {
            string x;
            cin >> x;
            count[x]++;
            if (i < n) {
                g1[i] = x;
            } else if (i < 2*n) {
                g2[i-n] = x;
            } else {
                g3[i-2*n] = x;
            }
        }
        
        int score1 = 0, score2 = 0, score3 = 0;
        for (int i = 0; i < n; ++i) {
            if (count[g1[i]] == 1) {
                score1 += 3;
            } else if (count[g1[i]] == 2) {
                score1 += 1;
            }
            
            if (count[g2[i]] == 1) {
                score2 += 3;
            } else if (count[g2[i]] == 2) {
                score2 += 1;
            }

            if (count[g3[i]] == 1) {
                score3 += 3;
            } else if (count[g3[i]] == 2) {
                score3 += 1;
            }
        }
        cout << score1 << ' ' << score2 << ' ' << score3 << '\n';
    }
}