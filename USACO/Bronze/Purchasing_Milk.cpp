// ! 难写
#include <bits/stdc++.h>
// #include "myprint.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q; // 1 <= N <= 10^5

    const int LIM = 31; // x <= 1e9 < 2^30, so keep deals 2^0 through 2^30.
    vector<long long> costs(LIM);
    for (int i = 0; i < N; ++i) {
        long long deal_cost;
        cin >> deal_cost;
        if (i == 0) {
            costs[i] = deal_cost;
        } else if (i < LIM){
            costs[i] = min(deal_cost, costs[i - 1] << 1);
        } else {
            costs[LIM-1] = min(costs[LIM-1], deal_cost);
        }
    }
    for (int i = N; i < LIM; ++i) {
        costs[i] = costs[i-1] << 1;
    }

    while (Q--) {
        long long x;
        cin >> x;
        
        long long ans = LLONG_MAX;
        long long cur = 0;

        for (int i = LIM - 1; i >= 0; --i) {
            long long bit = (x >> i) & 1;
            if (bit) {
                cur += costs[i];
            } else {
                // ! 可以选择补一个更大的deal，那么后面的deal都可以不考虑
                ans = min(ans, cur + costs[i]);
            }
        }

        ans = min(ans, cur); // 恰好买了x个milk的情况
        cout << ans << '\n';
    }


}
