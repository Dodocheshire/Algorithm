#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    int N;
    cin >> N;
    // 在树中, 存在唯一的sink X(没有出边)当且仅当其他所有节点都能到达X
    vector<int> outgoings(N, 0);
    for (int i = 0; i < N-1; ++i) {
        int w1, w2;
        cin >> w1 >> w2;
        outgoings[w1-1]++;
    }

    vector<int> sinks;
    for (int i = 0; i < N; ++i) {
        if (outgoings[i] == 0) {
            sinks.push_back(i+1);
        }
    }
    // n_sink一定 >=1
    cout << ((sinks.size() == 1) ? sinks[0] : -1);

}