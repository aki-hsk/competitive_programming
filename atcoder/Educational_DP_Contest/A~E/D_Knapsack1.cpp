#include<iostream>
#include<vector>
using namespace std;

// dp[ i ][ sum_w ] := i-1 番目までの品物から重さが sum_w を超えないように選んだときの、価値の総和の最大値
long long dp[110][100005] = {};
void chmax(long long &a, long long b) {
    if(a < b) a = b;
}

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    for(int i=0; i<n; i++) cin >> w[i] >> v[i];

    for(int i=0; i<n; i++) {
        for(int sum_w = 0; sum_w <= W; sum_w++) {
            // i番目の商品を選ぶ
            if(sum_w - w[i] >= 0) {
                chmax(dp[i+1][sum_w], dp[i][sum_w - w[i]] + v[i]);
            }
            // i番目の品物を選ばない
            chmax(dp[i+1][sum_w], dp[i][sum_w]);
        }
    }
    cout << dp[n][W] << endl;
}