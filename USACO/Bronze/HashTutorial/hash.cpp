// ! tutorial
#include <bits/stdc++.h>
#include <cstdint>
#include "myhash.h" // ! 阅读myhash.h
using namespace std;

// 我们来对 1. 默认哈希的std::unordered_map 2. 使用splitmix64哈希函数的std::unordered_map 3. 配合二次探测，掩码和splitmix64的QuadHashTable 进行性能评估
// 计时辅助函数
struct Timer {
    string name;
    chrono::high_resolution_clock::time_point start;
    Timer(string n) : name(n), start(chrono::high_resolution_clock::now()) {}
    ~Timer() {
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cout << name << " took: " << dur << " ms" << endl;
    }
};

void run_benchmark(int N) {
    cout << "--- Benchmarking with N = " << N << " operations ---" << endl;

    // 准备测试数据：生成 N 个随机 64 位整数
    vector<int64_t> keys(N);
    mt19937_64 rng(1337); // 固定种子保证公平
    for (int i = 0; i < N; ++i) keys[i] = rng();

    // 1. 测试原生 std::unordered_map
    {
        unordered_map<int64_t, int> umap;
        Timer t("1. std::unordered_map (Default)");
        for (int i = 0; i < N; ++i) umap[keys[i]] = i;
        for (int i = 0; i < N; ++i) if (umap[keys[i]] != i) exit(1);
        for (int i = 0; i < N; ++i) umap.erase(keys[i]);
    }

    // 2. 测试安全 std::unordered_map (配合 custom_hash)
    {
        unordered_map<int64_t, int, custom_hash> safe_umap;
        Timer t("2. std::unordered_map (custom_hash)");
        for (int i = 0; i < N; ++i) safe_umap[keys[i]] = i;
        for (int i = 0; i < N; ++i) if (safe_umap[keys[i]] != i) exit(1);
        for (int i = 0; i < N; ++i) safe_umap.erase(keys[i]);
    }

    // 3. 测试 QuadHashTable
    {
        QuadHashTable qtable;
        // qtable.resize(10000000); // 可选，减少中间扩容申请内存的时间
        Timer t("3. QuadHashTable (PBDS + custom_hash + Mask + Quad)");
        for (int i = 0; i < N; ++i) qtable[keys[i]] = i;
        for (int i = 0; i < N; ++i) if (qtable[keys[i]] != i) exit(1);
        for (int i = 0; i < N; ++i) qtable.erase(keys[i]);
    }
    cout << endl;
}

int main() {
    run_benchmark(200000);
    
    run_benchmark(1000000);

    run_benchmark(10000000);
}
