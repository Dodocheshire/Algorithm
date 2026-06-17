// ! review 只用维护两个性质
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) {
        int q;
        cin >> q;
        
        bool otherS = false; // s是否有非'a'字符
        bool otherT = false;
        long long sizeS = 1;
        long long sizeT = 1;
        while (q--) {
            int type, k;
            string x;
            cin >> type >> k >> x;
            bool has_other = false;
            for (char c : x) {
                if (c != 'a') {
                    has_other = true;
                    break;
                }
            }
            if (type == 1) {
                sizeS += 1LL * k * x.length(); // 强制提升
                if (has_other) otherS = true;
            }
            if (type == 2) {
                sizeT += 1LL * k * x.length(); 
                if (has_other) otherT = true;
            }

            if (otherT) {
                cout << "YES" << '\n';
                continue;
            } else {
                if (otherS) {
                    cout << "NO" << '\n';
                    continue;
                }
                cout << (sizeS < sizeT ? "YES" : "NO") << '\n';
            }

        }
        
    }
}
