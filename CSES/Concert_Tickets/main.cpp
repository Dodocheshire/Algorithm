#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    multiset<int> tickets;
    int t[m];

    for (int i = 0; i < n+m; ++i) {
        int x;
        cin >> x;
        if (i < n) {
            tickets.insert(x);
        } else {
            t[i-n]  = x;
        }
    }

    for (int i = 0; i < m; ++i) {
        auto it = tickets.upper_bound(t[i]);
        if(it == tickets.begin()) {
            cout << -1 << '\n';
        } else {
            --it;
            cout << *it << '\n';
            tickets.erase(it);
        }
    }
}