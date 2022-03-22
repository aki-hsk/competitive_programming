#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll mod = 1000000000+7;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

string s, t;

bool match(int k) {
    for(int i=0; i<t.size(); i++) {
        if((t[i] != s[i+k]) && (s[i+k] != '?')) {
            return false;
        }
    }
    return true;
}

string construct(int k) {
    string ans = s;
    for(int i=0; i<t.size(); i++) {
        ans[i+k] = t[i];
    }
    for(int i=0; i<ans.size(); i++) {
        if(ans[i] == '?') ans[i] = 'a';
    }
    return ans;
}

int main(){
    cin >> s >> t;
    bool flg = false;
    int start;
    for(int i=s.size()-t.size(); i>=0; i--) {
        if(match(i)) {
            flg = true;
            start = i;
            break;
        }
    }

    if(flg) cout << construct(start) << endl;
    else cout << "UNRESTORABLE" << endl;
}