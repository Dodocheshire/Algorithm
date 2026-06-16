// ! review (hard)
#include <bits/stdc++.h>
#include <tuple>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    int N;
    cin >> N;
    vector<tuple<int, int, int>> ecows; // <x, y, id>
    vector<tuple<int, int, int>> ncows; // <x, y, id>
    for (int i = 0; i < N; ++i ) {
        char dir;
        cin >> dir;
        int x, y;
    
        cin >> x >> y;
        if (dir == 'E') {
            ecows.push_back({x, y, i});
        } else {
            ncows.push_back({x, y, i});
        }
    }

    sort(ecows.begin(), ecows.end(), [](const auto &a, const auto &b) {
            return get<1>(a) < get<1>(b);
            });
    sort(ncows.begin(), ncows.end(), [](const auto &a, const auto &b) {
            return get<0>(a) < get<0>(b);
            });

    vector<int> stop_pos(N, -1);
    for (const auto &ec: ecows) {
        for (const auto &nc: ncows) {
            if (get<0>(ec) < get<0>(nc) && get<1>(ec) > get<1>(nc)) {
                int e_trav = get<0>(nc) - get<0>(ec);
                int n_trav = get<1>(ec) - get<1>(nc);
                // east cow blocks the north cow
                if (e_trav < n_trav && stop_pos[get<2>(nc)] == -1) {
                    stop_pos[get<2>(nc)] = get<1>(ec);
                }
                // north cow blocks the east cow (only if north cow is still moving)
                if (n_trav < e_trav && stop_pos[get<2>(nc)] == -1) { // ! Bug
                    stop_pos[get<2>(ec)] = get<0>(nc);
                    // ec has found a stop position, so check next ec(remaining nc has x larger than current nc.x, so can not be blocked by this ec)
                    break; 
                }
            }
        }
    }

    vector<int> dist(N, -1);
    for (const auto &ec : ecows) {
        if (stop_pos[get<2>(ec)] != -1) {
            dist[get<2>(ec)] = stop_pos[get<2>(ec)] - get<0>(ec);
        }
    }
    for (const auto &nc : ncows) {
        if (stop_pos[get<2>(nc)] != -1) {
            dist[get<2>(nc)] = stop_pos[get<2>(nc)] - get<1>(nc);
        }
    }

    for (int i = 0; i < N; ++i) {
        if (dist[i] == -1) {
            cout << "Infinity" << '\n';
        } else {
            cout << dist[i] << '\n';
        }
    }

}
