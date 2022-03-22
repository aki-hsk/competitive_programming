#include<iostream>
#include<vector>
using namespace std;
template<class T> inline bool chmax(T &a, T b) { if(a < b) {a = b; return 1;} return 0;}

// nCr 組み合わせ
// パスカルの三角形

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int x = 0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        chmax(x, a[i]);
    }
    int c = 0;
    int ans = 0;
    for(int i=0; i<n; i++) {
        if(c < min(a[i], x-a[i])) {
            c = min(a[i], x-a[i]);
            ans = a[i];
        }
    }
    cout << x << " " << ans << endl;
}