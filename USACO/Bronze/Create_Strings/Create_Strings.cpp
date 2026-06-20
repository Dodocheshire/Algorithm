#include <bits/stdc++.h>
using namespace std;

int n;
int count[26];
vector<string> permutation;

void search(const string &curr_str) {
    if (curr_str.length() == n) {
        permutation.push_back(curr_str);
        return;
    }

    for (int i = 0; i < 26; ++i) {
        if (::count[i]) {
            ::count[i]--;
            search(curr_str + (char)('a' + i));
            ::count[i]++;
        }
    }
}
int main() {
    string s;
    cin >> s;
    n = s.size();
    
    for (auto c : s) {
        ::count[c-'a']++;
    }

    search("");
    
    cout << permutation.size() << '\n';
    for (const auto &str: permutation) {
        cout << str << '\n';
    }
}