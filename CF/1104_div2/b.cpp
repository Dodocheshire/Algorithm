// hard+ (不会写)
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[i] = x;
        }
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            b[i] = x;
        }
        auto a_sorted = a;
        sort(a_sorted.begin(), a_sorted.end());

        bool skip = false;
        for (int i = 0; i < n; ++i) {
            if (a_sorted[i] > b[i]) {
                skip = true;
            }
        }
        if (skip) {
            cout << "-1" << '\n';
            continue;
        }

        vector<int> used(n, 0);
        for (int j = 0; j < n; ++j) {
            int min_i;
            for (int i = 0; i < n; ++i) {
                if (!used[i] && a[i] <= b[j]) {
                    min_i = i;
                    used[i] = 1;
                    break;
                }
            }
            a[min_i] = b[j];
        }

        int reverse = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (a[i] > a[j]) {
                    reverse++;
                }
            }
        }

        cout << reverse << '\n';
    }
    
}