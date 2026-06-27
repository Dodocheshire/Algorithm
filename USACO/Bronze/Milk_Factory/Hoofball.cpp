// ! review
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);
    
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> indegree(N, 0);
    vector<int> pass_to(N, -1);
    for (int i = 0; i < N; ++i) {
        if (i == 0 && i+1 < N) {
            indegree[i+1]++;
            pass_to[i] = i+1;
        } else if (i == N-1 && i-1 >= 0) {
            indegree[i-1]++;
            pass_to[i] = i-1;
        } else {
            if (a[i+1] - a[i] < a[i] - a[i-1]) {
                indegree[i+1]++;
                pass_to[i] = i+1;
            } else {
                indegree[i-1]++;
                pass_to[i] = i-1;
            }
        }
    }

    int src_ball = 0;
    for (int i = 0; i < N; ++i) {
        if (indegree[i] == 0) {
            src_ball++;
        }
    }
    int isolate_pair = 0;
    for (int i = 0; i < N; ++i) {
        if (i < pass_to[i]) { // 防止重复计数
            if (pass_to[pass_to[i]] == i && indegree[i] == 1 && indegree[pass_to[i]] == 1) { // this is an isolated pair
                isolate_pair++;
            }
        }
    }

    int num_pass = src_ball + isolate_pair;
    cout << num_pass;

}