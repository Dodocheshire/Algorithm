#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int limit[100];
    int drive[100];
    int p1 = 0, p2 = 0;
    int N, M;
    cin >> N >> M;
    int l, s;
    for (int i = 0; i < N; ++i) {
        cin >> l >> s;
        while (l--) {
            limit[p1++] = s;
        }
    }
    for (int i = 0; i < M; ++i) {
        cin >> l >> s;
        while (l--) {
            drive[p2++] = s;
        }
    }
    assert(p1 == 100 && p2 == 100);

    int maxSpOver = 0;
    for (int i = 0; i < 100; ++i) {
        maxSpOver = max(maxSpOver, drive[i] - limit[i]);
    }

    cout << maxSpOver << endl;
}