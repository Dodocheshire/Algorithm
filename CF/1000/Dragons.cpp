#include <bits/stdc++.h>
using namespace std;

struct Dragon {
    int x;
    int y;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s, n;
    cin >> s >> n;
    vector<Dragon> d(n);
    for (int i = 0; i < n; ++i) {
        int xi, yi;
        cin >> xi >> yi;
        d[i].x = xi;
        d[i].y = yi;
    }
    sort(d.begin(), d.end(), [](auto &a, auto &b) {
                return a.x < b.x;
                });

    for (auto dragon : d) {
        if (s <= dragon.x) {
            cout << "NO";
            return 0;
        }
        s += dragon.y;
    }

    cout << "YES";
    
}
