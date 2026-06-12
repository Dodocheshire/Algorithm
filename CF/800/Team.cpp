// 231A
#include <bits/stdc++.h>
using namespace std;

inline bool maj3(int x, int y, int z) {
    return (x+y+z)/2 > 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        bool f = maj3(x,y,z);
        if (f) cnt++;
    }

    cout << cnt << endl;
}