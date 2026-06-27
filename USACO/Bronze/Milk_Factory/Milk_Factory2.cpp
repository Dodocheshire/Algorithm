// represent the factory as a directed unweighted graph with edges from
// bi -> ai for every i.
// for every node i, start a DFS and check whether this results in every other node being visited.
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    
    int N;
    cin >> N;
    vector<int> adjacent[N+1];
    for (int i = 0; i < N-1; ++i) {
        int w1, w2;
        cin >> w1 >> w2;
        adjacent[w2].push_back(w1);
    }

    int root = -1;
    for (int v = 1; v <= N; ++v) {
        vector<int> stack;
        stack.push_back(v);
        vector<bool> visited(N+1, false);
        // dfs starts from node v:
        while (stack.size() > 0) {
            int curr = stack.back();
            stack.pop_back();
            visited[curr] = true;
            for (int neighbor : adjacent[curr]) {
                if (!visited[neighbor]) {
                    stack.push_back(neighbor);
                }
            }
        }
        // check if all nodes are visited
        bool valid = true;
        for (int i = 1; i <= N; ++i) {
            if (!visited[i]) {
                valid = false;
                break;
            }
        }

        if (valid) {
            root = v;
            break;
        }
    }

    cout << root;
}