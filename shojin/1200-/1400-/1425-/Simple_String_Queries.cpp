#include<iostream>
#include<vector>
#include<atcoder/fenwicktree>
using namespace std;
using namespace atcoder;

int main() {
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<fenwick_tree<int>> vf(26, fenwick_tree<int>(n+2));
    for(int i=0; i<n; i++) {
        int m = s[i]-'a';
        vf[m].add(i, 1);
    }
    for(int i=0; i<q; i++) {
        int t;
        cin >> t;
        if(t == 1) {
            int a;
            char c;
            cin >> a >> c;
            a--;
            vf[s[a]-'a'].add(a, -1);
            vf[c-'a'].add(a, 1);
            s[a] = c;
        }
        else {
            int l, r;
            cin >> l >> r;
            l--; r--;
            int cnt = 0;
            for(int j=0; j<26; j++) {
                if(vf[j].sum(l, r+1)) cnt++;
            }
            cout << cnt << endl;
        }
    }
}