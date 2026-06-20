// use STL next_permutation()
/**
这可以处理包含相同成员的输入序列,例如"AAABB"的排列.
虽然在某些极端情况下（最坏情况），单次调用该函数需要交换O(N)次元素,但如果你用它从头到尾生成全部N!种排列,均摊的交换次数是常数
即生成所有N!排列的时间复杂度是O(N!)
template <class BidirectionalIterator>
bool next_permutation(BidirectionalIterator first,
                      BidirectionalIterator last) {
    if (first == last) return false;
    BidirectionalIterator i = first;
    ++i;
    if (i == last) return false;
    i = last;
    --i;

    for(;;) {
        BidirectionalIterator ii = i--;
        if (*i < *ii) {
            BidirectionalIterator j = last;
            while (!(*i < *--j));
            iter_swap(i, j);
            reverse(ii, last);
            return true;
        }
        if (i == first) {
            reverse(first, last);
            return false;
        }
    }
} */

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    vector<string> perm;
    do {
        perm.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << perm.size() << '\n';
    for (const auto &str : perm) {
        cout << str << '\n';
    }

}