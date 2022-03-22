#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main() {
    // n:商品の数, m:割引券の数
    int n, m;
    cin >> n >> m;
    priority_queue<int> q;
    rep(i, n) {
        int a;
        cin >> a;
        q.push(a);
    }

    rep(i, m) {
        int x = q.top() / 2;
        q.pop();
        q.push(x);
    }

    ll res = 0;
    rep(i, n) {
        res += q.top();
        q.pop();
    }
    cout << res << endl;
}