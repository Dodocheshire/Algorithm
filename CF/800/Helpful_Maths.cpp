#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    vector<int> nums;
    for (auto c : s) {
        if (c!='+') {
            nums.push_back(c - '0');
        }
    }
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
        if (i==0) {
            cout << nums[i];
            continue;
        }
        cout << '+' << nums[i];
    }
}
