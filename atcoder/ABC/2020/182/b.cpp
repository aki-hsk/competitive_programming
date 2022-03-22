#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll mod = 1000000000+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    int max_cnt = 0;
    int ans;

    for(int i=2; i<=1000; i++) {
        int cnt = 0;
        for(int j=0; j<N; j++) {
            if(A[j] % i == 0) cnt++;
        }
        if(cnt > max_cnt) {
            max_cnt = cnt;
            ans = i;
        }
    }
    cout << ans << endl;
}