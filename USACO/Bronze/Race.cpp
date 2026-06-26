// ! review
#include <bits/stdc++.h>
#include <cassert>
#include <cstdio>
using namespace std;

// check A + (A-1) + .. + K+1 < remain, i.e. has enough time to slow down to K
bool ok(int remain, int A, int K) {
    long long A_long = (long long)A;
    long long K_long = (long long)K;
    return A_long * (A_long + 1) / 2 - K_long * (K_long + 1) / 2 < remain;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    
    int k, n;
    cin >> k >> n;

    while (n--) {
        int x;
        cin >> x; // endpoint speed limit
        int speed = 0;
        int remain = k;
        int t = 0;
        while (remain > 0) {
            if (ok(remain, speed+1, x)) {
                speed++;
            } else if (ok(remain, speed, x)) {
                speed = speed + 0;
            } else {
                assert(ok(remain, speed-1, x) && "there supposed to be enough time to slow down!");
                speed--;
            }
            remain -= speed;
            t++;
        }

        cout << t << '\n';
    }
}