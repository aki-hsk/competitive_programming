#include<iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)

int main() {
    int n, q;
    string s;
    cin >> n >> s >> q;
    bool sw = false;
    rep(i, q) {
        int t, a, b;
        cin >> t >> a >> b;
        a--; b--;
        if(t == 1) {
            if(sw) a = (a+n)%(n*2);
            if(sw) b = (b+n)%(n*2);
            swap(s[a], s[b]);
        }
        else sw = !sw;
    }
    if(sw) s = s.substr(n) + s.substr(0, n);
    cout << s << endl;
}