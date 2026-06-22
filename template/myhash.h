#include <bits/stdc++.h>
using namespace std;
// std::unordered_map默认使用std::hash,对于整数,hash(x) = x,极易造成大量hash冲突
// SplitMix64 确保即使输入数据非常接近，输出的哈希值也会天差地远
// 为自定义哈希函数引入随机种子,防止被hack

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
         x += 0x9e3779b97f4a7c15;
         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
         return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM); // 加上固定的(随机)偏移，防止被hack
    }
};

// std::unordered_map采用拉链法处理哈希冲突，插入新元素时，系统会为这个新节点单独申请一块内存(链表节点不连续)
// 这会导致cache hit 率下降

// gp_hash_table采用开放寻址，可以选择线性探测(缓存利用率高但容易一次聚集）或二次探测
// gp_hash_table默认表大小为2^k,故寻找位置时可以直接 index = hash(key) & (size - 1).

// 删除时采用"tombstones"标记来处理删除，数组中每个格子有三种可能的状态：
// 1. Empty (未使用)：从来没存过数据。 2. Occupied (已占用)：当前存有有效数据。3. Tombstone (墓碑)：以前存过数据，但现在被删除了
// 插入时，从哈希值对应的位置开始探测。如果遇到 Tombstone：记录下来，这个位置是可以被复用的。但是不能直接存进去，要继续往后找，看看key是不是已经存在于后面的某个位置，如果最后确认 Key 不存在，就把数据填入那个第一个墓碑的位置
// 当“墓碑”越来越多，查找失败的平均时间会线性上升，为了清理掉这些“墓碑”，gp_hash_table会进行 Rehash:
// 1.开辟一块新空间。 2. 遍历旧表，只把 Occupied 状态的有效元素提取出来，重新计算哈希值放入新表。3. 新表里一个“墓碑”都没有，所有空位都是 Empty

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;

// 定义允许手动 resize 的扩容策略
// 参数 1: 指数级扩容 (2^n)
// 参数 2: 负载因子触发器 (默认在 0.75 时扩容)
// 参数 3: 设置为 true 才允许调用 resize()
using Safe_Resize_Policy = hash_standard_resize_policy<
    hash_exponential_size_policy<>, // 保持默认
    hash_load_check_resize_trigger<>, // 保持默认
    true // 打开External_Size_Access
>;
using QuadHashTable = gp_hash_table<
    int64_t,                       // Key
    int,                           // Mapped (当集合用时把int换成null_type)
    custom_hash,               // Hash_Fn
    equal_to<int64_t>,             // Eq_Fn
    direct_mask_range_hashing<>,   // Comb_Probe_Fn direct_mask_range是通过hash(key) & (1<<n - 1),与操作比取余数(%)快很多
    // 传统平方探测采用f(i) = i^2(mod N)的步长,最多可能有一半的空位无法探测到. 而pbds采用三角数探测: f(i) = i(i+1)/2(mod N).
    // 如果哈希表的大小 N 是2的幂(即使用direct_mask_range_hashing),则三角数探测可以精确地遍历完数组中所有N个位置。
    // 如果采用direct_mod_range_hashing(质数表)取模, 探测序列会覆盖不全
    quadratic_probe_fn<>,           // ★ Probe_Fn = 平方探测
    // Resize_Policy默认是指数扩容，负载因子到0.75触发扩容
    Safe_Resize_Policy
>;  