#include<iostream>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a%b) : a; }

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long g = gcd(a, gcd(b, c));
    cout << a/g + b/g + c/g - 3 << endl;
}