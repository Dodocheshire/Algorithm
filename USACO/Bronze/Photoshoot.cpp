// ! hard
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    string s;
    cin >> N >> s;
    string prev;
    int flip = 0;
    for (int i = 0; i <= N-2; i += 2) {
        string curr = {s[i+0], s[i+1]};
        if (curr == "GG" || curr == "HH") continue;
        if (curr == prev) continue;
        flip++;
        prev = curr; 
    }
    if (prev == "HG") flip--; // 最后一块是'好块',可以少翻转一次

    cout << flip << endl;

}