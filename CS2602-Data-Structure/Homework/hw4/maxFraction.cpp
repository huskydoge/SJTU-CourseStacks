#include <iostream>
#include <queue>
using namespace std;

int n, k;

struct node {
    int numerator, denominator;
    bool operator < (const node &tmp) const {
        return 1.0 * numerator / denominator < 1.0 * tmp.numerator / tmp.denominator;
    }
};

int gcd(int numerator, int denominator) {
    return !denominator ? numerator : gcd(denominator, numerator % denominator);
}

int main(){
    cin >> n >> k;
    priority_queue<node> heap; // 大根堆 or 优先队列
    for (int i = 2; i <= n; ++i) {
        heap.push((node) {i - 1, i}); // 初始化堆内容
    }

    int numerator, denominator;
    while (k--) {
        node tmp = heap.top();
        heap.pop();
        numerator = tmp.numerator; denominator = tmp.denominator;
        if (k == 0) break;
        for (int i = numerator - 1; i >= 1; --i) {
            if (gcd(i, denominator) == 1) {
                heap.push((node) {i, denominator});
                break;
            }
        }
    }
    cout << numerator << '/' << denominator << endl;
    return 0;
}