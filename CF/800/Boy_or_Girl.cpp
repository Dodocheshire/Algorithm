// 236A
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main() {
   string s;
   cin >> s;
   unordered_set<char> cs;
   for (char c : s) {
        cs.insert(c);
   }
   if (cs.size() % 2 == 1) cout << "IGNORE HIM!";
   else cout << "CHAT WITH HER!";
}
