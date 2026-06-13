#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));

    int t = 5;
    cout << t << '\n';

    while (t--) {
        int n = rand() % 1000 + 1;
        int q = rand() % 100 + 1;
        cout << n << " " << q << '\n';

        for (int i = 0; i < n; ++i) {
            int h = rand() % 1000 + 1;
            int w = rand() % 1000 + 1;
            cout << h << " " << w << '\n';
        }

        for (int i = 0; i < q; ++i) {
            int hs = rand() % 999 + 1;
            int ws = rand() % 999 + 1;
            
            int hb = hs + rand() % (1000 - hs) + 1;
            int wb = ws + rand() % (1000 - ws) + 1;

            cout << hs << " " << ws << " " << hb << " " << wb << '\n';
        }
    }
}