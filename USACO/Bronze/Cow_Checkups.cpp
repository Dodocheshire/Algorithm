// ! review 对角线分组
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int a[N], b[N];
    int P[N];
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        a[i] = x;
    }
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        b[i] = x;
        P[i] = (i > 0) ? (P[i-1] + (b[i] == a[i])) : (b[i] == a[i]);
    }

    vector<int> ans(N+1); // ans[i], match=i的窗口数
    for (int diag = 0; diag <= 2*N-2; ++diag) {
        // 以diag / 2为中心扩展窗口
        int l = diag / 2;
        int r = diag - l;
        int match = P[N-1];
        while (l >= 0 && r < N) {
            match += (a[r] == b[l]) + (a[l] == b[r]) - (a[l] == b[l]) - (a[r] == b[r]);
            ans[match]++;
            l--;
            r++;
        }

    }

    for (int i = 0; i <= N; ++i) {
        cout << ans[i] << '\n';
    }
    
}