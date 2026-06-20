#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int s; // start stall idx [1:100]
    int t; // end stall idx
    int c; // cooling temperature lower bound
};
struct Air_Cond {
    int a; // start stall idx
    int b; // end stall idx
    int p; // cooling temperature
    int m; // money spent on this air-conditioner
};
int main() {
    int N, M;
    cin >> N >> M;

    vector<Cow> cows(N);
    vector<Air_Cond> airs(M);

    for (int i = 0; i < N; ++i) {
        int x,y,z;
        cin >> x >> y >> z;
        cows[i].s = x;
        cows[i].t = y;
        cows[i].c = z;
    }
    for (int i = 0; i < M; ++i) {
        int x, y, z, t;
        cin >> x >> y >> z >> t;
        airs[i].a = x;
        airs[i].b = y;
        airs[i].p = z;
        airs[i].m = t;
    }
    
    int minimal_spent = INT32_MAX;

    for (int mask = 0; mask < (1 << M); ++mask) {
        vector<int> cooling_temp(100+1, 0); // stall idx starts from 1
        int spent = 0;
        for (int air_idx = 0; air_idx < M; ++air_idx) {
            if (((1 << air_idx) & mask ) == 0) continue;
            const auto &air_cond = airs[air_idx];
            for (int stall = air_cond.a; stall <= air_cond.b; ++stall) {
                cooling_temp[stall] += air_cond.p;
            }
            spent += air_cond.m;
        }

        bool fail = false;
        for (const auto &cow : cows) {
            // check if the stalls where cows live in meet the cooling requirements
            for (int stall = cow.s; stall <= cow.t; ++stall) {
                if (cooling_temp[stall] < cow.c) {
                    fail = true;
                    break;
                }
            }
            if (fail) break;
        }
        if (!fail) {
            minimal_spent = min(minimal_spent, spent);
        }
    }

    cout << minimal_spent;

}