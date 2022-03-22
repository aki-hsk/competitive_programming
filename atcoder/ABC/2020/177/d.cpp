#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    vector<set<int>> S(1);
    int N, M;
    cin >> N >> M;
    int a, b;
    cin >> a >> b;

    // s.find(e) != s.end()

    for(int i=0; i<M-1; i++) {
        int a, b;
        cin >> a >> b;
        if(i == 0) {
            S[0].insert(a);
            S[0].insert(b);
        }
        else {
            for(int i=0; i<S.size(); i++) {
                if(S[i].find(a) != S[i].end() || S[i].find(b) != S[i].end()) {
                    S[i].insert(a);
                    S[i].insert(b);
                }
                else {
                    set<int> s = {a, b};
                    S.push_back(s);
                }
            }
        }
    }
    int ans = 0;
    for(int i=0; i<S.size(); i++) {
        ans += S[i].size()-1;
        for(auto s:S[i]) {
            cout << s;
        }
        cout << endl;
    }
    cout << ans << endl;
}