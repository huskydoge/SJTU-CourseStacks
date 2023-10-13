//
// Created by 黄奔皓 on 2023/2/21.
// reference: https://zhuanlan.zhihu.com/p/296231213
#include "vector"
#include "iostream"
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF = 1e18;

/*
   NOTE:
   std::pow is for floating point numbers.
   For integers, it's better to implement one.
*/

// FIXME: reimplement with long long int
LL pow_2 (LL x) {
    return x * x;
}

struct point {
    int x, y;
    point (int _x, int _y) : x(_x), y(_y) {}
    long long distance_2 (const point & other) const {
        // TODO: implement distance_2
        return pow_2(x - other.x) + pow_2(y - other.y);
    }
};

// vector中元素按x大小从小到大，从左到右
long long solve (vector <point> &a, int l, int r) {
    // TODO: implement solve
    if(l + 1 >= r){
        return INF;
    }
    LL ret;
    int m = (l + r) / 2;
    ret = min(solve(a, l, m), solve(a, m, r));
    vector <point> strip_left;
    vector <point> strip_right;

    int i = m, j = m - 1;

    while(true){
        if((i < r ) && (pow_2(a[i].x - a[m].x)) <= ret){
            strip_right.push_back(a[i]);
            ++ i;
        } else {
            break;
        }
    }

    while(true){
        if((j >= l) && (pow_2(a[j].x - a[m].x)) <= ret){
            strip_left.push_back(a[j]);
            -- j;
        } else {
            break;
        }
    }

    sort(strip_right.begin(), strip_right.end(), [](auto &u, auto &v) {
        return u.y < v.y;
    });

    for(int i = 0; i < (strip_left).size(); ++ i){
        int l_ = 0, r_ = strip_right.size() - 1;
        while(l_ < r_){
            int m_ = l_ + r_ / 2;
            if(strip_right[m_].y < strip_left[i].y && pow_2(strip_right[m_].y- strip_left[i].y) < ret){
                r_ = m_;
            } else {
                l_ = m_ + 1;
            }
        }

        for(int s = 0 ; s < 6; ++ s){
            if(r_ + s >= strip_right.size()){
                break;
            }
            ret = min(ret, strip_left[i].distance_2(strip_right[r_ + s]));
        }
    }

    return ret;

}

int main() {
    int n;
    cin >> n;
    vector <point> a;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back(point(x, y));
    }
    sort(a.begin(), a.end(), [](auto &u, auto &v) {
        return u.x < v.x;
    });
    cout << solve (a, 0, n) << endl;
}