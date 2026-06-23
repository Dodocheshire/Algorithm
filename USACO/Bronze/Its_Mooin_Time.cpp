// ! review
#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, F;
    cin >> N >> F;
    string s;
    cin >> s;

    vector<string> freq_patterns;
    // iterate over patterns "XYY", Y != X
    for (char X = 'a'; X <= 'z'; ++X) {
        for (char Y = 'a'; Y <= 'z'; ++Y) {
            if (Y == X) continue;

            int base_cnt = 0;
            // 统计未更改字符前的模式频率
            for (int i = 0; i+2 < N; ++i) {
                if (s[i] == X && s[i+1] == Y && s[i+2] == Y) {
                    base_cnt++;
                }
            }

            int max_delta = 0;
            // 考虑将第i个位置变为X/Y, 影响3个窗口
            for (int i = 0; i < N; ++i) {
                for (char c : {X, Y}) {
                    if (c == s[i]) continue;
                    // 统计原来3个窗口的模式频率
                    int origin_cnt = 0, after_cnt = 0;
                    for (int j = max(0, i-2); j <= min(N-3, i); j++) {
                        origin_cnt += (s[j] == X && s[j+1] == Y && s[j+2] == Y);
                        char t0 = (i == j) ? c : s[j];
                        char t1 = (i == j+1) ? c : s[j+1];
                        char t2 = (i == j+2) ? c : s[j+2];
                        after_cnt += (t0 == X) && (t1 == Y) && (t2 == Y);
                    }
                    max_delta = max(max_delta, after_cnt - origin_cnt);
                }
            }
            if (base_cnt + max_delta >= F) {
                freq_patterns.push_back({X, Y, Y});
            }

        }
    }

    sort(freq_patterns.begin(), freq_patterns.end());
    cout << freq_patterns.size() << '\n';
    for (const auto &p : freq_patterns) {
        cout << p << '\n';
    }
    
}