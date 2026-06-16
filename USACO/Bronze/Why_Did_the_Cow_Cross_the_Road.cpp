#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    
    const int N = 52;
    vector<int> start(N/2, -1), end(N/2, -1);
    for (int i = 0; i < N; ++i) {
       char x;
       cin >> x;
       if (start[x-'A'] == -1) {
           start[x-'A'] = i;
       } else {
           end[x-'A'] = i;
       }
    }

    int count = 0;
    for (int i = 0; i < N/2; ++i) {
        for (int j = 0; j < N/2; ++j) {
            if (start[i] < start[j] && start[j] < end[i] && end[i] < end[j]) {
                count++;
            }
        }
    }
    cout << count;
}
