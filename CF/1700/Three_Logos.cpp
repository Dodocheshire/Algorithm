// ! review
#include <bits/stdc++.h>
using namespace std;

const int K = 3;

int main() {
    vector<pair<int, int>> logos(K);
    int area = 0;
    for (int i = 0; i < K; ++i) {
        int xi, yi;
        cin >> xi >> yi;
        logos[i].first = xi;
        logos[i].second = yi;
        area += xi*yi;
    }
    int n = (int)round(sqrt((double)area));
    while (n*n > area) --n;
    while ((n+1)*(n+1) <= area) ++n; // biggest n s.t. n*n <= area
    if (n*n != area) {
        cout << "-1";
        return 0;
    }

    // iterate over {000, 001, ..., 111}: 8 types of rotation configuration, which maps (x_i, y_i) -> (w_i, h_i){i=1,2,3}
    // only 2 arrangements which we need to check
    //  a) h_{i_1} + h_{i_2} = h_{i_3} = n and w_{i_1} = w_{i_2} (search for i_3 = 1,2,3), where {i_1,i_2,i_3} is permutation of {1,2,3}
    // b)  h_1 + h_2 + h_3 = n and w_1 = w_2 = w_3 (only one case)

    for (int rotate_mask = 0; rotate_mask < (1 << K); ++rotate_mask) {
        vector<int> h(K), w(K);
        for (int i = 0; i < K; ++i) {
            h[i] = logos[i].first; w[i] = logos[i].second;
            if ((1 << i) & rotate_mask) {
                swap(h[i], w[i]);
            }
        }
        // now we get (h_i, w_i), check case_a first
        // bool f1 = (h[1] + h[2] == h[0] == n) 
        //         && (w[1] == w[2]);
        // bool f2 = (h[0] + h[2] == h[1] == n) 
        //         && (w[0] == w[2]);
        // bool f3 = (h[0] + h[1] == h[2] == n) 
        //         && (w[0] == w[1]);
        int sum_h = 0;
        map<int, int> cnt;
        for (int i = 0; i < 3; ++i) {
            sum_h += h[i];
            cnt[w[i]]++;
        }
        char ans[n][n];
        memset(ans, 'x', sizeof(ans));

        for (int i = 0; i < 3; ++i) {
            cnt[w[i]]--;
            if (cnt[w[i]] == 0) cnt.erase(w[i]);
            bool w_eq = (cnt.size()==1);
            bool case_a = (sum_h - h[i] == h[i]) && (h[i] == n) && w_eq;
            if (case_a) {
                
                for (int row = 0; row < n; ++row) {
                    for (int col = 0; col < w[i]; ++col)
                        ans[row][col] = 'A' + i;
                }
                int row_start = 0;
                int col_start = w[i];
                for (int j = 0; j < 3; ++j) {
                    if (j == i) continue;
                    for (int row = row_start; row < row_start + h[j]; ++row) {
                        for (int col = col_start; col < col_start + w[j]; ++col) {
                            ans[row][col] = 'A' + j;
                        }
                    }
                    row_start += h[j];
                }

                cout << n << '\n';
                for (int row = 0; row < n; ++row) {
                    for (int col = 0; col < n; ++col) {
                        cout << ans[row][col];
                    }
                    cout << '\n';
                }
                return 0;
            }
            cnt[w[i]]++;
        }

        bool case_b = (h[0] + h[1] + h[2] == n)
                    && (w[0] == w[1])
                    && (w[1] == w[2]);
        if (case_b) {
            cout << n << '\n';
            for (int i = 0; i < 3; ++i) {
                for (int row_offset = 0; row_offset < h[i]; ++row_offset) {
                    for (int col = 0; col < n; ++col) {
                        cout << (char)('A' + i);
                    }
                    cout << '\n';
                }
            }
            return 0;
        }

    }

    cout << -1;
}