// 71A
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        if (word.size() <= 10) cout << word << '\n';
        else cout << word.front() << word.size()-2 << word.back() << '\n';
    }
}