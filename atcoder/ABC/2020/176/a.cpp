#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int N, X, T;
    cin >> N >> X >> T;
    int ans = ceil((double)N/X);
    cout << ans * T;
}