#include <bits/stdc++.h>
using namespace std;

long long prefixSum[1001][1001];
long long area[1001][1001]; // area[hi][wi]: 所有大小为hi x wi的输入矩形的面积和
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, q;
    cin >> t;
    while(t--) {
        cin >> n >> q;
        // ! 这里需要将area初始化为0
        memset(area, 0, sizeof(area));
        for (int i = 0; i < n; ++i) {
            int hi, wi;
            cin >> hi >> wi;
            area[hi][wi] += hi*wi;
        }

        // 计算2D前缀和
        for (int i = 1; i < 1001; ++i) {
            for (int j = 1; j < 1001; ++j) {
                // i==0 || j==0时, prefixSum[i][j]已经是0(全局变量)
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + area[i][j];
            } 
        }

        // 处理q个查询
        while (q--) {
            int h_s, w_s, h_b, w_b;
            cin >> h_s >> w_s >> h_b >> w_b;
            if (h_b - h_s <= 1 || w_b - w_s <= 1) { // area数组在(h_s+1, w_s+1)到(h_b-1, w_b-1)之间没有面积
                cout << 0 << '\n';
                continue;
            }
            // 利用area的前缀和矩阵prefixSum求area的子矩阵和
            long long submatrix_sum = prefixSum[h_b-1][w_b-1] - prefixSum[h_s][w_b-1] - prefixSum[h_b-1][w_s] + prefixSum[h_s][w_s];
            cout << submatrix_sum << '\n';
        }
    }
}