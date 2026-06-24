#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--) {
        int N;
        int A, B;
        cin >> N >> A >> B;
        vector<string> picture(N); // each row has N elem {W, G, B}
        vector<vector<int>> stars(N, vector(N, 0));
        for (int i = 0; i < N; ++i) {
            cin >> picture[i];
        }

        bool bad = false;
        for (int row = N-1; row >=0; --row) {
            for (int col = N-1; col >= 0; --col) {
                switch (picture[row][col]) {
                    case 'W':
                        break;
                    case 'G':
                        if (stars[row][col]) break;
                        if (row - B >= 0 && col - A >= 0) { // 尝试让第一张图片的星星位移生成第二张图(row, col)处的'G'
                            if (picture[row-B][col-A] != 'W') {
                                stars[row-B][col-A] = 1;
                                break;
                            }
                        }
                        stars[row][col] = 1;
                        break;
                    case 'B':
                        stars[row][col] = 1; // 第一张图(row, col)处必须有星星
                        
                        if (row - B >= 0 && col - A >= 0) { // 尝试让第一张图片的星星位移生成第二张图(row, col)处的星星
                            if (picture[row-B][col-A] != 'W') {
                                stars[row-B][col-A] = 1;
                                break;
                            }
                        }
                        // 如果第一张图的星星无法位移生成第二张图(row, col)处的星星
                        bad = true;
                        goto EXIT;
                }
            }
        }

        EXIT:
        if (bad) {
            cout << -1 << '\n';
            continue;
        }
        // 统计第一张图的星星数
        int count = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (stars[i][j]) {
                    count++;
                }
            }
        }
        cout << count << '\n';
    }
}