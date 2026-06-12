#include <bits/stdc++.h>
// #include "../../template/debugging.h"
using namespace std;
#ifdef LOCAL
    #define dbg(v) cout << "line[" << __LINE__ << "]: " << #v << " = " << v << endl;
#else
    #define dbg(v)  
#endif
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int x;
    cin >> n >> x;
    vector<int> p(n);

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        p[i] = num;
    }
    sort(p.begin(), p.end());
    dbg(p);

    int cnt = 0;
    int p1 = 0, p2 = 0;

    while (p2+1 < n && p[p2+1] <= x-p[0]) {
        p2++;
    }
    dbg(p2);
    cnt += n - 1 - p2;
    while (p1 < p2) {
        cnt++;
        p1++;
        p2--;
        while(p2 > p1 && p[p2] > x-p[p1]) {
            cnt++;
            p2--;
        }
        dbg(cnt);
    }
    if (p1 == p2) cnt++;

    cout << cnt << endl;
}