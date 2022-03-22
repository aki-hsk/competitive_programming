#include<iostream>
#include<vector>
using namespace std;
const long long mod = 1e9+7;

// XORを見たら各桁ごとに考えてみる！
// https://drken1215.hatenablog.com/entry/2020/04/25/032000

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    long long res = 0;
    long long two_factor = 1;
    for(int d=0; d<60; d++) {
        long long even = 0, odd = 0;
        for(int i=0; i<n; i++) {
            if(a[i]>>d&1) ++odd;
            else ++even;
        }
        long long add = (odd * even) % mod * two_factor % mod;
        res = (res + add) % mod;
        two_factor = (two_factor * 2) % mod;
    }
    cout << res << endl;
    return 0;
}