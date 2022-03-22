#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> D(N, 0);
    //嫌いな番号には1を入れる
    for(int i=0; i<K; i++) {
        int a;
        cin >> a;
        D[a] = 1;
    }

    for(int i=N; i<=100000; i++) {
        int tmp = i;
        bool flg = true;
        while(tmp) {
            int n = tmp % 10;
            if (D[n] == 1) {
                flg = false;
                break;
            }
            tmp /= 10;
        }

        if(flg) {
            cout << i << endl;
            return 0;
        }
    }
}