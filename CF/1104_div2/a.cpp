#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int prev;
        cin >> prev;
        int curr;

        int minimal = 1001;
        int sum = prev;
        for (int i = 1; i < n; ++i) {
            cin >> curr;
            if (curr > prev) { // prev is local_minimal, can be minimal
                minimal = min(prev, minimal);
            }
            sum += min(minimal, curr);
            prev = curr;
        }

        cout << sum << '\n';
    }
    
}