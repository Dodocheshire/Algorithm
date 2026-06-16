#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int d_score = 0, a_score = 0;
    while (n--) {
        char x;
        cin >> x;
        if (x=='D') {
            d_score++;
        } else {
            a_score++;
        }
    }
    if (d_score > a_score) cout << "Danik";
    else if (d_score == a_score) cout << "Friendship";
    else cout << "Anton";
    
}



