#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
template<class T> inline bool chmax(T &a, T b) {if(a < b) {a = b; return 1;} return 0; }

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    long long t = 0;
    vector<long long> A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) {
        cin >> B[i];
        t += B[i];
    }
    int j = M;
    int ans = 0;
    for(int i=0; i<N+1; i++) {
        while(j>0 && t > K) {
            j--;
            t -= B[j];
        }
        if(t > K) break;
        chmax(ans, i+j);
        // 次のループからは i+1冊読んでいることになっている。
        if(i != N) t += A[i];
    }
    cout << ans << endl;
}