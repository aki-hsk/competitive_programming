#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

vector<long long> lunlun;

void dfs(long long n) {
    if(n > 3234566667) return;
    lunlun.push_back(n);
    int first_place = n % 10;
    int m = max(0, first_place - 1);
    int M = min(9, first_place + 1);
    for(int i=m; i<=M; i++) {
        dfs(n*10 + i);
    }
}

int main() {
    int k;
    cin >> k;
    for(int i=1; i<=9; i++) {
        dfs(i);
    }
    sort(lunlun.begin(), lunlun.end());
    cout << lunlun[k-1] << endl;
}