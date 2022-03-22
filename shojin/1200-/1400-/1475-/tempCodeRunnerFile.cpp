#include<iostream>
#include<vector>
using namespace std;
const long long INF = (1LL<<60);

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    vector<int> c(n);
    for(int i=0; i<n; i++) {
        cin >> p[i];
        p[i]--;
    }
    for(int i=0; i<n; i++) cin >> c[i];

    long long ans = -INF;
    for(int si=0; si<n; si++) {
        int x = si;
        vector<int> s;
        long long tog;
        while(true) {
            x = p[x];
            s.push_back(c[x]);
            tot += c[x];
            if(x == si) break;
        }
        int l = s.size();
        long long now = 0;
        for(int i=0; i<l; i++) {
            now += s[i];
            if(i+1 > k) break;
            if(tot > 0) {
                long long e = (k-i-1) % l;
                now += tot * e;
            }
            ans = max(ans, now);
        }
    }
    return 0;
}