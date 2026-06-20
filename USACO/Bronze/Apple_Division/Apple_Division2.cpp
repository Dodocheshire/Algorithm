// recursive solution (考虑第index个元素是否加入第一组)
#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> weights;

long long recurse_apples(int index, long long sum1, long long sum2) {
    // We've added all apples- return the absolute difference
    if (index == n) {
        return abs(sum1 - sum2);
    }

    // 分别考虑第index个apple分到第一组和第二组的情况
    return min(recurse_apples(index + 1, sum1 + weights[index], sum2), recurse_apples(index + 1, sum1, sum2 + weights[index]));
}

int main() {
    cin >> n;
    weights.resize(n);
    for (int i = 0; i < n; ++i) cin >> weights[i];
    // Solve the problem starting at apple 0 with both sets being empty
    cout << recurse_apples(0, 0, 0) << endl;
}