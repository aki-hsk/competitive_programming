#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    string ans = "";
    while(N) {
        N--;
        ll a = N % 26;
        char c = a + 'a';
        ans = c + ans;
        N /= 26;
    }
    cout << ans << endl;
}