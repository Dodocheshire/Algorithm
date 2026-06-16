#include <bits/stdc++.h>
#include <cstdint>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    vector<string> spot(N);
    vector<string> plain(N);
    
    auto id = [](char c) {
        switch (c) {
            case 'A':
                return (uint8_t)0;
                break;
            case 'C':
                return (uint8_t)1;
                break;
            case 'G':
                return (uint8_t)2;
                break;
            case 'T':
                return (uint8_t)3;
                break;
            default:
                cerr << "unimplemented" << endl;
        }
    };
    auto hash = [id](char a, char b, char c) {
        return (uint8_t)((id(a) << 4) | (id(b) << 2) | id(c));
    };
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        spot[i] = s;
    }
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        plain[i] = s;
    }
    
    int explains = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = i + 1; j < M; ++j) {
            for (int k = j + 1; k < M; ++k) {
                unordered_set<int> m1;
                for (int r = 0; r < N; ++r) {
                    uint8_t hashId = hash(spot[r][i], spot[r][j], spot[r][k]);
                    m1.insert(hashId);
                }
                unordered_set<int> m2;
                for (int r = 0; r < N; ++r) {
                    uint8_t hashId = hash(plain[r][i], plain[r][j], plain[r][k]);
                    m2.insert(hashId);
                }
                // check if m1 intersect with m2
                auto disjoint = [&](auto &&self, unordered_set<int> &_m1, unordered_set<int> &_m2) -> bool {
                    if (_m1.size() > _m2.size()) return self(self, _m2, _m1);
                    for (const auto &v : _m1) {
                        if (_m2.count(v)) {
                            return false;
                        }
                    }
                    return true;
                };
                if (disjoint(disjoint, m1, m2)) {
                    explains++;
                }

            }
        }
    }

    cout << explains;
}
