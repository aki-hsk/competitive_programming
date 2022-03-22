#include<iostream>
#include<vector>
using namespace std;

// All Green
int main() {
    long long D, G;
    cin >> D >> G;
    vector<long long> p(D), c(D);
    for(int i=0; i<D; i++) cin >> p[i] >> c[i];
    long long ans = (1LL<<60);

    // どの問題を完答するか
    for(int bit=0; bit<(1<<D); bit++) {
        long long score = 0;
        long long cnt = 0;
        for(int i=0; i<D; i++) {
            if(bit>>i&1) {
                score += (i+1) * p[i] * 100 + c[i];
                cnt += p[i];
            }
        }

        for(int i=D-1; i>=0; i--) {
            if(score >= G) break;
            if(bit>>i&1) continue;
            int s = (i+1) * 100;
            int num = min(p[i], (G-score+s-1)/s);
            score += num * s;
            cnt += num;
        }

        if(score < G) continue;
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}