// ! review this
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);

    string s1, s2;
    cin >> s1 >> s2;
    
    auto check = [](string &str, string &qstr) {
        if (qstr.length() > str.length()) {
            return;
        }
        int n = qstr.length();
        if (str.substr(str.length() - n) == qstr) {
            str.erase(str.length() - n);
        }
    };
    string s;
    for (auto c : s1) {
        s.push_back(c);
        check(s, s2);
    }

    cout << s;
}
