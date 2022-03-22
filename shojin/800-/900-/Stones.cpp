#include<iostream>
#include<vector>
using namespace std;
template<class T> inline bool chmin(T &a, T b) {if(a > b) {a = b; return 0;} return 1;}

int main() {
    int n;
    string s;
    cin >> n >> s;
    int w = 0, b = 0;
    for(int i=0; i<n; i++) if(s[i] == '.') w++;

    int ans = b + w;
    for(int i=0; i<n; i++) {
        if(s[i] == '#') b++;
        else w--;
        chmin(ans, b+w);
    }
    cout << ans << endl;
}