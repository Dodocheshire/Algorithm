// ! 好题
#include <bits/stdc++.h>
using namespace std;

struct Excitement {
    int parity;
    int upper;
};
int main() {
    int N;
    string S;
    cin >> N >> S;

    int base_cnt = 0;
    for (int i = 0; i <= N-2; ++i) {
        string sub = {S[i], S[i+1]};
        if (sub == "EE" || sub == "BB") base_cnt++;
    }

    // 对每个连续的'F'block维护: 
    // parity: 0表示'F'block影响的窗口可能产生的excitement值的集合为连续的自然数{0,1,2...,n}
    // parity: 1表示excitement集合为连续的奇数集{1, 3, 5, ..., 2k+1}
    // parity: 2表示exicitement集合为连续的偶数集{0, 2, 4,..., 2k}
    // upper: excitement集合中最大元素
    // 所有'F'block产生的excitement集合的闵可夫斯基和 S = S_1 + S_2 + .. + S_m(m为'F'block个数)满足:
    // 1. inf(S) = t (t为parity=1的S_i个数)
    // 2. sup(S) = sup(S_1) + sup(S_2) + .. + sup(S_m) 
    // 3. S中元素从小到大排列，则如果parity=0的集合不存在，则S相邻两个元素差为2，否则S相邻两个元素差为1
    vector<Excitement> FBlock_excitements;
    int p1 = 0, p2 = 0;
    while (p2 < S.length()) {
        while (p1 < S.length() && S[p1] != 'F') p1++;
        p2 = p1;
        while (p2 < S.length() && S[p2] == 'F') p2++;
        if (p1 == p2) break; // 没找到'F'block

        int n = p2 - p1;
        if (p1 == 0) { // 'F'block左侧没有元素
            if (p2 == S.length()) { // 'F'block右侧没有元素
                // Excitement集合是{0,1,...,n-1}
                FBlock_excitements.push_back({.parity=0, .upper=n-1});
            } else { // 'F'block右侧有元素
                // {0, 1, ..., n}
                FBlock_excitements.push_back({.parity=0, .upper=n});
            }
        } else { // 'F'block左侧有元素
            if (p2 == S.length()) { // 'F'block右侧没有元素
                FBlock_excitements.push_back({.parity=0, .upper=n});
            } else { // 'F'block右侧有元素
                if (S[p1-1] == S[p2]) { // 'F'block两侧元素相同，说明S[p1-1:p2]的E/S变换次数为偶数
                // 例如n=2, EFFE有n+1=3个len=2的字串。Excitement=n+1-k, 其中k为E/F的变换次数。k只可能是EEEE(变换0次),ESEE/ESSE/EESE(变换2次)
                // 而Excitement取值范围为{3-0, 3-2} = {1, 3}, 奇偶性与n+1一致
                    if ((n+1) % 2) {
                        FBlock_excitements.push_back({.parity=1, .upper=n+1});
                    } else {
                        FBlock_excitements.push_back({.parity=2, .upper=n+1});
                    }
                } else { // 'F'block两侧元素不同，说明S[p1-1:p2]的E/S变换次数为奇数
                    if ((n+1) % 2) {
                        FBlock_excitements.push_back({.parity=2, .upper=n});
                    } else {
                        FBlock_excitements.push_back({.parity=1, .upper=n});
                    }
                }
            }
        }

        p1 = p2;

    }

    // 根据各个excitements集合的性质计算其和S的下界，上界，相邻元素间隔
    bool continuous = false;
    int inf_S = 0;
    int sup_S = 0;
    for (const auto & excitement : FBlock_excitements) {
        if (excitement.parity == 0) {
            continuous = true;
        } 
        if (excitement.parity == 1) {
            inf_S++;
        }
        sup_S += excitement.upper;
    }

    int stride = continuous ? 1 : 2;
    cout << (sup_S - inf_S) / stride + 1 << '\n'; // 输出集合S中元素个数
    for (int elem = inf_S; elem <= sup_S; elem += (continuous ? 1 : 2)) {
        cout << elem + base_cnt << '\n';
    }

}