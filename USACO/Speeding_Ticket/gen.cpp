#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <set>

using namespace std;

/**
 * 生成 n 个总和为 total 的随机正整数
 * 逻辑：在 1 到 total-1 之间随机选 n-1 个不同的切分点，排序后取间距
 */
vector<int> generate_segments(int n, int total) {
    if (n == 1) return {total};
    
    set<int> cuts;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, total - 1);

    // 随机选取 n-1 个不同的位置
    while (cuts.size() < (size_t)(n - 1)) {
        cuts.insert(dis(gen));
    }

    vector<int> segments;
    int prev = 0;
    for (int cut : cuts) {
        segments.push_back(cut - prev);
        prev = cut;
    }
    segments.push_back(total - prev);
    return segments;
}

int main() {
    // 使用当前时间作为随机种子
    srand(time(0));
    random_device rd;
    mt19937 gen(rd());

    // 1. 随机生成 N 和 M 
    uniform_int_distribution<> nm_dis(1, 100);
    int N = nm_dis(gen);
    int M = nm_dis(gen);

    cout << N << " " << M << endl;

    // 2. 生成 N 个路段限制
    vector<int> road_lens = generate_segments(N, 100);
    uniform_int_distribution<> speed_dis(1, 100);
    for (int i = 0; i < N; ++i) {
        // 输出长度和限速
        cout << road_lens[i] << " " << speed_dis(gen) << endl;
    }

    // 3. 生成 M 个 Bessie 行驶段
    vector<int> bessie_lens = generate_segments(M, 100);
    for (int i = 0; i < M; ++i) {
        // 输出长度和行驶速度
        cout << bessie_lens[i] << " " << speed_dis(gen) << endl;
    }

    return 0;
}