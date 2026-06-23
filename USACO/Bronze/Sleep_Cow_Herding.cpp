#include <array>
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    
    array<int, 3> x;
    cin >> x[0] >> x[1] >> x[2];
    sort(x.begin(), x.end());
    int l1 = x[1] - x[0], l2 = x[2] - x[1];
    if (l1 > l2) {
        swap(l1, l2);
    }

    int min, max;
    if (l1 == 1) {
        if (l2 == 1) {
            min = 0;
        } else if (l2 == 2) {
            min = 1;
        } else {
            min = 2;
        }
    } else if (l1 == 2) {
        min = 1;
    } else {
        min = 2;
    }
    
    max = l2-1;
    cout << min << '\n';
    cout << max << '\n';

}