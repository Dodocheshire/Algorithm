#include <bits/stdc++.h>
using namespace std;

void backtrack(int st_pt, long long part_sum, long long &optimal_sum, long long array_sum, vector<int>& a) {
    auto better_sum = [&](const long long &opt_sum, const long long &part_sum) {
        if( abs(array_sum - opt_sum - opt_sum) < abs(array_sum - part_sum - part_sum)) {
            return opt_sum;
        } else {
            return part_sum;
        }
    };
    optimal_sum = better_sum(optimal_sum, part_sum);

    for (int n_elem_idx = st_pt; n_elem_idx < a.size(); ++n_elem_idx) {
        backtrack(n_elem_idx + 1, part_sum + a[n_elem_idx], optimal_sum, array_sum, a);
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n);
    long long arr_sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        p[i] = x;
        arr_sum += x;
    }
    long long optimal_sum = 0; // optimal partial sum of one group
    backtrack(0, 0, optimal_sum, arr_sum, p);
    long long mini_diff = abs(arr_sum - 2 * optimal_sum);

    cout << mini_diff;
}