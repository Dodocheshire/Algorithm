#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 0; i < min(s1.size(), s2.size()); ++i) {
        char a = tolower(s1[i]);
        char b = tolower(s2[i]);
        if (a < b) {
            cout << -1;
            return 0;
        } else if (a > b) {
            cout << 1;
            return 0;
        }
    }
    if (s1.size() > s2.size()) {
        cout << 1;
    } else if (s1.size() < s2.size()) {
        cout << -1;
    } else {
        cout << 0;
    }
    return 0;
}
