// ! 正确性证明
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    
    int N, K;
    cin >> N >> K;
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    vector<int> order(N+1);
    auto nex = [&](int pos) -> int {
        if (pos >= a1 && pos <= a2) pos = a1 + a2 - pos;
        if (pos >= b1 && pos <= b2) pos = b1 + b2 - pos;
        return pos;
    };
    for (int i = 1; i <= N; ++i) {
        int pos = i;
        pos = nex(pos);
        int c = 1;
        while (pos != i) {
            pos = nex(pos);
            c++;
        }

        int k = K % c;
        while (k--) {
            pos = nex(pos);
        }
        order[pos] = i;
    }

    for (int i = 1; i < order.size(); ++i) {
        cout << order[i] << '\n';
    }
}