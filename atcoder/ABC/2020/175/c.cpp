#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;


bool is_prime(const unsigned n) {
    switch(n) {
        case 0:
        case 1: return false;
        case 2: return true;
    }
    if(n % 2 == 0) return false;
    for(unsigned i=3; i*i <= n; i+=2) {
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    int X, num;
    cin >> X;
    for(int i=X; i<=1000000; i++) {
        if(is_prime(i)) {
            cout << i << endl;
            return 0;
        }
    }
}