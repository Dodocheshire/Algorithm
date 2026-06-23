#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    int N;
    cin >> N;
    string a, b;
    cin >> a >> b;

    int p = 0;
    int cnt = 0;
    while (p < N) {
        while (p < N && a[p] == b[p]) p++;
        if (p < N) cnt++;
        while (p < N && a[p] != b[p]) p++;
    }
    cout << cnt;
}