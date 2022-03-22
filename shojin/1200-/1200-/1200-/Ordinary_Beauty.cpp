#include<iostream>
using namespace std;

// https://qiita.com/drken/items/3fe1613c44de1f3bfbe1
// 期待値の線形性

int main() {
    long long n, m, d;
    cin >> n >> m >> d;
    double res;
    if(d == 0) res = (double)(m-1)/n;
    else res =  (double)(m-1) * 2 * (n-d) / n / n;
    printf("%.20f\n", res);
}