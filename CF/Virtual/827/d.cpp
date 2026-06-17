// 位置枚举 -> 值域枚举
// ! review
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int M = 1000;
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> pos(M+1, -1); // last pos in input of value x: pos[x] (1<=x<=100)
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            pos[x] = i+1;
        }

        int max_sum = -1;
        for (int x = 1; x <= M; ++x) {
            for (int y = 1; y <= M; ++y) {
                if (pos[x] != -1 && pos[y] != -1 && gcd(x, y) == 1) {
                    max_sum = max(max_sum, pos[x] + pos[y]);
                }
            }
        }

        cout << max_sum << '\n';
    }
}
