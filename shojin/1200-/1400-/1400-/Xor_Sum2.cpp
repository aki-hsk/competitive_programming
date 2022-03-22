#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    long long res = 0;
    int right = 0, sum = 0;

    // 和は広義単調増加 SUM
    // 排他的論理和は広義単調増加ではない XORSUM
    // 常に XORSUM >= SUMとなっている。
    // ある地点でSUM > XORSUMならばbreakしてしゃくとりする
    for(int left = 0; left < n; left++) {
        while(right < n && (sum ^ a[right]) == (sum + a[right])) {
            sum += a[right];
            ++right;
        }
        res += right - left;
        if(left == right) ++right;
        else sum -= a[left];
    }
    cout << res << endl;
    return 0;
}