#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "LINE[" << __LINE__ << "]: " << #v << " = " << (v) << endl;
int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    uint8_t genomes[2*N][M];
    for (int i = 0; i < 2*N; ++i) {
        for (int j = 0; j < M; ++j) {
            char x;
            cin >> x;
            switch (x) {
                case 'A' :
                    genomes[i][j] = 1;
                    break;
                case 'C':
                    genomes[i][j] = 1 << 1;
                    break;
                case 'G':
                    genomes[i][j] = 1 << 2;
                    break;
                case 'T':
                    genomes[i][j] = 1 << 3;
                    break;
                default:
                    cerr  << "Char not satisfied!" << endl;
            }
        }
    }

    int count = 0;
    for (int j = 0; j < M; ++j) {
        uint8_t x = 0;
        for (int i = 0; i < N; ++i) {
            x |= genomes[i][j];
        }
        uint8_t y = 0;
        for (int i = 0; i < N; ++i) {
            y |= genomes[i+N][j];
        }
        if ((x & y) == 0) {
            count++;
        }
    }

    cout << count;
}
