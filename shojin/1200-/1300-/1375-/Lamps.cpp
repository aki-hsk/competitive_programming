#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

void rot(vector<vector<int>>& a) {
    int h = a.size();
    int w = a[0].size();
    vector<vector<int>> pre(w, vector<int>(h));
    swap(a, pre);
    for(int i=0; i<w; i++) {
        for(int j=0; j<h; j++) {
            a[i][j] = pre[h-1-j][i];
        }
    }
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i=0; i<h; i++) cin >> s[i];
    vector<vector<int>> a(h, vector<int>(w));

    // 散らかっていないマス:1 それ以外を0に変換
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) a[i][j] = s[i][j] == '.';
    }
    int n = h*w;
    vector<mint> two(n+1, 1);
    for(int i=0; i<n; i++) two[i+1] = two[i] * 2;

    int k = 0;
    for(int i=0; i<h; i++) for(int j=0; j<w; j++) k += a[i][j];

    // 最終的にksに見えるマスの個数を入れる
    vector<vector<int>> ks = a;
    // 4回回転する
    for(int ri=0; ri<4; ri++) {
        // 一方向分の見える個数
        vector<vector<int>> d(h, vector<int>(w));
        for(int i=0; i<h; i++) {
            for(int j=0; j<w-1; j++) {
                if(a[i][j]) d[i][j]++;
                else d[i][j] = 0;
                if(a[i][j+1]) ks[i][j+1] += d[i][j];
                d[i][j+1] = d[i][j];
            }
        }
        rot(a);
        rot(ks);
        swap(h, w);
    }
    mint ans = two[k] * n;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            int x = k - ks[i][j];
            ans -= two[x];
        }
    }
    cout << ans.val() << endl;
    return 0;
}