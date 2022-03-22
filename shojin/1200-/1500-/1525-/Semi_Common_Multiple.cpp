#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long gcd(long long a, long long b) { return b ? gcd(b, a%b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

int f(int x) {
    int res = 0;
    while(x%2 == 0) {
        x /= 2;
        res++;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) {
        a[i] /= 2;
    }
    int t = f(a[0]);
    for(int i=0; i<n; i++) {
        if(f(a[i]) != t) {
            cout << 0 << endl;
            return 0;
        }
        a[i] >>= t;     // a[i] /= 2^t
    }
    m >>= t;

    long long l = 1;
    for(int i=0; i<n; i++) {
        l = lcm(l, a[i]);
        if(l > m) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << m/l - m/(2*l) << endl;
    return 0;
}