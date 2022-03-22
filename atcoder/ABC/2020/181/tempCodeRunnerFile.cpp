#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll mod = 1000000000+7;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    // 下3桁が8の倍数か？
    int s;
    cin >> s;
    vector<int> v;

    while(s) {
        int x = s % 10;
        v.push_back(x);
        s /= 10;
    }

    bool flg = false;
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v.size(); j++) {
            for(int k=0; k<v.size(); k++) {
                int a = v[i] * 100 + v[j] * 10 + v[k];
                int b = v[i] * 100 + v[j] + v[k] * 10;
                int c = v[i] * 10 + v[j] * 100 + v[k];
                int d = v[i] * 10 + v[j] + v[k] * 100;
                int e = v[i] + v[j] * 100 + v[k] * 10;
                int f = v[i] + v[j] * 10 + v[k] * 100;

                if(a % 8 == 0 || b % 8 == 0 || c % 8 == 0 || d % 8 == 0 || e % 8 == 0 || f % 8 == 0) {
                    flg = true;
                }
            }
        }
    }
    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
}