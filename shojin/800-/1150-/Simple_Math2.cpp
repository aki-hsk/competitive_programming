#include<iostream>
#include<vector>
using namespace std;

// https://jupiro.hatenablog.com/entry/2021/01/09/235236
// https://qiita.com/recuraki/items/40c24558eae5cc6318fa
// https://twitter.com/kyort0n/status/1348788439093706755

// 10^N = cm^2+dm+bとしたときのdが欲しい
// 10^Nをm^2で割ったあまり = dm+b
// (dm+b)/m = d これが求める値
// 10^Nをm^2で割ったあまりをmでわる
int powmod(int a, long long n, int mod) {
    int pm = 1;
    while (n > 0) {
        if (n & 1) pm = (long long)pm * a % mod;
        a = (long long)a * a % mod;
        n >>= 1;
    }
    return pm;
}


int main() {
    long long n, m;
    cin >> n >> m;
    printf("%d\n", powmod(10, n, m * m) / m % m);
    return 0;
}