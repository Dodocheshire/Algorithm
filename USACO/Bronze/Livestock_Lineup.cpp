#include <bits/stdc++.h>
using namespace std;

const int K = 8;
bool constraints[K][K];
bool used[K];
vector<vector<int>> solutions;
bool check_constraint(vector<int> &a) {
    assert(a.size() == K);
    bool adjacent[K][K];
    memset(adjacent, false, sizeof(adjacent));
    for (int i = 0; i < K-1; ++i) {
        adjacent[a[i]][a[i+1]] = adjacent[a[i+1]][a[i]] = true;
    }
    for (int row = 0; row < K; ++row) {
        for (int col = 0; col < row; ++col) {
            if (constraints[row][col] && !adjacent[row][col]) {
                return false;
            }
        }
    }
    return true;
}

void search(vector<int> &prefix) {
    int n = prefix.size();
    if (n == 8) {
        if (check_constraint(prefix)) {
            solutions.push_back(prefix);
        }
        return;
    }

    for (int i = 0; i < K; ++i) {
        // find an unused number
        if (used[i]) {
            continue;
        }
        used[i] = 1;
        prefix.push_back(i);
        search(prefix);
        prefix.pop_back();
        used[i] = 0;
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    vector<string> names = {
        "Bessie",
        "Buttercup",
        "Belinda",
        "Beatrice",
        "Bella",
        "Blue",
        "Betsy",
        "Sue",
    };
    sort(names.begin(), names.end()); // the cow with name `names[i]` is encoded into i
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        string s1, s2, s3, s4, s5, s6;
        cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6;
        int rid1 = find(names.begin(), names.end(), s1) - names.begin(); // rank id
        int rid2 = find(names.begin(), names.end(), s6) - names.begin();
        constraints[rid1][rid2] = constraints[rid2][rid1] = true;
    }
    // iterate over all permutations of {0,1,...,7}
    vector<int> prefix;
    search(prefix);

    for (int rid : solutions.at(0)) {
        cout << names[rid] << '\n';
    }

}