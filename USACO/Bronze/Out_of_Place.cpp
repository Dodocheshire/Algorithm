// ! review
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> sorted_a(a);
    sort(sorted_a.begin(), sorted_a.end());

    int diff = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != sorted_a[i]) {
            diff++;
        }
    }
    int ans = max(0 , diff-1);
    cout << ans;
}