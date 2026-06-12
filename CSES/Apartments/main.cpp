#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;

    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0; i < n+m; ++i) {
        int x;
        cin >> x;
        if(i < n) {
            a[i] = x;
        } else {
            b[i-n] = x;
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int p1 = 0, p2 = 0;
    int n_matches = 0;
    while(p1 < n && p2 < m) {
        if (a[p1] < b[p2] - k) {
            p1++;
        } else if (a[p1] > b[p2] + k) {
            p2++;
        } else {
           n_matches++;
           p1++;
           p2++; 
        }
    }

    cout << n_matches << endl;
}