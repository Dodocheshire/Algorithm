#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int N;
    cin >> N;
    const int T = 26;
    int freq[T] = {};
    memset(freq, 0, sizeof(freq));

    for (int i = 0; i < N; ++i) {
        string front, back;
        cin >> front;
        cin >> back;
        int cnt1[T] = {};
        memset(cnt1, 0, sizeof(cnt1));
        int cnt2[T] = {};
        memset(cnt2, 0, sizeof(cnt2));
        for (auto c : front) {
            cnt1[c - 'a']++;
        }
        for (auto c : back) {
            cnt2[c - 'a']++;
        }
        for (int k = 0; k < T; ++k) {
            freq[k] += max(cnt1[k], cnt2[k]);
        }
    }

    for (int i = 0; i < T; ++i) {
        cout << freq[i] << '\n';
    }
}
