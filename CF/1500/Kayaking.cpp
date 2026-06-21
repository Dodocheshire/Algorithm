#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> w(2*n);
    for (int i = 0; i < 2*n; ++i) {
        cin >> w[i];
    }
    sort(w.begin(), w.end());

    int optimal_sum = INT32_MAX;
    for (int i = 0; i < 2*n; ++i) { // iterate over the deleted 2 person
        for (int j = i+1; j < 2*n; ++j) {
            int sum = 0;
            int p = 0, q = 0;
            while (1) {
                while (p == i || p == j) {
                    p++;
                }
                q = p+1;
                while (q == i || q == j) {
                    q++;
                }
                if (p >= 2*n) break;
                sum += abs(w[p] - w[q]);
                p = q+1;
            }
            optimal_sum = min(optimal_sum, sum);
        }
    }

    cout << optimal_sum;
}