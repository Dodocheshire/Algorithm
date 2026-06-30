#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);

    int N;
    string x, y;
    cin >> N >> x >> y;
    map<string, string> pTree;
    for (int i = 0; i < N; ++i) {
        string child, parent;
        cin >> parent >> child;
        pTree[child] = parent;
    }

    vector<string> x_ascendants, y_ascendants; // include x, y itself
    
    for (string node_x = x; !node_x.empty(); node_x = pTree[node_x]) {
        x_ascendants.push_back(node_x);
    }
    for (string node_y = y; !node_y.empty(); node_y = pTree[node_y]) {
        y_ascendants.push_back(node_y);
    }

    auto find_intersect = [](const vector<string> &a, const vector<string> &b){
        int i = a.size() - 1;
        int j = b.size() - 1;
        int len = 0;
        while (i >= 0 && j >= 0 && a[i] == b[j]) {
            len++;
            i--;
            j--;
        }
        return len; 
    };
    int len = find_intersect(x_ascendants, y_ascendants);
    if (len == 0) { // 没有公共祖先
        cout << "NOT RELATED" << endl;
        return 0;
    }
    int start_x = x_ascendants.size() - len, start_y = y_ascendants.size() - len;
    if (start_y < start_x) { // 为方便讨论，调整x辈分比y高
        swap(start_x, start_y);
        swap(x, y);
    }

    string relation;
    if (start_x == 0) { // x 是 y的直系祖先
        for (int i = 0; i < start_y-2; ++i) {
            relation.append("great-");
        }
        if (start_y > 1) relation.append("grand-");
        relation.append("mother");
    } else if (start_x == 1 && start_y == 1) {
        cout << "SIBLINGS" << endl;
        return 0;
    } else if (start_x == 1 && start_y >= 2) {
        for (int i = 0; i < start_y-2; ++i) {
            relation.append("great-");
        }
        relation.append("aunt");
    } else {
        cout << "COUSINS" << endl;
        return 0;
    }

    cout << x << " is the " << relation << " of " << y;
}