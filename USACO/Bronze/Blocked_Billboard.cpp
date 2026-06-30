#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;
    int x5, y5, x6, y6;
    cin >> x1 >> y1 >> x2 >> y2
        >> x3 >> y3 >> x4 >> y4
        >> x5 >> y5 >> x6 >> y6;
    int overlap1y = max(min(y6, y2) - max(y5, y1), 0);
    int overlap1x = max(min(x6, x2) - max(x5, x1), 0);
    int overlap2y = max(min(y6, y4) - max(y5, y3), 0);
    int overlap2x = max(min(x6, x4) - max(x5, x3), 0);
    int overlap1 = overlap1y * overlap1x;
    int overlap2 = overlap2y * overlap2x;
    
    int area1 = (y2-y1) * (x2-x1);
    int area2 = (y4-y3) * (x4-x3);

    cout << area2 + area1 - overlap1 - overlap2 << endl;
}