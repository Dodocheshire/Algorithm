#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int X = 0;

    while (n--) {
        char a, b, c;
        cin >> a >> b >> c;
        if (b=='+') X++;
        else X--;
    }
    cout << X << flush;
}

