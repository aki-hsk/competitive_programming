#include <bits/stdc++.h>
using namespace std;

// 5で割って1余る素数の配列を作る
// 上の配列から任意の５個を選べば必ず5の倍数になる

int main() {
    vector<int> p;
    int n;
    cin >> n;
    for(int i=3; i<=55555; i+=2) {
        bool prime = true;
        for(int j=2; j*j<=i; j++) {
            if(i%j == 0) prime = false;
        }
        if(!prime) continue;
        if(i % 5 == 1)p.push_back(i);
    }
    for(int i=0; i<n; i++) cout << p[i] << endl;
}