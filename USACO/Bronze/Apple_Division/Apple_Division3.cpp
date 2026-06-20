// using bitmask to iterate over subsets
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> weights(n);
    for (auto &w: weights) cin >> w;

    long long ans = INT64_MAX;
    for (int mask = 0; mask < (1 << n); ++mask) {
        long long sum1 = 0;
        long long sum2 = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) { // 第i个元素在组1
                sum1 += weights[i];
            } else {
                sum2 += weights[i];
            }
        }
        ans = min(ans, abs(sum1 - sum2));
    }

    cout << ans << endl;
    // Optionally, since the two sets are identical, we can set the last number to always be in the second set. This would translate to iterating on masks from 
    // [0: 2^{n-1}-1], instead of [0: 2^n - 1]
}