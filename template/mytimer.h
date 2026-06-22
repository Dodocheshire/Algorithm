#include <bits/stdc++.h>
using namespace std;

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