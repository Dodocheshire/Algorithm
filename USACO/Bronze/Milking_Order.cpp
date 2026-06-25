// ! review(好题)
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    int N, M, K;
    cin >> N >> M >> K;
    
    vector<int> cow_pos(N+1, 0); // pos从1开始，cow从1开始
    vector<int> hierarchy;
    bool cow1_in_hierarchy = false;
    for (int i = 0; i < M; ++i) {
        int cow;
        cin >> cow;
        hierarchy.push_back(cow);
        if (cow == 1) cow1_in_hierarchy = true;
    }
    vector<int> pos_cow(N+1, 0);
    for (int i = 0; i < K; ++i) {
        int cow, pos;
        cin >> cow >> pos;
        pos_cow[pos] = cow;
        cow_pos[cow] = pos;
    }

    if (cow1_in_hierarchy) {
        int p = 1; // point to pos_cow
        int i = 0; // point to hierarchy
        while (1) {
            if (cow_pos[hierarchy[i]] > 0) {
                if (hierarchy[i] == 1) {
                    cout << cow_pos[1] << endl;
                    return 0;
                } else {
                    p = cow_pos[hierarchy[i]] + 1;
                    i++;
                    continue;
                }
            }
            if (pos_cow[p] > 0) {
                p++;
                continue;
            }

            if (hierarchy[i] == 1) {
                cout << p;
                return 0;
            } else {
                pos_cow[p] = hierarchy[i];
                cow_pos[hierarchy[i]] = p;
            }
            p++;
            i++;
        }
    } else {
        // 反向安放hierarchy中的奶牛(位置从后往前找)
        int p = N;
        int i = M-1;
        while (i >= 0) {
            while (i >= 0 && cow_pos[hierarchy[i]] > 0) {
                p = cow_pos[hierarchy[i]] - 1;
                i--;
            }
            while (pos_cow[p] > 0) {
                p--;
            }
            if (i >= 0) {
                pos_cow[p] = hierarchy[i];
                cow_pos[hierarchy[i]] = p;
                p--;
                i--;
            }
        }
       
        for (int p = 1; p <= N; ++p) {
            if (pos_cow[p] == 0) {
                cout << p << endl;
                return 0;
            }
        }
    }


}