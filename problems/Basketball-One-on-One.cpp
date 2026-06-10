#include <bits/stdc++.h>

int main() {
    int A_score = 0; int B_score = 0;
    char c = '\0'; int num = 0;
    while (cin >> c >> num) {
        if (c == 'A') {
            A_score += num;
        } else {
            B_score += num;
        }
    }

    if (A_score > B_score) {
        cout << 'A' << endl;
    } else {
        cout << 'B' << endl;
    }

}