#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int K, N;
    cin >> K >> N;
    int cow[K][N];
    for (int k = 0; k < K; ++k) {
        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;
            cow[k][i] = x-1; // cow id starts from 1; (map to 0:)
        }
    }
    int consistency[N][N];
    memset(consistency, 0, sizeof(consistency));
    for (int k = 0; k < K; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int cowi = cow[k][i];
                int cowj = cow[k][j];
                if (i < j) {
                    consistency[cowi][cowj] += 1;
                } else {
                    consistency[cowi][cowj] -= 1;
                }
            }
        }
    }

    // check non-diagnol elements of consistency is K or -K;
    int consistent_pair = 0;
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            if (col == row) continue;
            if (abs(consistency[row][col]) == K) {
                consistent_pair++; 
            }
        }
    }
    cout << consistent_pair/2; // remove duplicate pairs
}
