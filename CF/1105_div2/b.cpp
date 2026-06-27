#include<bits/stdc++.h>
using namespace std;

const int MODULUS = 998244353;
long long power(long long base, long long exp) {
    base = base % MODULUS;
    long long result = 1;
    while (exp > 0) {
        if (exp % 2) {
            result = (result * base) % MODULUS;
        }
        base = (base * base) % MODULUS;
        exp = exp >> 1;
    }
    return result;
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, m, r, c;
        cin >> n >> m >> r >> c;
        long long M = MODULUS - 1;
        long long free_vars = (n % M) * (m % M) - ((n - r + 1) % M) * ((m - c + 1) % M);
        free_vars = (free_vars + M) % M;
        long long ans = power(2, free_vars);
        cout << ans << '\n';
    }
} 