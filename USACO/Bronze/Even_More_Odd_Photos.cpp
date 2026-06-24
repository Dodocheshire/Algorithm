#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;
    int oddNum = 0;
    int evenNum = 0;
    for (int i = 0 ;i < N; ++i) {
        int x;
        cin >> x;
        if (x%2) {
            oddNum++;
        } else {
            evenNum++;
        }
    }
    int ans = -1;
    if (evenNum >= oddNum) {
        ans = min(2*oddNum+1, evenNum+oddNum);
    } else {
        if ((2*evenNum + oddNum) % 3 == 0) {
            ans = (2*evenNum + oddNum) / 3 * 2;
        } else if ((2*evenNum + oddNum) % 3 == 1) {
            ans = (2*evenNum + oddNum) / 3 * 2 - 1;
        } else {
            ans = (2*evenNum + oddNum) / 3 * 2 + 1;
        }
    }
    cout << ans << endl;
}