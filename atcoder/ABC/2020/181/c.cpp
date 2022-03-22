#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll mod = 1000000000+7;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N;
    cin >> N;
    vector<pair<double, double>> p(N);
    for(int i=0; i<N; i++) {
        cin >> p[i].first >> p[i].second;
    }

    bool flg = false;

    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            for(int k=j+1; k<N; k++) {
                if((p[i].second)*(p[j].first - p[k].first) + p[j].second*(p[k].first-p[i].first) + p[k].second * (p[i].first - p[j].first) == 0) {
                    flg = true;
                }
            }
        }
    }
    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
}