#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        bool has_same = false;
        for (const auto &[k, v] : cnt) {
            if (v != 1) {
                has_same = true;
                break;
            }
        }
        cout << (has_same ? "NO" : "YES") << '\n';
    }
}
