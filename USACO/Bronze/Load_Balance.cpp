// ! review
#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int n, B;
    cin >> n >> B;

    int x[n], y[n];
    for (int i = 0; i < n; ++i) {
        int loc_x, loc_y;
        cin >> loc_x >> loc_y;
        x[i] = loc_x;
        y[i] = loc_y;
    }
    
    int minM = n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int xi = x[i] + 1;
            int yj = y[j] + 1;
            int ld = 0, rd = 0, lu = 0, ru = 0;
            for (int k = 0; k < n; ++k) {
                if (x[k] < xi && y[k] < yj) ld++;
                if (x[k] > xi && y[k] < yj) rd++;
                if (x[k] < xi && y[k] > yj) lu++;
                if (x[k] > xi && y[k] > yj) ru++;
            }
            int M = max(max(ld, rd), max(lu, ru));
            minM = min(M, minM);
        }
    }

    cout << minM;
}