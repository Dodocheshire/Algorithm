#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    int n, k;
    cin >> t;
    
    while (t--) {
        cin >> n >> k;
        int c = 0;
        while (k * ((1 << (c+1)) - 1) <= n) c++;
        int x = k * ((1 << c) - 1);
        int ans = k*c + (n - x) / (1 << c);
        cout << ans << '\n';
    }

}