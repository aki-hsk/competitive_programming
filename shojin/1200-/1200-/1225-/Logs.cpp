#include<iostream>
#include<vector>
using namespace std;

// 答えを二分探索
// f(x) = 一番長いものをx以下にできるか？
// -> 全部をx以下にするために切る回数がk以下

// ---------NG----|-----OK-----

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    int l = 0, r = 1e9+1;
    while(r-l > 1) {
        int m = (l+r)/2;
        // 引数がないので()を省略
        auto ok = [&]{
            long long now = 0;
            for(int i=0; i<n; i++) now += (a[i]-1)/m;
            return now <= k;
        };
        if(ok()) r = m;
        else l = m;
    }
    cout << r << endl;
    return 0;
}