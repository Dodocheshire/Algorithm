#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        coins[i] = x;
    }
    sort(coins.begin(), coins.end(), greater<int>());
    int sum = accumulate(coins.begin(), coins.end(), 0);

    int cnt = 0;
    int curr_sum = 0;
    for (auto coin : coins) {
        curr_sum += coin;
        cnt++;
        if (curr_sum > sum/2) {
            cout << cnt;
            break;
        }
    }

}
