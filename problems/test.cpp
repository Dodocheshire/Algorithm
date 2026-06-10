#include <bits/stdc++.h>
using namespace std;

namespace Solution1 {

int solve(int x) { return x < 10; }

}  // namespace Solution1

namespace Solution2 {

int solve(int x) { return x < 11; }

}  // namespace Solution2

int main() {
	mt19937 rng(0);
	while (true) {
		int x = rng() % 100;
		int out1 = Solution1::solve(x);
		int out2 = Solution2::solve(x);
		if (out1 != out2) {
			cout << x << " " << out1 << " " << out2 << endl;
			exit(0);
		}
	}
}