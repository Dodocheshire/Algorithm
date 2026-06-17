#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> s(n);
        vector<long long> prefix_sum(n); // height

        int x;
        cin >> x;
        s[0] = x;
        prefix_sum[0] = x;
        for (int i = 1; i < n; ++i) {
            int x;
            cin >> x;
            s[i] = max(s[i-1], x);
            prefix_sum[i] = prefix_sum[i-1] + x;
        }

        for (int i = 0; i < q; ++i) {
            int query;
            cin >> query;
            auto it = upper_bound(s.begin(), s.end(), query);
            int available_step = it - s.begin();
            long long available_height = available_step ? prefix_sum[available_step-1] : 0;
            if (i < q-1) {
                cout << available_height << ' ';
            } else {
                cout << available_height << '\n';
            }
        }
        
    }

}
