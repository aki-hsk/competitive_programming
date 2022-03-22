#include<iostream>
#include<vector>
using namespace std;

// https://www.youtube.com/watch?v=igfVeTsGeYw
long long calc(long long a) {
    // 4の時に0,1,2,3,4までになるので5つの整数
    a++;
    // 10^12 <= 2^40桁くらい
    // i桁目の偶奇を調べる

    long long ans = 0;
    for(int i=0; i<50; i++) {
        // 周期を求める 0桁目: 周期2, 1桁目: 周期4
        long long loop = (1LL<<i+1);
        long long cnt = (a / loop) * (loop / 2);

        // 00000.....001111
        cnt += max(0LL, (a % loop) - (loop / 2));

        // その桁の1の数が奇数だったら足し算
        if(cnt % 2 == 1) {
            ans += 1LL << i;
        }
    }
    return ans;
}

int main() {
    long long a, b;
    cin >> a >> b;
    long long ans = calc(b) ^ calc(a-1);
    cout << ans << endl;
}