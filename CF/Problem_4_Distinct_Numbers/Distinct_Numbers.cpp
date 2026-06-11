#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = 0;
    cin >> N;
    vector<int> s(N);
    for(int &x: s) cin >> x;
    sort(s.begin(), s.end());
    
    int ans = 1;
    for(int i = 1; i < N; ++i) {
        if(s[i] != s[i-1]) ans++;
    }

    cout << ans << endl;
}