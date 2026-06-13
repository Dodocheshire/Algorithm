#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;

        vector<pair<int, int>> rect(n);

        for (int i = 0; i < n; ++i) {
            cin >> rect[i].first >> rect[i].second;
        }

        while (q--) {
            int hs, ws, hb, wb;
            cin >> hs >> ws >> hb >> wb;

            long long ans = 0;
            
            for (auto [h, w] : rect) {
                if (hs < h && h < hb && ws < w && w < wb) {
                    ans += 1LL * h * w;
                }
            }

            cout << ans << '\n';
        }
    }
}