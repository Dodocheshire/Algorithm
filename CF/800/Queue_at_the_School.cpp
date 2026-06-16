#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    string s;
    cin >> n >> t;
    cin >> s;

    for (int ti = 0; ti < t; ++ti) {
        for (int pos = 0; pos < n-1; ++pos) {
            if (s[pos] == 'B' && s[pos+1] == 'G') {
                swap(s[pos], s[pos+1]);
                pos++; // skip the boy if he has just been exchanged
            }
        }
    }
    cout << s;
}
