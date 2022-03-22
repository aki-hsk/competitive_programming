#include<iostream>
#include<vector>
using namespace std;

// a%Kを決め打つと, b%k, c%kのとるべき値が一意に定まる(a+b, a+cがkの倍数)

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> num(k, 0);
    // num[x] = kで割ってk余る個数
    for(int i=1; i<=n; i++) num[i%k]++;
    long long res = 0;

    for(int a = 0; a < k; ++a) {
        int b = (k-a)%k;
        int c = (k-a)%k;
        if((b+c)%k != 0) continue;
        res += num[a] * num[b] * num[c];
    }
    cout << res << endl;
}