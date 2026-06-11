#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    
    int a = 0, b = 0;
    int c = 0, d = 0;
    cin >> a >> b;
    cin >> c >> d;
    int intersect = 0;
    if (c < b && a < d) {
        if (c < a) {
            intersect = min(b, d) - a;
        } else {
            intersect = min(b, d) - c;
        }
    }
    cout <<  (d - c) + (b - a) - intersect << endl;
}