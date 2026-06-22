#include <bits/stdc++.h>
#include <utility>
using namespace std;

int main() {
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    
    int N;
    cin >> N;

    unordered_map<string, int> s;
    for (int i = 0; i < N; ++i) {
        string k;
        int v;
        cin >> k >> v;
        s[k] += v;
    }
    vector<pair<int, string>> cows;
    for (auto pair : s) {
        cows.push_back(make_pair(pair.second, pair.first));
    }
    sort(cows.begin(), cows.end());

    int i = 0;
    if (cows.size() == 7) { // else some cows have milk production=0
        while (i < cows.size() && cows[i].first == cows[0].first) i++;
    }

    if (i < cows.size() && (i + 1 == cows.size() || cows[i].first != cows[i+1].first)) {
        cout << cows[i].second << endl;
    } else {
        cout << "Tie" << endl;
    }
}