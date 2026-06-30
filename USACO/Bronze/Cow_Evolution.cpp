#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);

    int N;
    cin >> N;
    map<string, set<int>> cows; // cows[feature] = a set of sub-populations
    set<string> all_feats;
    for (int i = 0; i < N; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            string feature;
            cin >> feature;
            cows[feature].insert(i);
            all_feats.insert(feature);
        }
    }
    vector<string> all_feats_vec(all_feats.begin(), all_feats.end());
    for (int i = 0; i < all_feats_vec.size(); ++i) {
        for (int j = i+1; j < all_feats_vec.size(); ++j) {
            const auto &s1 = cows[all_feats_vec[i]];
            const auto &s2 = cows[all_feats_vec[j]];
            bool only_a = false, only_b = false; // 是否存在元素属于s1但不属于s2，属于s2但不属于s1
            bool both = false; // 是否存在元素同时属于s1与s2
            for (int sub_population = 0; sub_population < N; ++sub_population) {
                bool has_a = s1.count(sub_population);
                bool has_b = s2.count(sub_population);

                if (has_a && !has_b) {
                    only_a = true;
                } else if (!has_a && has_b) {
                    only_b = true;
                } else if (has_a && has_b) {
                    both = true;
                }
            }
            if (only_a && only_b && both) { // 违反进化树条件
                cout << "no" << '\n';
                return 0;
            }

        }
    }

    cout << "yes" << '\n';
}