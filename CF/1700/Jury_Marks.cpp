// ! review
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    cin >> k >> n;

    unordered_set<int> prefix;
    vector<int> b(n);
    int curr_sum = 0;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        curr_sum += x;
        prefix.insert(curr_sum);
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    // 一个合法的初试分数S至少要满足"能生成第一个观察到的累积分数b[0]",即存在i,s.t. prefix[i] + S = b[0]
    // 也就是说，合法的初试分数是{S: S = b[0] - prefix[i], i=1,2...,k}的子集, 大小最多为k
    int ans = 0;
    for (int p : prefix) {
        int S = b[0] - p;
        // 检查forall j>0, exists e \in prefix, s.t. S = b[j] - e
        bool ok = true;
        for (int j = 1; j < n; ++j) {
            int target_prefix = b[j] - S;
            if (!prefix.count(target_prefix)) ok = false;
        }
        if (ok) ans++;
    }
    cout << ans;
}