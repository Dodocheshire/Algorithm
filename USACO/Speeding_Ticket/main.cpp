#define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "line(" << __LINE__ <<  ") -> " << #v << " = " << (v) << endl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("speeding.in", "r", stdin); // comment these 2 lines on local machine
    // freopen("speeding.out", "w", stdout);

    int N = 0, M = 0;
    cin >> N >> M;
    
    int prefixSum1[N], prefixSum2[M];
    int speed1[N], speed2[M];

    int l1 = 0, l2 = 0;
    int sp1 = 0, sp2 = 0;
    for (int i = 0; i < N; ++i) {
        cin >> l1 >> sp1;
        speed1[i] = sp1;
        // dbg(speed1[i]);
        if (i == 0) {
            prefixSum1[i] = l1;
        } else {
            prefixSum1[i] = l1 + prefixSum1[i-1];
        }
        // dbg(prefixSum1[i]);
    }
    for (int i = 0; i < M; ++i) {
        cin >> l2 >> sp2;
        speed2[i] = sp2;
        // dbg(speed2[i]);
        if (i == 0) {
            prefixSum2[i] = l2;
        } else {
            prefixSum2[i] = l2 + prefixSum2[i-1];
        }
        // dbg(prefixSum2[i]);
    }
    
    assert(prefixSum1[N-1] == prefixSum2[M-1] && prefixSum1[N-1] == 100 && "last elem of prefixSum1 should = prefixSum2 = 100");
    int p1 = 0, p2 = 0;
    int maxOverSpeed = 0;
    while (p1 < N && p2 < M) {

        if (speed2[p2] - speed1[p1] > maxOverSpeed) maxOverSpeed = speed2[p2] - speed1[p1];
        if (prefixSum1[p1] < prefixSum2[p2]) {
            ++p1;
        } else if (prefixSum1[p1] > prefixSum2[p2]) {
            ++p2;
        } else {
            ++p1;
            ++p2;
        }
    
    }
    assert(p2 == M);

    cout << maxOverSpeed << endl;
    
}