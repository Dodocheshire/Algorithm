#include <iostream>
using namespace std;

int x = 10;

void dbg() { cerr << "x = " << x << endl; }

int main() {
	dbg();
	x = 5000;
	dbg();
}