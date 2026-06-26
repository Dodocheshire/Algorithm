#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    
    int N, M;
    cin >> N >> M;
    vector<int> adjacent[N+1 + M]; // pasture numbered from 1, cow numbered from 1+N to N+M

    for (int i = 0; i < M; ++i) {
        int pasture1, pasture2;
        cin >> pasture1 >> pasture2;
        adjacent[i+1+N].push_back(pasture1);
        adjacent[i+1+N].push_back(pasture2);
        adjacent[pasture1].push_back(i+1+N);
        adjacent[pasture2].push_back(i+1+N);
    }

    vector<int> colors(1+N, 0);
    for (int p = 1; p <= N; ++p) {
        // select a color different from relevant pastures(whose color is selected)
        unordered_set<int> to_exclude;
        for (int x : adjacent[p]) { // 遍历吃这片草的所有牛
            // 获得cow的吃的另一个草地
            int pasture1 = adjacent[x][0], pasture2 = adjacent[x][1];
            int another_pasture = (pasture1 == p) ? pasture2 : pasture1;
            if (colors[another_pasture] > 0) { // 颜色确定的草地的颜色需排除
                to_exclude.insert(colors[another_pasture]); // to_exclude大小最多为3,因为一片草地最多被3头牛吃
            }
        }
        // 从小到大选择一个可选的颜色(总能做到,因为to_exclude大小<=3)
        for (int color = 1; color <= 4; ++color) {
            if (to_exclude.count(color) == 0) {
                colors[p] = color;
                break;
            }
        }

    }
    for (int i = 1; i <= N; ++i) {
        cout << colors[i];
    }
}