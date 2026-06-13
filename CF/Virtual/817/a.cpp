#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
// Timur
    int t, n;
    cin >> t;
    string s;
    string s_name("Timur");
    while(cin >> n >> s) {
        unordered_set<char> name(s_name.begin(), s_name.end());
        bool match = true;
        for (auto c : s) {
            if (!name.erase(c)) {
                match = false;
                break;
            }
        }
        if (match && name.empty()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}