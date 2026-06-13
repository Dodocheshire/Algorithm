#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "line[" << __LINE__ << "]: " << #v << " = "  << (v) << endl;

vector<long long> solve(char a[], int n) {
    int p1 = 0, p2 = n-1;
    int mid = (n-1)/2;
    int k = 0;
    
    long long sum = 0;
    vector<long long> result(n); // 记录至多改变k个朝向时的sum值
    for (int i = 0; i < n; ++i) {
        if (a[i] == 'L') {
            sum += i;
        } else {
            sum += n-1-i;
        }
    }

    while (p1 <= mid && p2 > mid) {
        if (a[p1] == 'R') {
            p1++;
            continue;
        }
        if (a[p2] == 'L') {
            p2--;
            continue;
        }
        // 这里a[p1] == 'L', a[p2] == 'R'
        if (p1 + p2 <= n-1) { // 改变a[p1]朝向看到的人数增加的更多
            int deltaSum = (n-1-p1) - p1;
            sum += (long long)deltaSum;
            p1++;
        } else { // 改变a[p2]朝向看到的人数增加的更多
            int deltaSum = p2 - (n-1-p2);
            sum += (long long)deltaSum;
            p2--;
        }
        result[k] = sum;
        k++; // 更新已改变朝向的人数
    }

    while (p1 <= mid) {
        if (a[p1] == 'R') {
            p1++;
            continue;
        }
        int deltaSum = (n-1-p1) - p1;
        sum += (long long)deltaSum;
        result[k] = sum;
        p1++;
        k++;
    }
    while (p2 > mid) {
        if (a[p2] == 'L') {
            p2--;
            continue;
        }
        int deltaSum = p2 - (n-1-p2);
        sum += (long long)deltaSum;
        result[k] = sum;
        p2--;
        k++;
    }
    for (int i = k; i < n; ++i) { // 此时无法通过继续改变朝向来增加sum值
        result[i] = sum;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        char dir[n];
        for (int i = 0; i < n; ++i) {
            char x;
            cin >> x;
            dir[i] = x;
        }
        vector<long long> ret = solve(dir, n);
        for (int i = 0; i < n; ++i) {
            if (i == n-1) {
                cout << ret[i] << '\n';
                continue;
            }
            cout << ret[i] << ' ';
        }
    }   
}