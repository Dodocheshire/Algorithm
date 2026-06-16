#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <unordered_map>
using namespace std;

struct Entry {
    int day;
    string cow;
    int delta;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int N;
    cin >> N;
    
    vector<Entry> records;
    unordered_map<string, int> milk_output;
    milk_output["Mildred"] = 7;
    milk_output["Elsie"] = 7;
    milk_output["Bessie"] = 7;
    vector<string> displays{"Bessie", "Elsie", "Mildred"};
    for (int i = 0; i < N; ++i) {
        int day;
        string cow;
        int delta;
        cin >> day >> cow >> delta;
        Entry e {.day = day, .cow = cow, .delta = delta};
        records.push_back(e);
    }
    sort(records.begin(), records.end(), [](const auto &a, const auto &b) {
    return a.day < b.day;
            });
    
    int answer = 0;
    for (auto e : records) {
        milk_output[e.cow] += e.delta;
        int max_output = 0;
        for (const auto &[k, v] : milk_output)     {
            max_output = max(max_output, v);
        }

        vector<string> n_displays;
        for (const auto &[k, v] : milk_output) {
            if (v == max_output) {
                n_displays.push_back(k);
            }
        }
        if (n_displays != displays) answer++;
        displays = n_displays;
    }

    cout << answer;

}
