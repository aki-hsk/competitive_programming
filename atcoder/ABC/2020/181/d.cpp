#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll mod = 1000000000+7;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool solve(string s) {
    if(s.size() == 1) {
        if(s == "8") return true;
        return false;
    }
    if(s.size() == 2 ) {
        if(stoi(s) % 8 == 0) return true;
        swap(s[0], s[1]);
        if(stoi(s) % 8 == 0) return true;
        return false;
    }

    vector<int> cnt(10);
    for(char c:s) cnt[c-'0']++; // 入力値の数字の分布
    for(int i=112; i<=1000; i+=8) {
        int x = i;
        vector<int> nc(10);         // 3桁の8の倍数の分布
        for(int j=0; j<3; j++) {
            nc[x % 10]++;
            x /= 10;
        }
        bool ok = true;
        for(int j=0; j<10; j++) if(nc[j] > cnt[j]) ok = false;
        if(ok) return true;
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    if(solve(s)) cout << "Yes" << endl;
    else cout << "No" << endl;
}