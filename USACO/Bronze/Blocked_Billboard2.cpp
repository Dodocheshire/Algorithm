#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int bl_1x, bl_1y, ur_1x, ur_1y; // 第一个广告牌的左下角和右上角坐标
    int bl_2x, bl_2y, ur_2x, ur_2y; // 第一个广告牌的左下角和右上角坐标
    cin >> bl_1x >> bl_1y >> ur_1x >> ur_1y
        >> bl_2x >> bl_2y >> ur_2x >> ur_2y;

    int area;
    if (bl_1x >= bl_2x && ur_1x <= ur_2x) {
        int ylen;
        if (ur_2y >= ur_1y) {
            ylen = max(min(bl_2y, ur_1y) - bl_1y, 0);
        } else if (bl_2y <= bl_1y) {
            ylen = max(ur_1y - max(ur_2y, bl_1y), 0);
        } else {
            ylen = ur_1y - bl_1y;
        }
        area = ylen * (ur_1x - bl_1x);
    } else if (bl_1y >= bl_2y && ur_1y <= ur_2y) {
        int xlen;
        if (bl_2x <= bl_1x) {
            xlen = max(ur_1x - max(ur_2x, bl_1x), 0);
        } else if (ur_2x >= ur_1x) {
            xlen = max(min(bl_2x, ur_1x) - bl_1x, 0);
        } else {
            xlen = ur_1x - bl_1x;
        }
        area = xlen * (ur_1y - bl_1y);
    } else {
        area = (ur_1x - bl_1x) * (ur_1y - bl_1y);
    }

    cout << area << endl;
}