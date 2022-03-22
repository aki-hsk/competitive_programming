#include<iostream>
#include<vector>
using namespace std;

// DPテーブル（配列全体が自然にfalseで初期化)
// dp[i] := 石の個数が残りi個の局面が勝ちか負けかをbool値で表したもの
bool dp[110000];

int main() {
    // k:石の数
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    // DP
    for(int i=1; i<=k; i++) {
        for(int j=0; j<n; j++) {
            if(i-a[j]>=0) dp[i] |= !dp[i-a[j]];
        }
    }

    // 始めの石を取るときに勝ちパターンがあるか？
    if(dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;
}