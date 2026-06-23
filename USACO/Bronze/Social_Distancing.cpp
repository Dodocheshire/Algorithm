// ! review 二分答案法
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);
    int N;
    string s;
    cin >> N >> s;

    vector<int> cows;
    for (int i = 0; i < N; i++) {
        if (s[i] == '1') cows.push_back(i);
    }

    // 判断最小间距为 D 时，能否再放入 2 头新奶牛
    auto canPlace = [&](int D) -> bool {
        int count = 0;
        if (cows.empty()) return N - 1 >= D;
        // 左侧空区间：位置 0 到 cows[0] 之前，每隔 D 放一头
        count += cows[0] / D;
        // 相邻已有奶牛之间的间隔内能插入的数量
        for (int i = 1; i < (int)cows.size(); i++) {
            count += max(0, (cows[i] - cows[i - 1]) / D - 1);
        }
        // 右侧空区间：cows.back() 之后，每隔 D 放一头
        count += (N - 1 - cows.back()) / D;
        return count >= 2;
    };

    int lo = 1, hi = N - 1, ans = 0;
    // 已有牛之间的最小距离是 D 的上界
    for (int i = 1; i < (int)cows.size(); i++) {
        hi = min(hi, cows[i] - cows[i - 1]);
    }
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (canPlace(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
