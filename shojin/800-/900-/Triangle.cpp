#include<iostream>
using namespace std;

int main() {
    long long s;
    cin >> s;
    const int v = 1000000000;

    // x2*y3 - x3*y2 = sとなれば良い
    // x2 = v, x3 = 1とすると
    // v*y3 - y2 = s

    // sをvで割って切り上げた値
    long long y3 = (s+v-1)/v;
    long long y2 = v*y3-s;
    cout << "0 0 " << v << " " << y2 << " 1 " << y3 << endl;
}