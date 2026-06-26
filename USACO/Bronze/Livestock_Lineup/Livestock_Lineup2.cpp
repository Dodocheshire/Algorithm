#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    
    const auto names = []() {
        vector<string> name_tmp = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
        sort(name_tmp.begin(), name_tmp.end());
        return name_tmp;
    }();
    int K = names.size();

    map<string, int> name2id;
    for (int i = 0; i < K; ++i) {
        name2id[names[i]] = i;
    }
    int N;
    cin >> N;
    vector<int> adjacent[K];
    
    for (int i = 0; i < N; ++i) {
        string trash;
        string a, b;
        cin >> a >> trash >> trash >> trash >> trash >> b;
        adjacent[name2id[a]].push_back(name2id[b]);
        adjacent[name2id[b]].push_back(name2id[a]);
    }

    bool added[K];
    memset(added, false, sizeof(added));
    vector<int> order;
    for (int i = 0; i < K; ++i) {
        if (!added[i] && adjacent[i].size() <= 1) { // 注意这里不能选相邻链的中间元素
            order.push_back(i);
            added[i] = true;
            if (adjacent[i].size() > 0) {
                int prev = i;
                int curr = adjacent[i][0];
                while (adjacent[curr].size() == 2) {
                    order.push_back(curr);
                    added[curr] = true;
                    int a = adjacent[curr][0], b = adjacent[curr][1];
                    int to = (a == prev) ? b : a;
                    prev = curr;
                    curr = to;
                }
                order.push_back(curr);
                added[curr] = true;
            }
        }
    }

    for (int node : order) {
        cout << names[node] << '\n';
    }

}