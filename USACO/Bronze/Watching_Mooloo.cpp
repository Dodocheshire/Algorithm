#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    long long prev;
    cin >> prev;

    long long sum = K+1;
    for (int i = 1; i < N; ++i) {
        long long curr;
        cin >> curr;
        sum += min(curr-prev, (long long)K+1);
        prev = curr;
    }
    cout << sum;
}