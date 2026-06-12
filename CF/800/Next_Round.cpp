// 158A
#include <bits/stdc++.h>
using namespace std;

// todo(2026-6-12): review, 理解“>= k-th value”
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int a[n];
    int zero_idx = n;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = x;
        if (x == 0 && zero_idx == n) zero_idx = i;
    }

    int upper = k;
    while (upper < n && a[upper] == a[k-1]) upper++;
    
    cout << min(upper, zero_idx) << endl;
}