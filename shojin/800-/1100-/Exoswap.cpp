#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> p, ip;
// 1<i<n-1に対して必ず1回ずつswapが必要

// ip[i] pの逆行列, iが配列pで左から何番目にあるか
// left iがあるべき位置
bool solve(int left, vector<int> &res) {
    // 操作後に0~n-1になっていなければfalse
    if(res.size() == n-1) {
        for(int i=0; i<n; i++) if(p[i] != i) return false;
        return true;
    }

    // ip[left]からleftまで持ってくる
    if(ip[left] <= left) return false;

    // 各値を左端まで動かしていく
    for(int j=ip[left]; j>left; --j) {
        res.push_back(j);
        swap(p[j], p[j-1]);
    }
    for(int j=left; j<ip[left]; j++) if(p[j] != j) return false;
    return solve(ip[left], res);
}

int main() {
    cin >> n;
    p.resize(n), ip.resize(n);
    for(int i=0; i<n; i++) {
        cin >> p[i];
        --p[i];
        ip[p[i]] = i;
    }
    // p    1, 3, 0, 4, 2
    // ip   2, 0, 4, 1, 3
    vector<int> res;
    if(!solve(0, res)) cout << -1 << endl;
    else for(auto v:res) cout << v << endl;
}

