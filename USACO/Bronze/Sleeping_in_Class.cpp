// ! review
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int max_a = -1;
        int sum_a = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[i] = x;
            max_a = max(max_a, x);
            sum_a += x;
        }

        // 特判, 如果a全为0, sum_a % x 会崩
        if (sum_a == 0) {
            cout << 0 << '\n';
            continue;
        }
        for (int x = max_a; x <= sum_a; ++x) {
            if (sum_a % x != 0) {
                continue;
            }
            int curr_x = 0;
            bool fail = false;
            for (int i = 0; i < n; ++i) {
                curr_x += a[i];
                if (curr_x > x) {
                    fail = true;
                    break;
                }
                if (curr_x == x) { // next segment
                    curr_x = 0;
                }
            }
            if (curr_x > 0) fail = true; // 理论上不会出现这种情况, 因为x整除sum_a
            if (!fail) {
                int coalesce_cnt = n - sum_a / x;

                cout << coalesce_cnt << '\n';
                break; // 随着x增加, coalesce也增加, 不用搜索了.
            }

        }
    }
}