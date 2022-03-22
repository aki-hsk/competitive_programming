#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll mod = 1000000000+7;

void func(ll N, ll tmp, int use, ll &counter) {
    if(tmp > N) return;
    if(use == 0b111) counter++;
    cout << tmp << endl;
    func(N, tmp*10+3, use|0b001, counter);
    func(N, tmp*10+5, use|0b010, counter);
    func(N, tmp*10+7, use|0b100, counter);
}

// use = 000
// use|0b001 -> use = 001
// use = 101
// use|0b110 -> use = 111

int main() {
    ll N;
    cin >> N;
    ll counter = 0;
    func(N, 0, 0, counter);
    cout << counter << endl;
}